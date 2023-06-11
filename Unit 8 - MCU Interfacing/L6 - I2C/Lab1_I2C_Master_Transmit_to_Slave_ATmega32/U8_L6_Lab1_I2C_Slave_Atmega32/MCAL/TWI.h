/*
 * TWI.h
 *
 * Created: 6/3/2023 9:29:12 PM
 *  Author: Hesham Mohamed
 */ 


#ifndef TWI_H_
#define TWI_H_

//====================
// Includes
//====================
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

//====================
// APIs
//====================

//function select the mode, take the mode and the message
void MCAL_TWI_Init(unsigned long SCL_Clock);
void MCAL_TWI_Master_Transmit(uint8_t T_data);
void MCAL_TWI_Master_Receive(uint8_t R_data);
void MCAL_TWI_Slave_Transmit(uint8_t T_data);
uint8_t MCAL_TWI_Slave_Receive();
void TWI_SetAddress(unsigned char address);


#endif /* TWI_H_ */