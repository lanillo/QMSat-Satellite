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
}

/****************************************************/
EconoState::EconoState(ISerialComm* p_USART)
{
	m_USART = p_USART;
	m_stateId = Econo;
}

/****************************************************/
short EconoState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void EconoState::onEntry()
{

}

/****************************************************/
short EconoState::execute()
{
	return m_stateId;
}

/****************************************************/
void EconoState::onExit()
{

}
