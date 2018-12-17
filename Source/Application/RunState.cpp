/*
 * RunState.cpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief RunState Class Definition
 */

#include "RunState.hpp"
#include "Constants.hpp"

/****************************************************/
/**
* \brief By default Object constructor for the RUN State
* \return None
*/
RunState::RunState()
{
	m_stateId = Run;
}

/****************************************************/
/**
* \brief Object constructor for the RUN State
* \param[in] p_UartUI 		:  Pointer to the USART1 Object
* \param[in] p_UartAlim 	:  Pointer to the UART0 Object
* \param[in] p_AlimManager 	:  Pointer to the AlimManager Object
* \param[in] p_I2C_MCP 		:  Pointer to a TempSensor Object
* \return None
*/
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
/**
* \brief Return the unique identifier of the state
* \return 1 for the RUN state
*/
short RunState::getStateId()
{
	return m_stateId;
}

/****************************************************/
/**
* \brief Execute the initial action when entering the state
* \return None
*/
void RunState::onEntry()
{
	m_UartUI->sendSerial("Running State\n",14);
}

/****************************************************/
/**
* \brief Execute the normal set of actions for this state
* \return ID of the next state to be execute
*/
short RunState::execute()
{
	// Get and send the Battery voltage to the UI
	m_ADCValue[1] = m_AlimManager->getBatteryVoltage();
	m_UartUI->sendSerial(m_ADCValue,3);

	// Get and send the Switch state to the Alim uC
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

	// Check if the Battery Voltage of the batteries is too low
	if(m_AlimManager->getBatteryVoltage() < 5)
	{
		return Econo;
	}
	m_UartUI->sendSerial(tempValue,7);


	return Run;
}

/****************************************************/
/**
* \brief Execute the initial action when exiting the state
* \return None
*/
void RunState::onExit()
{

}


