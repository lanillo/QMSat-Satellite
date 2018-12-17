/*
 * EconoState.cpp
 *
 *  Created on: October 22, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief EconoState Class Definition
 */

#include "EconoState.hpp"

/****************************************************/
/**
* \brief By default Object constructor for the ECONO State
* \return None
*/
EconoState::EconoState()
{
	m_stateId = Econo;

	m_ADCValue[0] = 'B';
	m_ADCValue[2] = '\n';
}

/****************************************************/
/**
* \brief Object constructor for the ECONO State
* \param[in] p_UartUI 	:  Pointer to the USART1 Object
* \param[in] p_AlimManager 	:  Pointer to the AlimManager Object
* \return None
*/
EconoState::EconoState(ISerialComm* p_UartUI, AlimManager* p_AlimManager)
{
	m_UartUI = p_UartUI;
	m_AlimManager = p_AlimManager;
	m_stateId = Econo;

	m_ADCValue[0] = 'B';
	m_ADCValue[2] = '\n';
}

/****************************************************/
/**
* \brief Return the unique identifier of the state
* \return 2 for the ECONO state
*/
short EconoState::getStateId()
{
	return m_stateId;
}

/****************************************************/
/**
* \brief Execute the initial action when entering the state
* \return None
*/
void EconoState::onEntry()
{
	m_UartUI->sendSerial("Low Power State\n",16);
}

/****************************************************/
/**
* \brief Execute the normal set of actions for this state
* \return ID of the next state to be execute
*/
short EconoState::execute()
{

	m_ADCValue[1] = m_AlimManager->getBatteryVoltage();
	m_UartUI->sendSerial(m_ADCValue,3);
	if(m_AlimManager->getBatteryVoltage() > 5)
	{
		return Run;
	}

	return Econo;
}

/****************************************************/
/**
* \brief Execute the initial action when exiting the state
* \return None
*/
void EconoState::onExit()
{

}
