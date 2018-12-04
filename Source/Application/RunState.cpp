/*
 * RunState.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume Beaupré
 */

#include "RunState.hpp"
#include "Constants.hpp"

/****************************************************/
RunState::RunState()
{
	m_stateId = Run;
}

/****************************************************/
RunState::RunState(EFM32_USART1* p_UartUI, EFM32_UART0* p_UartAlim, AlimManager* p_AlimManager, ITempSensor* p_I2C_MCP)
{
	m_UartUI = p_UartUI;
	m_UartAlim = p_UartAlim;
	m_AlimManager = p_AlimManager;
	m_I2C_MCP = p_I2C_MCP;

	m_ADCValue[0] = 'B';
	m_ADCValue[2] = '\n';

	m_SwitchStateValue[0] = '%';
	m_SwitchStateValue[1] = 'O';
	m_SwitchStateValue[3] = '&';

	m_stateId = Run;
}

/****************************************************/
short RunState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void RunState::onEntry()
{
	m_UartUI->sendSerial("Running State\n",14);
}

/****************************************************/
short RunState::execute()
{
	m_ADCValue[1] = m_AlimManager->getBatterieVoltage();
	m_UartUI->sendSerial(m_ADCValue,3);

	if(m_UartUI->getSwitchState() == true)
	{
		m_UartUI->setSwitchState(false);
		m_SwitchStateValue[2] = m_UartUI->getSwitchForAlim();
		m_UartAlim->sendSerial(m_SwitchStateValue,4);
	}
	// Start I2C and get ambient temperature (Ta)
	m_I2C_MCP->getTemp();
	// Create char* for UI with Ta
	char* temperatureString = m_I2C_MCP->tempToString();
	char tempValue[7];
	for(int i = 0; i<6; i++)
	{
		tempValue[i] = *temperatureString++;
	}
	tempValue[6] = '\n';
	if(m_AlimManager->getBatterieVoltage() < 5)
	{
		return Econo;
	}
	/*bool megagenial = false;
	if(megagenial)
	{
		m_UartUI->sendSerial("T24.25\n",7);
	}
	else
	{
		m_UartUI->sendSerial("T24.20\n",7);
	}*/
	m_UartUI->sendSerial(tempValue,7);
	return Run;
}

/****************************************************/
void RunState::onExit()
{

}


