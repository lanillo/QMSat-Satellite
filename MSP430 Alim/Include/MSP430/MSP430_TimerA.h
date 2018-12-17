/*
 * MSP430_TimerA.h
 *
 *  Created on: 20 nov. 2018
 *      Author: guill
 */

#ifndef INCLUDE_MSP430_MSP430_TIMERA_H_
#define INCLUDE_MSP430_MSP430_TIMERA_H_


#define TIMER_A BIT3

void ConfigureTimerA();

void ConfigureTimerA()
{
    CCTL0 = CCIE;                           // CCR0 interrupt enabled
    TACTL = TASSEL_2 + MC_1 + ID_3;         // SMCLK/8, upmode
    CCR0 =  1000;                          // 100 Hz
    TACTL |= TAIE;
}

#endif /* INCLUDE_MSP430_MSP430_TIMERA_H_ */
