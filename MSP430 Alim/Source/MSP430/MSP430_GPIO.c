/*
 * MSP430_GPIO.c
 *
 *  Created on: 19 nov. 2018
 *      Author: Guillaume Beaupré
 */

#include <Include/MSP430/MSP430_GPIO.h>
#include <Include/MSP430/MSP430_UART.h>

/***************************************************************************/
void enableTelecommunicationSubsystem()
{
    P1OUT |= SWITCH_TELECOM;
}

void disableTelecommunicationSubsystem()
{
    P1OUT &= ~SWITCH_TELECOM;
}

/***************************************************************************/
void enablePayloadSubsystem()
{
    P1OUT |= SWITCH_PAYLOAD;
}

void disablePayloadSubsystem()
{
    P1OUT &= ~SWITCH_PAYLOAD;
}

/***************************************************************************/
void enableOBCSubsystem()
{
    P1OUT |= SWITCH_OBC;
}

void disableOBCSubsystem()
{
    P1OUT &= ~SWITCH_OBC;
}

/***************************************************************************/
void enableAttitudeSubsystem()
{
    P2OUT |= SWITCH_ATTITUDE;
}

void disableAttitudeSubsystem()
{
    P2OUT &= ~SWITCH_ATTITUDE;
}

/***************************************************************************/
void ConfigureSwitchGpioInit()
{
    P1DIR |= SWITCH_TELECOM + SWITCH_OBC + SWITCH_PAYLOAD + SWITCH_ATTITUDE;
    P1OUT &= ~(SWITCH_TELECOM + SWITCH_OBC + SWITCH_PAYLOAD + SWITCH_ATTITUDE);
    P2DIR |= SWITCH_ATTITUDE;
    P2OUT &= ~SWITCH_ATTITUDE;
}

/***************************************************************************/
void sendSwitchState(unsigned short p_SwitchState)
{
    uart_puts("%S");
    uart_putc(p_SwitchState);
    uart_putc('&');
}

unsigned short getSwitchState()
{
    return (P1OUT &= 0b00011110) >> 1;
}

void setSwitchState(unsigned short p_SwitchState)
{
    if(p_SwitchState == 0x1)
    {
        if(P1OUT & SWITCH_TELECOM)
        {
            disableTelecommunicationSubsystem();
        }
        else
        {
            enableTelecommunicationSubsystem();
        }
    }
    else if(p_SwitchState == 0x2)
    {
        if(P1OUT & SWITCH_PAYLOAD)
        {
            disablePayloadSubsystem();
        }
        else
        {
            enablePayloadSubsystem();
        }
    }
    else if(p_SwitchState == 0x4)
    {
        if(P1OUT & SWITCH_OBC)
        {
            disableOBCSubsystem();
        }
        else
        {
            enableOBCSubsystem();
        }
    }
    else if(p_SwitchState == 0x8)
    {
        if(P2OUT & SWITCH_ATTITUDE)
        {
            disableAttitudeSubsystem();
        }
        else
        {
            enableAttitudeSubsystem();
        }
    }
}

