/*
 * EconoState.cpp
 *
 *  Created on: 2018-10-22
 *      Author: Guillaume Beaupré
 */

#include "EconoState.hpp"

/****************************************************/
EconoState::EconoState()
{
	m_stateId = Econo;

	m_ADCValue[0] = 'B';
	m_ADCValue[2] = '\n';
}

/****************************************************/
EconoState::EconoState(ISerialComm* p_UartUI, AlimManager* p_AlimManager)
{
	m_UartUI = p_UartUI;
	m_AlimManager = p_AlimManager;
	m_stateId = Econo;

	m_ADCValue[0] = 'B';
	m_ADCValue[2] = '\n';
}

/****************************************************/
short EconoState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void EconoState::onEntry()
{
	m_UartUI->sendSerial("Low Power State\n",16);
}

/****************************************************/
short EconoState::execute()
{

	m_ADCValue[1] = m_AlimManager->getBatterieVoltage();
	m_UartUI->sendSerial(m_ADCValue,3);
	if(m_AlimManager->getBatterieVoltage() > 5)
	{
		return Run;
	}

	return Econo;
}

/****************************************************/
void EconoState::onExit()
{

}
