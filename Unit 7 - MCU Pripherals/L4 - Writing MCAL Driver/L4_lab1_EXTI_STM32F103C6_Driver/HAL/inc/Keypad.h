/*
 * Keypad.h
 *
 *  Created on: May 6, 2023
 *      Author: hesham mohamed
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Driver.h"
//commands
#define SET_BIT(reg,bit) (reg |= (1<< bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit) (reg ^= (1<< bit))

//define PORT
#define KEYPAD_PORT GPIOB

//define buttons
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

//functions
void keypad_init();
char keypad_get_key();

#endif /* INC_KEYPAD_H_ */
