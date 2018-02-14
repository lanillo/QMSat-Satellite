#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

<<<<<<< HEAD
int main(void)
{
	/* Chip errata */

	CMU->HFRCOCTRL = 0x8;                         // Set High Freq. RC Osc. to 1 MHz
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5);      // Enable GPIO and Timer0 peripheral clocks

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    initTimer0();
    timer0->start();

    /* Infinite loop */
    while (true)
    {
    	stateManager->execute();
    }
=======
#include "EFM32_GPIO.hpp"

#define LED_PORT E
#define BUTTON_PORT B
#define LED0 2
#define LED1 3

int main(void)
{
	// Chip errata
	CHIP_Init();

	// Enable main clock
	CMU->HFPERCLKEN0 = (1 << 13);

	// Instantiate constants class
	Constants C;

	Factory factory = Factory();
	StateManager* stateManager = factory.createStateManager();

	EFM32_GPIO E2 = EFM32_GPIO(2, C.E);
	EFM32_GPIO E2 = EFM32_GPIO(3, C.E);

	/* Infinite loop */
	while (true)
	{
	  stateManager->execute();
	}
>>>>>>> GPIO
}
