/*
 * Factory.hpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume
 */

#ifndef FACTORY_FACTORY_HPP_
#define FACTORY_FACTORY_HPP_

#include "StateManager.hpp"
#include "InitState.hpp"
#include "RunState.hpp"

#include "EFM32_Timer0.hpp"

class Factory
{
private:
	/**** StateManager ****/
	bool m_StateManagerCreated;
	StateManager m_StateManager;

	/**** States ****/
	bool m_StatesCreated;
	InitState m_InitState;
	RunState m_RunState;
	void createStates();

	/**** Timer0 ****/
	EFM32_Timer0 m_Timer0;
	bool m_Timer0Created;

public:
	Factory();
	StateManager* createStateManager();
	EFM32_Timer0* createTimer0();
};



#endif /* FACTORY_FACTORY_HPP_ */
