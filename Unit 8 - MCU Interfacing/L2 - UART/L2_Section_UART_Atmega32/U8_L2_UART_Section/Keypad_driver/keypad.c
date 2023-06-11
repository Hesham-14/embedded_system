/*
 * keypad.c
 *
 * Created: 5/1/2023 2:33:42 PM
 *  Author: hesham mohamed
 */ 

#include "keypad.h"

//initialize arrays
int keypad_row[] = {R0, R1, R2, R3};
int keypad_col[] = {C0, C1, C2, C3};
	
void keypad_init()
{
	//0. enable PORTD
	KEYPAD_PORT = 0xFF;
	//1. initialize C' pins as output
	KEYPAD_DDR = 0xF0;
	//2. initialize R' pins as input
	//KEYPAD_PIN = 0xF0;
}

char keypad_get_key()
{
	int i,j;
	//loop for output
	for(i=0; i<4; i++)
	{
		//0. make sure that all col ports are ON
		for(int k=0; k<4; k++)
			SET_BIT(KEYPAD_PORT, keypad_col[k]);
		
		//1. set i pin = 0 GROUND
		CLR_BIT(KEYPAD_PORT, keypad_col[i]);
		
		//loop for j inputs on that output pin i
		for(j=0; j<4; j++)
		{
			//if pin is pressed the ground will be connected to the KEYPAD_PIN
			//So if pin = 0, then its pressed
			if(!(KEYPAD_PIN & (1 << keypad_row[j])))
			{
				//single press mode
				while(!(KEYPAD_PIN & (1 << keypad_row[j])));
				switch(i)
				{
					case(0):
					{
						if(j==0) return '7';
						else if(j==1) return '4';
						else if(j==2) return '1';
						else if(j==3) return '?';
						break;
					}
					case(1):
					{
						if(j==0) return '8';
						else if(j==1) return '5';
						else if(j==2) return '2';
						else if(j==3) return '0';
						break;
					}
					case(2):
					{
						if(j==0) return '9';
						else if(j==1) return '6';
						else if(j==2) return '3';
						else if(j==3) return '=';
						break;
					}
					case(3):
					{
						if(j==0) return '/';
						else if(j==1) return '*';
						else if(j==2) return '-';
						else if(j==3) return '+';
						break;
					}
				}
			}
		}
	}
	//return A if no key is pressed
	return 'A';
}