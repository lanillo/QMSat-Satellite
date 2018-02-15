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
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5);      // Enable GPIO and Timer0 peripheral clocks

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    // Instantiate constants class
    Constants g_C;

    EFM32_GPIO PE2 = EFM32_GPIO(2, g_C.E);

    PE2.turnON();
    PE2.turnOFF();

    initTimer0();

    /* Infinite loop */
    unsigned int test = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	/*if (timer0->getElapsedTime_microsecond() > 500000)
    	{
    		stateManager->execute();
    		timer0->getReferenceTime_microsecond();
    	}*/
    }
}
