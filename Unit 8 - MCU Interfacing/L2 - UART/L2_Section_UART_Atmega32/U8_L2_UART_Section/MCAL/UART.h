/*
 * UART.h
 *
 * Created: 5/27/2023 3:48:05 PM
 *  Author: hesham mohamed
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/iom32.h>


//commands
#define SET_BIT(reg,bit) (reg |= (1<< bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit) (reg ^= (1<< bit))


//APIs
void UART_Init(void);
void UART_Send(uint8_t data);
uint8_t UART_Receive(void);


#endif /* UART_H_ */