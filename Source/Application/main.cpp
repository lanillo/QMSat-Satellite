#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

#include "EFM32_GPIO.hpp"

int main(void)
{
	/* Chip errata */
	CMU->HFRCOCTRL |= CMU_HFRCOCTRL_BAND_1MHZ; // Set High Freq. RC Osc. to 1 MHz
    CMU->CTRL |= (1 << _CMU_CTRL_HFCLKDIV_SHIFT); // Set HF clock divider to /2 to keep core frequency <32MHz
	CMU->OSCENCMD |= 0x4; // Enable XTAL Oscillator
	while(! (CMU->STATUS & 0x8) ); // Wait for XTAL osc to stabilize
	CMU->CMD = 0x2;

	CMU->HFPERCLKEN0 = (1 << _CMU_HFPERCLKEN0_GPIO_SHIFT) | (1 << _CMU_HFPERCLKEN0_TIMER0_SHIFT) | (1 << _CMU_HFPERCLKEN0_USART1_SHIFT);

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    /*Initialisations*/
    initTimer0();
    initUSART1();

    //timer0->start();

    /* Infinite loop */
    unsigned int referenceTime_microsecond;
    referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	if (timer0->getElapsedTime_microsecond(referenceTime_microsecond) > TIME_500_MILLISECONDS)
    	{
    		stateManager->execute();
    		referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    	}
    	stateManager->execute();
    }
}
