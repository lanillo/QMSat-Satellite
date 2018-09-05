/*
 * RunState.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#include "RunState.hpp"

/****************************************************/
RunState::RunState()
{
	m_stateId = Run;
}

/****************************************************/
RunState::RunState(ISerialComm* p_USART)
{
	m_stateId = Run;

	m_USART = p_USART;
}

/****************************************************/
short RunState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void RunState::onEntry()
{
	m_USART->sendSerial("Entering Run State\n\r",20);
}

/****************************************************/
short RunState::execute()
{
	m_USART->sendSerial("Executing Run State\n\r",21);
	return Init;
}

/****************************************************/
void RunState::onExit()
{

}


