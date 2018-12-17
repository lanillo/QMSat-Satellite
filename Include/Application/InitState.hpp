/*
 * InitState.hpp
 *
 *  Created on: 2018-01-23
 *      Author: Guillaume
 */

#include "IState.hpp"
#include "ILED.hpp"
#include "ISerialComm.hpp"
#include "AlimManager.hpp"

#ifndef INCLUDE_APPLICATION_INITSTATE_HPP_
#define INCLUDE_APPLICATION_INITSTATE_HPP_

class InitState: public IState
{
public:
	InitState();
	InitState(ISerialComm* p_UartUI, AlimManager* p_AlimManager);
	~InitState() {};

	short getStateId();

private:
	short m_stateId;
	ISerialComm* m_UartUI;
	AlimManager* m_AlimManager;

	char m_SwitchValue[3];

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_INITSTATE_HPP_ */
