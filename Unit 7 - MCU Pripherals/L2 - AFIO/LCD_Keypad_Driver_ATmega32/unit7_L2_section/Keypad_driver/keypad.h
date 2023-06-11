/*
 * keypad.h
 *
 * Created: 5/1/2023 2:33:52 PM
 *  Author: hesham mohamed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

//commands
#define SET_BIT(reg,bit) (reg |= (1<< bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit) (reg ^= (1<< bit))

//define PORT
#define KEYPAD_PORT PORTD
#define KEYPAD_DDR DDRD
#define KEYPAD_PIN PIND

//define buttons
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//functions
void keypad_init();
char keypad_get_key();


#endif /* KEYPAD_H_ */