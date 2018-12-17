/*
 * InitState.hpp
 *
 *  Created on: January 23, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief Initialization State Prototype
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
	InitState(ILED* p_LED0, ISerialComm* p_UartUI, AlimManager* p_AlimManager);
	~InitState() {};

	short getStateId();

private:
	short m_stateId;
	ILED* m_LED;
	ISerialComm* m_UartUI;
	AlimManager* m_AlimManager;

	char m_SwitchValue[3];

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_INITSTATE_HPP_ */
