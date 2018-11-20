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
#include "AlimManager.hpp"
#include "EFM32_USART1.hpp"

class RunState: public IState
{
public:
	RunState();
	RunState(EFM32_USART1* p_UartUI, ISerialComm* p_UartAlim, AlimManager* p_AlimManager);
	~RunState() {};

	short getStateId();

private:
	short m_stateId;

	EFM32_USART1* m_UartUI;
	ISerialComm* m_UartAlim;
	AlimManager* m_AlimManager;

	char m_ADCValue[3];
	char m_SwitchStateValue[4];

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_RUNSTATE_HPP_ */
