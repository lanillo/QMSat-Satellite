#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_chip.h"
#include "bspconfig.h"
#include "efm32gg990f1024.h"

#include <stdio.h>

#include "Factory.hpp"
#include "Constants.hpp"

#include "EFM32_GPIO.hpp"

int main(void)
{
	/* Chip errata */
	CMU->HFRCOCTRL = 0x8;                         // Set High Freq. RC Osc. to 1 MHz
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5);      // Enable GPIO and Timer0 peripheral clocks

    /* Initialize chip */
    //CHIP_Init();

    /* Enable clock for GPIO module */
    //CMU_ClockEnable(cmuClock_GPIO, true);

    /* Configure PB0 pin as an input for PB0 button */
    EFM32_GPIO B9(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN, gpioModeInput, 0);

    /* Configure LED0 as a push pull for LED drive */
    EFM32_GPIO E2(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPullDrive, 1);

    EFM32_GPIO PA12(gpioPortD, 14, gpioModePushPull, 1);
    PA12.setGPIOPortDriveMode(gpioDriveModeLowest);

    while (1)
      {
    	if (!B9.readInput())
		{
		  /* Configure LED Port with alternate drive strength of 0.5mA */
    		E2.setOutputHigh();
    		PA12.setOutputHigh();
		}
		else
		{
		  /* Configure LED Port with standard drive strength of 6mA */
			E2.setOutputLow();
			PA12.setOutputLow();
		}
      }

}
