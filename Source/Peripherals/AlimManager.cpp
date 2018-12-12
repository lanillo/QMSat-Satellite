/*
 * AlimManager.cpp
 *
 *  Created on: 2018-11-19
 *      Author: Guillaume Beaupré
 */

#include "AlimManager.hpp"

/****************************************************/
/**
* \brief Object construtor for the Alim Manager which control the communication with Power Source sub-system
* \return None
*/
AlimManager::AlimManager()
{
	m_BatteryVoltage = 0;

	m_TelecommunicationSubsystemEnable = 0;
	m_QuantumMagnetometerSubsystemEnable = 0;
	m_OBCSubsystemEnable = 0;
	m_AttitudeSubsystemEnable = 0;
}

/****************************************************/
/**
* \brief Get the voltage of the battery
* \return Battery voltage
*/
unsigned short AlimManager::getBatteryVoltage()
{
	if(m_BatteryVoltage == '/0')
	{
		m_BatteryVoltage = 0x1;
	}
	else if(m_BatteryVoltage == 0xA)
	{
		m_BatteryVoltage = 0x9;
	}
	return m_BatteryVoltage;
}

/****************************************************/
/**
* \brief Get the voltage of the battery
* \param[in] p_BatteryVoltage :  Set the last battery voltage from the Alim uC
* \return None
*/
void AlimManager::setBatteryVoltage(unsigned short p_BatteryVoltage)
{
	m_BatteryVoltage = p_BatteryVoltage;
}

/****************************************************/
/**
* \brief Set the Power distribution switch state according from the Alim uC
* \param[in] p_SwitchState :	Contain the power distribution switch state on the OBC
* \return None
*/
void AlimManager::setSwitchState(unsigned short p_SwitchState)
{
	m_SwitchState = p_SwitchState;
}

/****************************************************/
/**
* \brief Get Power distribution switch state stored on the OBC
* \return Power distribution switch states
*/
unsigned short AlimManager::getSwitchState()
{
	return m_SwitchState;
}

/****************************************************/
/**
* \brief Give the actual Telecommunication Sub-system Power Source actual state
* \return Telecommunication Sub-system Power Source actual state
*/
bool AlimManager::isTelecommunicationSubsystemEnable()
{
	return m_TelecommunicationSubsystemEnable;
}

/****************************************************/
/**
* \brief Give the actual Quantum Magnetometer Sub-system Power Source actual state
* \return Quantum Magnetometer Sub-system Power Source actual state
*/
bool AlimManager::isQuantumMagnetometerSubsystemEnable()
{
	return m_QuantumMagnetometerSubsystemEnable;
}

/****************************************************/
/**
* \brief Give the actual OBC Sub-system Power Source actual state
* \return OBC Sub-system Power Source actual state (Should be ON each time you call that function ;D )
*/
bool AlimManager::isOBCSubsystemEnable()
{
	return m_OBCSubsystemEnable;
}

/****************************************************/
/**
* \brief Give the actual Attitude Sub-system Power Source actual state
* \return Attitude Sub-system Power Source actual state
*/
bool AlimManager::isAttitudeSubsystemEnable()
{
	return m_AttitudeSubsystemEnable;
}


/****************************************************/
/**
* \brief function used in the RX Interrupt
* \param[in] p_UART0Instance 		:  The instance of the UART0 Object
* \param[in] p_AlimManagerInstance 	:  The instance of the AlimManager Object
* \return None
*/
void AlimManager::callbackForSerialReceive(void* p_UART0Instance, void* p_AlimManagerInstance)
{
	if (p_UART0Instance != null && p_AlimManagerInstance != null)
	{
		EFM32_UART0* uart = reinterpret_cast<EFM32_UART0*>(p_UART0Instance);
		AlimManager* alimManager = reinterpret_cast<AlimManager*>(p_AlimManagerInstance);
		char RxData = uart->receiveSerial();
		if(RxData == '%')
		{
			uart->m_IsReceiving = true;
			uart->m_RxBufferIndex = 0;
		}
		else if(uart->m_IsReceiving)
		{
			if(RxData != '&')
			{
				uart->m_RxBuffer[uart->m_RxBufferIndex] = RxData;
				uart->m_RxBufferIndex++;
			}
			else
			{
				uart->m_IsReceiving = false;
				if(uart->m_RxBuffer[0] == 'B')
				{
					alimManager->setBatteryVoltage(uart->m_RxBuffer[1]);
				}
				if(uart->m_RxBuffer[0] == 'S')
				{
					alimManager->setSwitchState(uart->m_RxBuffer[1]);
				}
			}
		}
	}
}

