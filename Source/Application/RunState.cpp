/*
 * RunState.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume Beaupré
 */

#include "RunState.hpp"
#include "Constants.hpp"

/****************************************************/
RunState::RunState()
{
	m_stateId = Run;
}

/****************************************************/
RunState::RunState(ISerialComm* p_USART_UI, ITempSensor* p_I2C_MCP)
{
	m_stateId = Run;
	m_I2C_MCP = p_I2C_MCP;
	m_USART_UI = p_USART_UI;
}

/****************************************************/
short RunState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void RunState::onEntry()
{
	m_USART_UI->sendSerial("Entering Run State\n",19);

	// Start I2C and get ambient temperature (Ta)
	m_I2C_MCP->getTemp();

	// Create char* for UI with Ta
	char* temperatureString = m_I2C_MCP->tempToString();
	m_USART_UI->sendSerial(temperatureString,6);
}

/****************************************************/
short RunState::execute()
{
	m_USART_UI->sendSerial("Executing Run State\n",20);

	return Init;
}

/****************************************************/
void RunState::onExit()
{

}


