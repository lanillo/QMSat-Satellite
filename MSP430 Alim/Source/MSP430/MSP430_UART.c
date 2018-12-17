/*
 * MSP430_UART.cpp
 *
 *  Created on: 20 oct. 2018
 *      Author: guillaume
 */

//#include "uart.h"
#include <Include/MSP430/MSP430_UART.h>
#include <Include/MSP430/MSP430_GPIO.h>
#include <msp430.h>

volatile short IsReceiving = 0;
volatile char RxBuffer[50];
volatile unsigned short RxBufferIndex;

//************************************************************
void initMSP430_UART()
{
    P3SEL |= RXD + TXD ; // P3.5 (Pin 26) = RXD,; P3.4 (Pin 25) =TXD
    P3OUT &= 0x00;
    P3OUT &= ~TXD;
    P3DIR |= TXD;
    //UCA0CTL0 |= UCMSB;                        //MSB first
    UCA0CTL0 &= ~UC7BIT;                        //frame of 8 bits
    UCA0CTL0 &= ~UCPEN;                         //No parity bit
    UCA0CTL0 &= ~UCSPB;                         //1 stop bit
    UCA0CTL0 &= ~UCSYNC;                        //mode asynchrone
    UCA0CTL1 |= UCSSEL_2;                       // SMCLK
    UCA0BR0 = 104;                              // 8MHz 9600
    UCA0BR1 = 0;                                // 8MHz 9600
    UCA0MCTL &= UCBRS_0;                        // Modulation UCBRSx = 2
    //UCA0STAT |= 0X80;
    UCA0CTL1 &= ~UCSWRST;                       // Initialize USCI state machine
    IE2 |= UCA0RXIE ;//+ UCA0TXIE;              // Enable USCI_A0 RX interrupt
}

//************************************************************
unsigned char uart_getc()
{
    while (!(IFG2&UCA0RXIFG));                // USCI_A0 RX buffer ready?
    return UCA0RXBUF;
}

//************************************************************
void uart_putc(unsigned char p_char)
{
    while (!(IFG2&UCA0TXIFG));              // USCI_A0 TX buffer ready?
    UCA0TXBUF = p_char;                          // TX
}

//************************************************************
void uart_puts(const char *p_str)
{
     while(*p_str)
     {
         uart_putc(*p_str++);
     }
}

//************************************************************
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
   char RxData = uart_getc();
   if(RxData == '%')
   {
       IsReceiving = 1;
       RxBufferIndex = 0;
   }
   else if(IsReceiving)
   {
       if(RxData != '&')
       {
           RxBuffer[RxBufferIndex] = RxData;
           RxBufferIndex++;
       }
       else
       {
           IsReceiving = 0;
           if(RxBuffer[0] == 'O')
           {
               setSwitchState(RxBuffer[1]);
           }
       }
   }
}

//************************************************************
#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
    int a = 1;
}
