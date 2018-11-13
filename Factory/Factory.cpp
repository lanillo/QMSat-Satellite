/*
 * Factory.cpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume Beaupré
 */

#include "Factory.hpp"

/****************************************************/
Factory::Factory()
{
	m_StateManagerCreated = false;
	m_StatesCreated = false;
	m_Timer0Created = false;
	m_LED0Created = false;
	m_USART1Created = false;
	m_USART0Created = false;
	m_SPICreated = false;
	m_GPIOCreated = false;
	m_I2CCreated = false;
	m_PWMCreated = false;

	// Setup Clock Tree
	this->clockInit();
}

/****************************************************/
StateManager* Factory::createStateManager()
{
	createStates();

	if(m_StateManagerCreated == false)
	{
		m_StateManager = StateManager(&m_InitState);

		m_StateManager.addState(&m_RunState);
		m_StateManager.addState(&m_EconoState);
	}
	return &m_StateManager;
}

/****************************************************/
void Factory::createStates()
{
	createUSART1();
	createUSART0();
	createLED();
	if(m_StatesCreated == false)
	{
		m_InitState = InitState(&m_LED0, &m_EFM32_USART1);
		m_RunState = RunState(&m_EFM32_USART1, &m_UartAlim);
		m_EconoState = EconoState(&m_EFM32_USART1);

		m_StatesCreated = true;
	}
}

/****************************************************/
void Factory::createLED()
{
  if(m_LED0Created == false)
  {

  }
}

/****************************************************/
void Factory::createGPIO()
{
	if(m_GPIOCreated == false)
	{
		/***** PWM *****/
		EFM32_GPIO LED0(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0); // set LED0 (PE2) pin as push-pull output

		/***** I2C *****/
		/* MUST BE initialized after ROUTE of I2C to avoid glitches */
	    /* Output value must be set to 1 to not drive lines low. Set SCL first, to ensure it is high before changing SDA. */
	    EFM32_GPIO SCL(gpioPortC, 7, gpioModeWiredAndPullUpFilter, 1);	// PD7(I2C0) #1 - PC5(I2C1) #0 - PC7(I2C0) #1 - SCL
	    EFM32_GPIO SDA(gpioPortC, 6, gpioModeWiredAndPullUpFilter, 1);	// PD6(I2C0) #1 - PC4(I2C1) #0 - PC6(I2C0) #1 - SDA

	    /***** GPIO *****/
		m_PB0 = EFM32_GPIO(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInput, 1); // set PBO button (B9) as input
		m_PB1 = EFM32_GPIO(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, gpioModeInput, 1); // set PB1 button (B10) as input

		m_GPIOCreated = true;
	}
}

/****************************************************/
void Factory::createUSART1()
{
	if(m_USART1Created == false)
	{
		m_EFM32_USART1 = EFM32_USART1(9600, _USART_FRAME_STOPBITS_ONE, _USART_FRAME_PARITY_NONE);
		callbackUSART1Init(&EFM32_USART1::callbackForSerialTransmit, &EFM32_USART1::callbackForSerialReceive, (void*)&m_EFM32_USART1);
		m_USART1Created = true;
	}
}

/****************************************************/
void Factory::createUSART0()
{
	if(m_USART0Created == false)
	{
		m_UartAlim = EFM32_USART0(9600, _USART_FRAME_STOPBITS_ONE, _USART_FRAME_PARITY_NONE);
		callbackUSART0Init(&EFM32_USART0::callbackForSerialTransmit, &EFM32_USART0::callbackForSerialReceive, (void*)&m_UartAlim);
		m_USART0Created = true;
	}
}

/****************************************************/
void Factory::createSPI()
{
	if(m_SPICreated == false)
	{
		m_EFM32_SPI = EFM32_SPI(9600, true);
	}
}

/****************************************************/
EFM32_Timer0* Factory::createTimer0()
{
	if(m_Timer0Created == false)
	{
		m_Timer0 = EFM32_Timer0(TIME_100_MICROSECONDS);
		m_Timer0Created = true;
	}
	return &m_Timer0;
}

/****************************************************/
void Factory::createI2C()
{
	if(m_I2CCreated == false)
	{
		m_I2C = EFM32_I2C();
		m_I2CCreated = true;
	}
}

/****************************************************/
void Factory::createPWM()
{
	if(m_PWMCreated == false)
	{
		m_PWM = EFM32_PWM(PWM_DUTY_CYCLE);
		m_PWMCreated = true;
	}
}

/****************************************************/
void Factory::initEFM32Functionnality()
{
	initTimer0();
	initSPI();
	initUSART1();
	initUSART0();
	initI2C();
}

/****************************************************/
void Factory::clockInit()
{
	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);			// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   	// Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); 	// Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       // Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);		// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_USART0, true);		// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER0, true);		// Enable Timer_0 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER3, true);		// Enable Timer_3 peripheral clock
    CMU_ClockEnable(cmuClock_I2C0, true);		// Enable I2C0 peripheral clock
}
