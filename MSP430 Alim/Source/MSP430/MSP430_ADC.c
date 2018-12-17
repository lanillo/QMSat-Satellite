/*
 * MSP430_ADC.c
 *
 *  Created on: 1 nov. 2018
 *      Author: Guillaume Beaupré
 */

#include "Include/MSP430/MSP430_ADC.h"
#include "Include/MSP430/MSP430_UART.h"

/***************************************************************************/
void ConfigureAdc()
{
   /* Configure ADC Channel */
   ADC10CTL0 = SREF_1 + ADC10SHT_0 + REF2_5V + REFON + ADC10ON + ADC10IE;// internal reference // sample and hold time // VREF = 2.5V // internal reference on // ADC on // Interrupt Enable
   ADC10CTL1 = INCH_5 + SHS_0 + ADC10SSEL_0 + ADC10DIV_3 + CONSEQ_0;// channel 5 = P1.5 // ADC clock source = SMCLK // ADC10CLK/4 // single channel mode
   P3DIR &= ~BIT0;
   P3SEL |= BIT0;
   ADC10AE0 = BIT5; // Enable P3.0 as analog input
}

/***************************************************************************/
unsigned int ReadValueADC()
{
    ADC10CTL0 |= ADC10SC; // Start conversion

    return ADC10MEM;
}

/***************************************************************************/
void sendBatterieVoltage(unsigned short p_voltage)
{
    uart_puts("%B");
    uart_putc(p_voltage);
    uart_putc('&');
}
