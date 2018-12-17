/*
 * AlimManager.cpp
 *
 *  Created on: November 19, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief AlimManager Class Definition
 */

#include "AlimManager.hpp"

/****************************************************/
AlimManager::AlimManager()
{
	m_BatterieVoltage = 0;

	m_TelecommunicationSubsystemEnable = 0;
	m_QuantumMagnetometerSubsystemEnable = 0;
	m_OBCSubsystemEnable = 0;
	m_AttitudeSubsystemEnable = 0;
}

/****************************************************/
unsigned short AlimManager::getBatterieVoltage()
{
	if(m_BatterieVoltage == '/0')
	{
		m_BatterieVoltage = 0x1;
	}
	else if(m_BatterieVoltage == 0xA)
	{
		m_BatterieVoltage = 0x9;
	}
	return m_BatterieVoltage;
}

/****************************************************/
void AlimManager::setBatterieVoltage(unsigned short p_BatterieVoltage)
{
	m_BatterieVoltage = p_BatterieVoltage;
}

/****************************************************/
void AlimManager::setSwitchState(unsigned short p_SwitchState)
{
	m_SwitchState = p_SwitchState;
}

/****************************************************/
unsigned short AlimManager::getSwitchState()
{
	return m_SwitchState;
}

/****************************************************/
bool AlimManager::isTelecommunicationSubsystemEnable()
{
	return m_TelecommunicationSubsystemEnable;
}

/****************************************************/
bool AlimManager::isQuantumMagnetometerSubsystemEnable()
{
	return m_QuantumMagnetometerSubsystemEnable;
}

/****************************************************/
bool AlimManager::isOBCSubsystemEnable()
{
	return m_OBCSubsystemEnable;
}

/****************************************************/
bool AlimManager::isAttitudeSubsystemEnable()
{
	return m_AttitudeSubsystemEnable;
}


/****************************************************/
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
					alimManager->setBatterieVoltage(uart->m_RxBuffer[1]);
				}
				if(uart->m_RxBuffer[0] == 'S')
				{
					alimManager->setSwitchState(uart->m_RxBuffer[1]);
				}
			}
		}
	}
}

