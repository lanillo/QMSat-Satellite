#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include <stdio.h>

#include "Factory.hpp"
#include "Constants.hpp"

int main(void)
{
	/* Chip errata */
	CMU->HFRCOCTRL = 0x8;                         // Set High Freq. RC Osc. to 1 MHz
    CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5);      // Enable GPIO and Timer0 peripheral clocks

    EFM32_GPIO SDA_PC4 = EFM32_GPIO(4, C, false, OPENSOURCE);
    EFM32_GPIO SCL_PC5 = EFM32_GPIO(5, C, false, OPENSOURCE);

    SDA_PC4.setOutputLow();
    SDA_PC4.setOutputHigh();
    SDA_PC4.setOutputLow();
    SDA_PC4.setOutputHigh();

    SCL_PC5.setOutputLow();
    SCL_PC5.setOutputHigh();
    SCL_PC5.setOutputLow();
    SCL_PC5.setOutputHigh();

    EFM32_I2C I2CT = EFM32_I2C(SDA_PC4, SCL_PC5, ACCELEROMETER_ADDRESS);

    I2CT.ReadData();

}
