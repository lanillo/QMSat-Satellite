
#define DEBUG_BREAK           __asm__("BKPT #0"); //For debug

// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_usart.h"
// [Library includes]$

#include <string.h>

#include "bspconfig.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

#include "EFM32_GPIO.hpp"

#define COM_PORT gpioPortD // USART location #1: PD0 and PD1
#define UART_TX_pin 0      // PD0
#define UART_RX_pin 1      // PD1

#define   I2C_PORT     2     // gpioPortC
#define   I2C_SDA      4     // PC4
#define   I2C_SCLK     5     // PC5
#define   I2C_WP       3     // PC3 - Write protect pin for EEPROM IC
#define   UART_PORT    3     // gpioPortD (USART location #1: PD0 and PD1)
#define   UART_TX      0     // UART TX: PD0
#define   LED_PORT     1     // gpioPortB
#define   LED_PIN0     11    // LED0: PB11
#define   LED_PIN1     12    // LED1: PB12
#define   BLOCK_SIZE   256   // 256 bytes per block
#define   PAGE_SIZE    16    // 16 bytes per page

// Functions involving direct I2C communication with EEPROM
uint8_t read_byte(uint8_t memory_block, uint8_t address, uint8_t* response);
uint8_t write_byte(uint8_t memory_block, uint8_t address, uint8_t data);
uint8_t read_block(uint8_t memory_block, uint8_t buffer[], uint16_t buffer_size);
uint8_t write_page(uint8_t memory_block, uint8_t page_num, uint8_t data[], uint8_t page_size);
uint8_t chip_is_busy(void);

// Higher level functions that implement the I2C functions above
void display_block(uint8_t memory_block);
void block_erase(uint8_t memory_block);
void check_error_status(uint8_t status);

// Functions involving UART communication with terminal (PC) program
void print_byte(uint8_t byte);
void print_byte_setup(uint8_t byte);

// Global variable
uint8_t print_byte_array[4] = { 0x30, 0x78, 0x20, 0x20 }; // array for displaying bytes one nibble at a time

// Error strings
char error_message1[] = "Error - unsupported block number\n\r";
char error_message2[] = "Error - buffer/array size unacceptable\n\r";
char error_message3[] = "Error - unsupported page number\n\r";
char error_message4[] = "Error - transmitted/received NACK, expected ACK\n\r";
char error_message5[] = "Error - unkown cause of error\n\r";

int main(void)
{
    /* Initialize chip */
	/* Chip errata */
	CHIP_Init();

	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);	// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   // Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); // Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       // Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);		// Enable USART1 peripheral clock
    //CMU_ClockEnable(cmuClock_TIMER0, true);		// Enable Timer_0 peripheral clock
    //CMU_ClockEnable(cmuClock_I2C1, true);		// Enable I2C1 peripheral clock

    /* Configure PB0 pin as an input for PB0 button */
	EFM32_GPIO B9_PB0(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN, gpioModeInputPull, 1);

	/* Configure LED0 as a push pull for LED drive */
	EFM32_GPIO E2_LED0(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);


	uint8_t i;
	char test_string[] = "\n\rHello World!\n\r";     // Test string
	char rx_char = 0;                                // Temp variable for storing received characters

	GPIO_PinModeSet(gpioPortD, 0, gpioModePushPull, 1); // Configure UART TX pin as digital output, initialize high since UART TX idles high (otherwise glitches can occur)
	GPIO_PinModeSet(gpioPortD, 1, gpioModeInput, 0);    // Configure UART RX pin as input (no filter)

	USART_InitAsync_TypeDef uartInit =
	{
		uartInit.enable       = usartDisable,   // Wait to enable the transmitter and receiver
		uartInit.refFreq      = 0,              // Setting refFreq to 0 will invoke the CMU_ClockFreqGet() function and measure the HFPER clock
		uartInit.baudrate     = 38400,          // Desired baud rate
		uartInit.oversampling = usartOVS16,     // Set oversampling value to x16
		uartInit.databits     = usartDatabits8, // 8 data bits
		uartInit.parity       = usartNoParity,  // No parity bits
		uartInit.stopbits     = usartStopbits1, // 1 stop bit
		uartInit.mvdis        = false,          // Use majority voting
		uartInit.prsRxEnable  = false,          // Not using PRS input
		uartInit.prsRxCh      = usartPrsRxCh0,  // Doesn't matter which channel we select
	};

	USART_InitAsync(USART1, &uartInit);			// Apply configuration struct to USART1
	USART1->ROUTE = UART_ROUTE_RXPEN | UART_ROUTE_TXPEN | _UART_ROUTE_LOCATION_LOC1; // Clear RX/TX buffers and shift regs, enable transmitter and receiver pins

	USART_IntClear(USART1, _UART_IF_MASK); // Clear any USART interrupt flags
	NVIC_ClearPendingIRQ(UART1_RX_IRQn);   // Clear pending RX interrupt flag in NVIC
	NVIC_ClearPendingIRQ(UART1_TX_IRQn);   // Clear pending TX interrupt flag in NVIC

	USART_Enable(USART1, usartEnable);     // Enable transmitter and receiver

	// Print test string
	for(i=0; i<strlen(test_string); i++)
	{
		while( !(USART1->STATUS & (1 << 6)) ); // wait for TX buffer to empty
		USART1->TXDATA = 'a';       // print each character of the test string
	}

    while (1)
    {
    	if(!B9_PB0.readInput())
    	{
    		E2_LED0.setOutputHigh();
    		USART1->TXDATA = 'a';
    	} else
    	{
    		E2_LED0.setOutputLow();
    	}

		if(USART1->STATUS & (1 << 7))
		{
			// if RX buffer contains valid data
			rx_char = USART1->RXDATA;       // store the data
		}

		if(rx_char)
		{
			// if we have a valid character
			if(USART1->STATUS & (1 << 6))
			{
				// check if TX buffer is empty
				USART1->TXDATA = 'a';	// echo received char
				rx_char = 0;			// reset temp variable
			}
		}
    }
}
