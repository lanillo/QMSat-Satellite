/*
 * RunState.hpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief Run State Prototype
 */

#ifndef INCLUDE_APPLICATION_RUNSTATE_HPP_
#define INCLUDE_APPLICATION_RUNSTATE_HPP_

#include "IState.hpp"
//#include "ISerialComm.hpp"
#include "AlimManager.hpp"
#include "EFM32_USART1.hpp"
#include "EFM32_UART0.hpp"
#include "ITempSensor.hpp"
#include "MCP9808TempSensor.hpp"
#include <stdio.h>

class RunState: public IState
{
public:
	RunState();
	RunState(EFM32_USART1* p_UartUI, EFM32_UART0* p_UartAlim, AlimManager* p_AlimManager, ITempSensor* p_I2C_MCP);
	~RunState() {};

	short getStateId();

private:
	short m_stateId;

	EFM32_USART1* m_UartUI;
	EFM32_UART0* m_UartAlim;
	AlimManager* m_AlimManager;
	ITempSensor* m_I2C_MCP;
  
	char m_ADCValue[3];
	char m_SwitchStateValue[4];

	void onEntry();
	void onExit();
	short execute();
};

#endif /* INCLUDE_APPLICATION_RUNSTATE_HPP_ */
