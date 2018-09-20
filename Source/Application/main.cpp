
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



int main(void)
{
    /* Initialize chip */
	CHIP_Init();

	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);			// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   	// Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); 	// Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       	// Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);		// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER0, true);		// Enable Timer_0 peripheral clock
    //CMU_ClockEnable(cmuClock_I2C1, true);			// Enable I2C1 peripheral clock

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    /*Initializations*/
    initTimer0();
    initUSART1();

    timer0->start();

    /* Infinite loop */
    static unsigned int referenceTime_microsecond;
    referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	if (timer0->getElapsedTime_microsecond(referenceTime_microsecond) >= TIME_3_SECOND)
    	{
    		stateManager->execute();
    		referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    	}
    }
}
