/*
 * AlimManager.hpp
 *
 *  Created on: November 19, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief AlimManager Class Prototype
 */

#ifndef INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_
#define INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_

#include "EFM32_UART0.hpp"

class AlimManager
{
private:
	unsigned short m_BatterieVoltage;
	unsigned short m_SwitchState;
	bool m_TelecommunicationSubsystemEnable;
	bool m_QuantumMagnetometerSubsystemEnable;
	bool m_OBCSubsystemEnable;
	bool m_AttitudeSubsystemEnable;

public:
	AlimManager();
	~AlimManager() {};

	unsigned short getBatterieVoltage();
	unsigned short getSwitchState();
	void setSwitchState(unsigned short p_SwitchState);
	void setBatterieVoltage(unsigned short p_BatterieVoltage);

	bool isTelecommunicationSubsystemEnable();
	bool isQuantumMagnetometerSubsystemEnable();
	bool isOBCSubsystemEnable();
	bool isAttitudeSubsystemEnable();

	static void callbackForSerialReceive(void* p_UART0Instance, void* p_AlimManagerInstance);
};



#endif /* INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_ */
