/*
* UART.c
*
* Created: 2/13/2021 9:11:14 PM
*  Author: karim
*/


#include "UART.h"


void UART_Init(void)
{
	/*Baud rate value variable*/
	uint16_t UBRR_Val = 0;
	/*define Tx and Rx bin direction */
	SET_BIT(DDRD,PD1);
	CLR_BIT(DDRD,PD0);
	/*Baud Rate Calculations*/
	UBRR_Val = (((FRQ) /(16 * BAUDRATE)) - 1);//11110101 00111001
	UBRRL = UBRR_Val;     //00000000 00111001
	//UBRRH = UBRR_Val >> 8;//00000000 11110101
	/*disable Interrupt*/
	CLR_BIT(UCSRB,TXCIE);
	CLR_BIT(UCSRB,RXCIE);
	CLR_BIT(UCSRB,UDRIE);
	
	/*Enable Transmitter and Receiver bits*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	/*select UCSRC REGESITER*/
	SET_BIT(UCSRC,URSEL);
	/*Full configuration for UART*/
	//UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);// 9 bit- defining
	CLR_BIT(UCSRC,UCSZ2);SET_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRC,UCSZ0);/*8-bit mode*/
	CLR_BIT(UCSRC,UPM1);CLR_BIT(UCSRC,UPM0);/*no parity mode*/
	CLR_BIT(UCSRC,USBS);/*Stop Bits-1 Bits*/
	
	
	
}
void UART_Transmit(uint8_t data)
{
	UDR = data;
	while (GET_BIT(UCSRA, TXC) != 1);
}
UART_STATUS UART_Tx(uint8_t data){
	    UDR=data;
		while (GET_BIT(UCSRA, TXC) != 1);
		return UART_OK;
}

uint8_t UART_Receive(void)
{
	uint8_t data;
	while (GET_BIT(UCSRA, RXC) != 1);
	data=UDR;
	return data;
}
void UART_RX(uint8_t* data){
	while (GET_BIT(UCSRA, RXC) != 1);
	*data=UDR;
}
UART_STATUS UART_RECIEVE_DATA(uint8_t* data)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	*data=UDR;
	return UART_OK;
}
//void UART_Tx_STR(uint8_t* str)
//{
//	while(*str !='\0'){
//		UART_Tx(*str);
//		_delay_ms(1);
//		str++;
//	}
//}

//void UART_Rx_STR(uint8_t* str)
//{
//uint8_t recieve=0;
//*str =" ";
//while(recieve != '\0')
//{
//	UART_RX(&recieve);
//	_delay_ms(1);
//	*str +=recieve;
//	
//}
//
//}