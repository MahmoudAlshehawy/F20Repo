/*
 * SPI.h
 *
 * Created: 2/19/2021 8:18:47 PM
 *  Author: karim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_CONFIG.h"


void SPI_Init(void);
void SPI_Transmit( uint8_t data);
 uint8_t SPI_Receive(void);
void SPI_SlaveSelect( uint8_t slave);

SPI_Status SPI_Transeive(uint8_t dataSent, uint8_t* dataReceived);

#endif /* SPI_H_ */