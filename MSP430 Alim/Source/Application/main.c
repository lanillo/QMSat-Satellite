/**
 * main.c
 */

#include <msp430.h>
#include "Include/MSP430/MSP430_UART.h"
#include "Include/MSP430/MSP430_ADC.h"
#include "Include/MSP430/MSP430_GPIO.h"
#include "Include/MSP430/MSP430_TimerA.h"
#include "Include/Application/Constants.h"
#include <stddef.h>
#include <math.h>

volatile unsigned long value;
volatile short elapsedTime_millisecond;
unsigned long  voltage_mV;
unsigned short  switchState;;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	BCSCTL1 = CALBC1_1MHZ;      // Set DCO
    DCOCTL  = CALDCO_1MHZ;

    P2DIR |= 0xFF; // All P2.x outputs
    P2OUT &= 0x00; // All P2.x reset

    P4DIR |= 0xFF; // All P4.x outputs
    P4OUT &= 0x00; // All P4.x reset

    initMSP430_UART();
    ConfigureAdc();
    ConfigureSwitchGpioInit();
    ConfigureTimerA();

	__bis_SR_register(GIE);
	__enable_interrupt();


	P1DIR |= GREENLED;
	P1OUT |= GREENLED;

	ADC10CTL0 |= ENC | ADC10SC;

	disableTelecommunicationSubsystem();
	disablePayloadSubsystem();
	disableOBCSubsystem();
	disableAttitudeSubsystem();

	elapsedTime_millisecond = 0;
	switchState = 0x00;
	voltage_mV = 0;
	value = 0;
	while(1)
	{
	    if(elapsedTime_millisecond >= TIME_1_SECOND)
	    {
	        voltage_mV = ((value * 2500) / 102300);
            sendBatterieVoltage((unsigned short)voltage_mV);

            switchState = getSwitchState();
            sendSwitchState(switchState);

            elapsedTime_millisecond = 0;
	    }
	}
}

/***************************************************************************/
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
    value = ADC10MEM;
    ADC10CTL0 |= ENC | ADC10SC;
}

/***************************************************************************/
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{
    elapsedTime_millisecond += 10;
    TACTL &= ~TAIFG;
}
