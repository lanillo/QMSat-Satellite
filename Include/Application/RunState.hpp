/*
 * RunState.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef INCLUDE_APPLICATION_RUNSTATE_HPP_
#define INCLUDE_APPLICATION_RUNSTATE_HPP_

#include "IState.hpp"
#include "ISerialComm.hpp"
#include "ITempSensor.hpp"
#include <stdio.h>

class RunState: public IState
{
public:
	RunState();
	RunState(ISerialComm* p_USART, ITempSensor* p_I2C_MCP);
	~RunState() {};

	short getStateId();

private:
	short m_stateId;

	ISerialComm* m_USART_UI;
	ITempSensor* m_I2C_MCP;

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_RUNSTATE_HPP_ */
