#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

#include "EFM32_GPIO.hpp"

int main(void)
{
	/* Chip errata */

	CMU->HFRCOCTRL = 0x8;                         // Set High Freq. RC Osc. to 1 MHz
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5) | (1 << 1);      // Enable GPIO and Timer0 peripheral clocks
    CMU->CTRL |= (1 << 14);                         // Set HF clock divider to /2 to keep core frequency <32MHz
	CMU->OSCENCMD |= 0x4;                           // Enable XTAL Oscillator
	while(! (CMU->STATUS & 0x8) );                  // Wait for XTAL osc to stabilize
	CMU->CMD = 0x2;

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    initTimer0();
    timer0->start();

    /* Infinite loop */
    unsigned int test;
    test = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	if (timer0->getElapsedTime_microsecond(test) > TIME_500_MILLISECONDS)
    	{
    		stateManager->execute();
    		test = timer0->getReferenceTime_microsecond();
    	}
    }
}
