/*
 * StateManager.cpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume
 */


#include "StateManager.hpp"


StateManager::StateManager()
{
	m_StatesIndex = 0;
	m_CurrentState =  0;
	m_CurrentStateId = 0;
	m_NextStateId = 0;
}

/****************************************************/
StateManager::StateManager(IState* p_State)
{
	m_StatesIndex = 0;
	m_CurrentState =  p_State;
	m_CurrentStateId = -1;
	m_NextStateId = p_State->getStateId();
	addState(p_State);
}

/****************************************************/
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
void StateManager::addState(IState* p_State)
{
	m_States[m_StatesIndex] = p_State;
	m_StatesIndex++;
}

/****************************************************/
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
