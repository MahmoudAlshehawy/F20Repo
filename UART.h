/*
* UART.h
*
* Created: 2/13/2021 9:11:03 PM
*  Author: karim
*/


#ifndef UART_H_
#define UART_H_

#include "UART_CONFIG.h"

void UART_Init(void);
void UART_Transmit(uint8_t data);
UART_STATUS UART_Tx(uint8_t data);

uint8_t UART_Receive(void);
void UART_RX(uint8_t* data);
UART_STATUS UART_RECIEVE_DATA(uint8_t* data);


void UART_Tx_STR(uint8_t* str);
void UART_Rx_STR(uint8_t* str);

#endif /* UART_H_ */