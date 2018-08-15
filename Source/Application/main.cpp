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

    EFM32_GPIO PE0 = EFM32_GPIO(0, E, false, OPENSOURCE);
    EFM32_GPIO PE1 = EFM32_GPIO(1, E, false, OPENSOURCE);
    EFM32_GPIO PE2 = EFM32_GPIO(2, E, false, OPENSOURCE);
    EFM32_GPIO PE3 = EFM32_GPIO(3, E, false, OPENSOURCE);
    EFM32_GPIO PE4 = EFM32_GPIO(4, E, false, OPENSOURCE);
    EFM32_GPIO PE5 = EFM32_GPIO(5, E, false, OPENSOURCE);
    EFM32_GPIO PE6 = EFM32_GPIO(6, E, false, OPENSOURCE);
    EFM32_GPIO PE7 = EFM32_GPIO(7, E, false, OPENSOURCE);
    EFM32_GPIO PE8 = EFM32_GPIO(8, E, false, OPENSOURCE);
    EFM32_GPIO PE9 = EFM32_GPIO(9, E, false, OPENSOURCE);
    EFM32_GPIO PE10 = EFM32_GPIO(10, E, false, OPENSOURCE);
    EFM32_GPIO PE11 = EFM32_GPIO(11, E, false, OPENSOURCE);
    EFM32_GPIO PE12 = EFM32_GPIO(12, E, false, OPENSOURCE);
    EFM32_GPIO PE13 = EFM32_GPIO(13, E, false, OPENSOURCE);
    EFM32_GPIO PE14 = EFM32_GPIO(14, E, false, OPENSOURCE);
    EFM32_GPIO PE15 = EFM32_GPIO(15, E, false, OPENSOURCE);

    PE0.setOutputHigh();
    PE1.setOutputHigh();
    PE2.setOutputHigh();
    PE3.setOutputHigh();
    PE4.setOutputHigh();
    PE5.setOutputHigh();
    PE6.setOutputHigh();
    PE7.setOutputHigh();
    PE8.setOutputHigh();
    PE9.setOutputHigh();
    PE10.setOutputHigh();
    PE11.setOutputHigh();
    PE12.setOutputHigh();
    PE13.setOutputHigh();
    PE14.setOutputHigh();
    PE15.setOutputHigh();



/*
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
*/
}
