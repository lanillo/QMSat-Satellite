/*
 * RunState.cpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief InitState Class Definition
 */

#include "InitState.hpp"
#include "efm32gg990f1024.h"

/****************************************************/
InitState::InitState()
{
	m_stateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED, ISerialComm* p_UartUI, AlimManager* p_AlimManager)
{
	m_LED = p_LED;
	m_UartUI = p_UartUI;
	m_stateId = Init;
	m_AlimManager = p_AlimManager;

	m_SwitchValue[0] = 'S';
	m_SwitchValue[2] = '\n';
}

/****************************************************/
short InitState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void InitState::onEntry()
{
	m_UartUI->sendSerial("Initiation of QMSat Sattelite\n",30);
}

/****************************************************/
short InitState::execute()
{
	m_SwitchValue[1] = m_AlimManager->getSwitchState();
	m_UartUI->sendSerial(m_SwitchValue,3);

	return Run;
}

/****************************************************/
void InitState::onExit()
{

}
