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
	m_USART1Created = false;
}

/****************************************************/
StateManager* Factory::createStateManager()
{
	createStates();

	if(m_StateManagerCreated == false)
	{
		m_StateManager = StateManager(&m_InitState);

		//m_StateManager.addState(&m_RunState);
	}
	return &m_StateManager;
}

/****************************************************/
void Factory::createStates()
{
	createUSART1();
	createLED();
	if(m_StatesCreated == false)
	{
		m_InitState = InitState(&m_LED0, &m_EFM32_USART1);
		m_RunState = RunState();

		m_StatesCreated = true;
	}
}

/****************************************************/
void Factory::createLED()
{
	if(m_LED0Created == false)
	{
		m_GPIO_LED0 = EFM32_GPIO(2,4);
		m_LED0 = LED(&m_GPIO_LED0);

		m_LED0Created = true;
	}
}

/****************************************************/
void Factory::createUSART1()
{
	if(m_USART1Created == false)
	{
		m_EFM32_USART1 = EFM32_USART1(57600, _USART_FRAME_STOPBITS_ONE, _USART_FRAME_PARITY_NONE);
		callbackUSART1Init(&EFM32_USART1::callbackForSerialTransmit, &EFM32_USART1::callbackForSerialReceive, (void*)&m_EFM32_USART1);
		m_USART1Created = true;
	}
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
