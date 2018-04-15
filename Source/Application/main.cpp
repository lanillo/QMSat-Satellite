#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

int main(void)
{
	/* Chip errata */
	CMU->HFRCOCTRL = 0x8;                         // Set High Freq. RC Osc. to 1 MHz
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5);      // Enable GPIO and Timer0 peripheral clocks

    EFM32_GPIO PE2 = EFM32_GPIO(2, E, false, OPENSOURCE);
    EFM32_GPIO PE3 = EFM32_GPIO(3, E, false, OPENSOURCE);

    int cpt = 0;

    PE2.setOutputHigh();
    if (PE2.readInput())
    {
    	cpt++;
    }
    PE2.setOutputLow();
    if (PE2.readInput())
	{
		cpt++;
	}
    PE3.setOutputHigh();
    if (PE3.readInput())
	{
		cpt++;
	}
    PE3.setOutputLow();
    if (PE3.readInput())
	{
		cpt++;
	}

}
