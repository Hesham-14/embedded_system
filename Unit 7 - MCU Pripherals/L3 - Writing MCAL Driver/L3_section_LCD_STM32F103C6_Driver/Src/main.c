/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hesham Mohamed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "LCD.h"
#include "Keypad.h"


void CLK_init()
{
	//1. GPIO port A clock enable
	RCC_GPIOA_CLK_EN();
	//1. GPIO port B clock enable
	RCC_GPIOB_CLK_EN();
}



void wait_ms(uint32_t time)
{
	uint32_t i, j;
	for(i=0; i < time; i++)
		for(j=0; j < 255; j++);
}

int main()
{
	CLK_init();
	LCD_init();
	keypad_init();
	char key_pressed;
	int i;
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};


	LCD_write_string("Hey Hesham");
	wait_ms(30);
	for (i = 0; i < 11; i++)
	{
		LCD_write_char(LCD_DISPLAY[i]);
		wait_ms(30);
		/* wait for 1 second */
	}

	LCD_clear_screen();
	LCD_write_string("Keypad Ready");
	wait_ms(30);
	LCD_clear_screen();
	while(1)
	{
		key_pressed = keypad_get_key();
		switch(key_pressed)
		{
		case('A'):
					//nothing pressed
					break;
		case('?'):
					LCD_clear_screen();
					break;
		default:
			LCD_write_char(key_pressed);
			break;
		}
	}
	return 0;
}
