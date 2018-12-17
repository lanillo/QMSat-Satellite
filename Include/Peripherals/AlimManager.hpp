/*
 * AlimManager.hpp
 *
 *  Created on: November 19, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupr�.
 *
 *   \brief AlimManager Class Prototype
 */

#ifndef INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_
#define INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_

#include "EFM32_UART0.hpp"

class AlimManager
{
private:
	unsigned short m_BatteryVoltage;
	unsigned short m_SwitchState;
	bool m_TelecommunicationSubsystemEnable;
	bool m_QuantumMagnetometerSubsystemEnable;
	bool m_OBCSubsystemEnable;
	bool m_AttitudeSubsystemEnable;

public:
	AlimManager();
	~AlimManager() {};

	unsigned short getBatteryVoltage();
	unsigned short getSwitchState();
	void setSwitchState(unsigned short p_SwitchState);
	void setBatteryVoltage(unsigned short p_BatteryVoltage);

	bool isTelecommunicationSubsystemEnable();
	bool isQuantumMagnetometerSubsystemEnable();
	bool isOBCSubsystemEnable();
	bool isAttitudeSubsystemEnable();

	static void callbackForSerialReceive(void* p_UART0Instance, void* p_AlimManagerInstance);
};



#endif /* INCLUDE_PERIPHERALS_ALIMMANAGER_HPP_ */
