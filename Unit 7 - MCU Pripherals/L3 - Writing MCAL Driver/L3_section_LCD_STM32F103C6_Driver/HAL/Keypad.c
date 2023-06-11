/*
 * Keypad.c
 *
 *  Created on: May 6, 2023
 *      Author: hesham mohamed
 */
#include "STM32F103C6_GPIO_Driver.h"
#include "Keypad.h"

int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns

void keypad_init()
{
		GPIO_PinConfig_t pin;
		int i=0;
		//1. intialize R & C pins as output
		for(i=0; i<=8; i++)
		{
			if(i==2)
				continue;
			pin.GPIO_PinNumber = (0b1 << i);
			pin.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			pin.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(KEYPAD_PORT, &pin);
			MCAL_GPIO_WritePin(KEYPAD_PORT, pin.GPIO_PinNumber , GPIO_PIN_SET);
		}
}

char keypad_get_key()
{
	int i,j;
	for(i=0; i<4; i++)
	{
		//0. write 1 on all col pins
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);

		//1. make first col pin ground to loop its row
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);

		//2. loop over rows and check if power on
		for(j=0; j<4; j++)
		{
			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j] == 0))
			{
				//single press mode
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0);
				switch(i)
				{
				case(0):
													if(j==0) return '7';
													else if(j==1) return '4';
													else if(j==2) return '1';
													else if(j==3) return '?';
				break;
				case(1):
													if(j==0) return '8';
													else if(j==1) return '5';
													else if(j==2) return '2';
													else if(j==3) return '0';
				break;
				case(2):
													if(j==0) return '9';
													else if(j==1) return '6';
													else if(j==2) return '3';
													else if(j==3) return '=';
				break;
				case(3):
													if(j==0) return '/';
													else if(j==1) return '*';
													else if(j==2) return '-';
													else if(j==3) return '+';
				break;
				}
			}
		}

	}
	//return A if no key is pressed
	return 'A';
}
