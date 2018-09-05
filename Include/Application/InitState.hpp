/*
 * InitState.hpp
 *
 *  Created on: 2018-01-23
 *      Author: Guillaume
 */

#include "IState.hpp"
#include "ILED.hpp"
#include "ISerialComm.hpp"

#ifndef INCLUDE_APPLICATION_INITSTATE_HPP_
#define INCLUDE_APPLICATION_INITSTATE_HPP_

class InitState: public IState
{
public:
	InitState();
	InitState(ILED* p_LED0,ISerialComm* p_USART);
	~InitState() {};

	short getStateId();

private:
	short m_StateId;
	ILED* m_LED;
	ISerialComm* m_USART;

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_INITSTATE_HPP_ */
