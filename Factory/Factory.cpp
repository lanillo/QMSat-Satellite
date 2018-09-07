/*
 * Factory.cpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume
 */

#include "Factory.hpp"
#include "Constants.hpp"

/****************************************************/
Factory::Factory()
{
	m_StateManagerCreated = false;
	m_StatesCreated = false;
	m_Timer0Created = false;
	m_LED0Created = false;
	m_GPIOCreated = false;
	m_I2CCreated = false;
}

/****************************************************/
StateManager* Factory::createStateManager()
{
	createStates();

	if(m_StateManagerCreated == false)
	{
		m_StateManager = StateManager(&m_InitState);

		m_StateManager.addState(&m_RunState);
	}
	return &m_StateManager;
}

/****************************************************/
void Factory::createStates()
{
	if(m_StatesCreated == false)
	{
		m_InitState = InitState();
		m_RunState = RunState();

		m_StatesCreated = true;
	}
}

/****************************************************/
void Factory::createLED()
{
	/*
	if(m_LED0Created == false)
	{
		m_GPIO_LED0  = EFM32_GPIO(gpioPortC, 4, gpioDriveModeStandard, false);
		m_LED0 = LED(&m_GPIO_LED0);

		m_LED0Created = true;
	}
	*/
}

/****************************************************/
EFM32_GPIO* Factory::createGPIO()
{
	/*
	if(m_GPIOCreated == false)
	{
		m_GPIO_LED0  = EFM32_GPIO(gpioPortC, 4, gpioDriveModeStandard, false);
		m_Timer0Created = true;
	}
	return &m_GPIO;
	*/
}

/****************************************************/
EFM32_Timer0* Factory::createTimer0()
{
	if(m_Timer0Created == false)
	{
		m_Timer0 = EFM32_Timer0(10);
		callbackTimer0Init(&EFM32_Timer0::callbackForTimer0Increment, (void*)&m_Timer0);
		m_Timer0Created = true;
	}
	return &m_Timer0;
}

/****************************************************/
EFM32_I2C* Factory::createI2C0()
{
	if(m_I2CCreated == false)
	{
		m_I2C = EFM32_I2C(m_GPIO, m_GPIO, 10);
		m_I2CCreated = true;
	}
	return &m_I2C;
}
