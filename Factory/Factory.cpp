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
	m_SPICreated = false;
	m_GPIOCreated = false;
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
	createUSART1();
	createLED();
	if(m_StatesCreated == false)
	{
		m_InitState = InitState(&m_LED0, &m_EFM32_USART1);
		m_RunState = RunState(&m_EFM32_USART1);

		m_StatesCreated = true;
	}
}

/****************************************************/
void Factory::createLED()
{
  if(m_LEDCreated == false)
  {
  
  }
}

/****************************************************/
EFM32_GPIO* Factory::createGPIO()
{
	if(m_GPIOCreated == false)
	{

	}

	return &m_GPIO;
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
void Factory::createSPI()
{
	if(m_SPICreated == false)
	{
		m_EFM32_SPI = EFM32_SPI();
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
