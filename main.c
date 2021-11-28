/*
* Interfacing_Modules_AMIT_F20.c
*
* Created: 8/7/2021 7:48:25 PM
* Author : karim
*/

#include "OUTPUT_Module.h"
#include "EXT_INT.h"
#include "UART.h"
#include "SPI.h"

int main(void)
{

  uint8_t  Data_out;
  LED0_Initialize();
  LED1_Initialize();
  LED2_Initialize();
  
  
	
	 UART_Init();
	 SPI_Init();
	 SPI_SlaveSelect(0);
	
	/* Replace with your application code */
	while (1)
	{
	Data_out=UART_Receive();
		SPI_Transmit(Data_out);
		//TO MAKE SURE UART IS OK (MASTER)
		switch(Data_out){
			case '1':
			LED0_ON();
			break;
			case '2':
			LED1_ON();
			break;
			case '3':
			LED2_ON();
			break;
			case '4':
			LED0_OFF();
			break;
			case '5':
			LED1_OFF();
			break;
			case'6':
			LED2_OFF();
			break;
		}
		
		
		
	}
	
} 




