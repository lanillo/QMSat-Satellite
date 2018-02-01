/*
 * StateManager.hpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume
 */

#include "IState.hpp"

#define MAX_NUMBER_OF_STATES (1U)

class StateManager
{
public:
	StateManager();
	StateManager(IState* p_State);

	void execute();
	void addState(IState* p_State);

private:
	IState* m_States[MAX_NUMBER_OF_STATES];
	IState* m_CurrentState;

	short m_StatesIndex;
	short m_CurrentStateId;
	short m_NextStateId;

	IState* getNextState();
};


