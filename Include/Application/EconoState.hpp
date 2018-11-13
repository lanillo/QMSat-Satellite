/*
 * EconoState.hpp
 *
 *  Created on: 2018-10-22
 *      Author: Guillaume Beaupré
 */

#include "IState.hpp"
#include "ISerialComm.hpp"

#ifndef INCLUDE_APPLICATION_ECONOSTATE_HPP_
#define INCLUDE_APPLICATION_ECONOSTATE_HPP_

class EconoState: public IState
{
public:
	EconoState();
	EconoState(ISerialComm* p_USART);
	~EconoState() {};

	short getStateId();

private:
	short m_stateId;
	ISerialComm* m_USART;

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_ECONOSTATE_HPP_ */
