/*
 * MSP430_UART.hpp
 *
 *  Created on: 20 oct. 2018
 *      Author: Guillaume Beaupré
 */

#ifndef INCLUDE_MSP430_MSP430_UART_H_
#define INCLUDE_MSP430_MSP430_UART_H_

/**
 * Receive Data (RXD) at P3.5
 */
#define RXD     BIT5

/**
 * Transmit Data (TXD) at P3.4
 */
#define TXD     BIT4

#define GREENLED BIT0

unsigned int i; //Counter
const char *m_str;

void initMSP430_UART();

unsigned char uart_getc();
void uart_putc(unsigned char p_char);
void uart_puts(const char *p_str);

__interrupt void USCI0RX_ISR(void);
__interrupt void USCI0TX_ISR(void);

#endif /* INCLUDE_MSP430_MSP430_UART_H_ */
