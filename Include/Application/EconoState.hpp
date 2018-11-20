/*
 * EconoState.hpp
 *
 *  Created on: 2018-10-22
 *      Author: Guillaume Beaupré
 */

#include "IState.hpp"
#include "ISerialComm.hpp"
#include "AlimManager.hpp"

#ifndef INCLUDE_APPLICATION_ECONOSTATE_HPP_
#define INCLUDE_APPLICATION_ECONOSTATE_HPP_

class EconoState: public IState
{
public:
	EconoState();
	EconoState(ISerialComm* p_UartUI, AlimManager* p_AlimManager);
	~EconoState() {};

	short getStateId();

private:
	short m_stateId;
	ISerialComm* m_UartUI;
	AlimManager* m_AlimManager;

	char m_ADCValue[3];

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_ECONOSTATE_HPP_ */
