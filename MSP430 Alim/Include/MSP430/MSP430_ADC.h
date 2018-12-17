/*
 * MSP430_ADC.h
 *
 *  Created on: 1 nov. 2018
 *      Author: Guillaume Beaupré
 */

#ifndef INCLUDE_MSP430_MSP430_ADC_H_
#define INCLUDE_MSP430_MSP430_ADC_H_

#include <msp430.h>

#define LED0 BIT0

void ConfigureAdc(void);

unsigned int ReadADCValue();
void sendBatterieVoltage(unsigned short p_voltage);

// ADC10 interrupt service routine
__interrupt void ADC10_ISR (void);

#endif /* INCLUDE_MSP430_MSP430_ADC_H_ */
