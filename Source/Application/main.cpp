
// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_usart.h"
#include "em_timer.h"
#include "i2cspmconfig.h"
// [Library includes]$

#include <string.h>

#include "bspconfig.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"
#include "Constants.hpp"

#include "EFM32_GPIO.hpp"
#include "EFM32_PWM.hpp"

int duty_cycle_pwm = 10;
bool going_up = true;

int main(void)
{
    /* Initialize chip */
	CHIP_Init();

	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);			// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   	// Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); 	// Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       // Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);		// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER0, true);		// Enable Timer_0 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER3, true);		// Enable Timer_3 peripheral clock
    CMU_ClockEnable(cmuClock_I2C0, true);		// Enable I2C0 peripheral clock
    //CMU_ClockEnable(cmuClock_I2C1, true);		// Enable I2C0 peripheral clock

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();

    /* Initializations */
    initTimer0();
    initUSART1();

    /* Output value must be set to 1 to not drive lines low. Set
	SCL first, to ensure it is high before changing SDA. */
    //EFM32_GPIO SCL(gpioPortD, 7, gpioModePushPull, 1);	// PD7(I2C0) - PC5(I2C1) - SCL
    //EFM32_GPIO SDA(gpioPortC, 6, gpioModePushPull, 1);	// PD6(I2C0) - PC4(I2C1) - SDA

    EFM32_GPIO LED0(gpioPortE, 2, gpioModePushPull, 0); // set LED0 pin as push-pull output
    EFM32_GPIO LED1(gpioPortE, 3, gpioModePushPull, 1); // set LED1 pin as push-pull output

    EFM32_PWM PWM1(duty_cycle_pwm);

    timer0->start();

    /* Infinite loop */
    static unsigned int referenceTime_microsecond;
    referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	if (timer0->getElapsedTime_microsecond(referenceTime_microsecond) >= TIME_1_SECOND)
    	{
    		if (going_up)
    		{
    			if(PWM1.getDutyCycle() >= 0 && PWM1.getDutyCycle() <= 90)
    			{
    				PWM1.augmentDutyCycleBy(10);
    			}

    			if(PWM1.getDutyCycle() >= 100)
				{
					going_up = false;
				}
    		} else
    		{
				if(PWM1.getDutyCycle() >= 10 && PWM1.getDutyCycle() <= 100)
				{
					PWM1.reduceDutyCycleBy(10);
				}

				if(PWM1.getDutyCycle() <= 0)
				{
					going_up = true;
				}
    		}

    		stateManager->execute();
    		referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    	}
    }
}
