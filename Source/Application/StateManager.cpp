/*
 * StateManager.cpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume Beaupré
 */


#include "StateManager.hpp"

/****************************************************/
/**
* \brief By default Object constructor for the INIT State
* \return None
*/
StateManager::StateManager()
{
	m_StatesIndex = 0;
	m_CurrentState =  0;
	m_CurrentStateId = 0;
	m_NextStateId = 0;
}

/****************************************************/
/**
* \brief Object constructor for the INIT State
* \param[in] p_State 	:  The first state that will be executed
* \return None
*/
StateManager::StateManager(IState* p_State)
{
	m_StatesIndex = 0;
	m_CurrentState =  p_State;
	m_CurrentStateId = -1;
	m_NextStateId = p_State->getStateId();
	addState(p_State);
}

/****************************************************/
/**
* \brief Execute the next state depending on the next ID given by the execution of the current state
* \return None
*/
void StateManager::execute()
{
	if(m_CurrentStateId != m_NextStateId)
	{
        m_CurrentState->onEntry();
        m_CurrentStateId = m_CurrentState->getStateId();
	}
	else
	{
		m_NextStateId = m_CurrentState->execute();
	}
	if(m_CurrentStateId != m_NextStateId)
	{
		m_CurrentState->onExit();
		m_CurrentState = getNextState();
	}
}

/****************************************************/
/**
* \brief  Add a state to the state machine (only the state added that way are accessible for the StateManager)
* \return None
*/
void StateManager::addState(IState* p_State)
{
	m_States[m_StatesIndex] = p_State;
	m_StatesIndex++;
}

/****************************************************/
/**
* \brief  Check the list of States to find the one with the Next state ID
* \return Pointer to the next state to be executed
*/
IState* StateManager::getNextState()
{
	for(unsigned short index = 0; index < m_StatesIndex; index++)
	{
		if(m_States[index]->getStateId() == m_NextStateId)
		{
			return m_States[index];
		}
	}
	return m_States[m_CurrentStateId];
}
