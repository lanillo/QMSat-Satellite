/*
 * MSP430_GPIO.h
 *
 *  Created on: 19 nov. 2018
 *      Author: Guillaume Beaupré
 */

#ifndef INCLUDE_MSP430_MSP430_GPIO_H_
#define INCLUDE_MSP430_MSP430_GPIO_H_

#include <msp430.h>

#define SWITCH_TELECOM BIT1
#define SWITCH_OBC BIT3
#define SWITCH_PAYLOAD BIT2
#define SWITCH_ATTITUDE BIT4

void enableTelecommunicationSubsystem();
void disableTelecommunicationSubsystem();

void enablePayloadSubsystem();
void disablePayloadSubsystem();

void enableOBCSubsystem();
void disableOBCSubsystem();

void enableAttitudeSubsystem();
void disableAttitudeSubsystem();

void ConfigureSwitchGpioInit();
void sendSwitchState(unsigned short p_SwitchState);
void setSwitchState(unsigned short p_SwitchState);
unsigned short getSwitchState();

#endif /* INCLUDE_MSP430_MSP430_GPIO_H_ */
