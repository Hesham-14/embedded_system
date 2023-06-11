/*
 * main.c
 *
 * Created: 5/26/2023 7:44:43 PM
 *  Author: hesham mohamed
 */ 

#include <avr/io.h>
#include <avr/iom32.h>
#include "./LCD_driver/LCD.h"
#include "./Keypad_driver/keypad.h"
#include "MCAL/UART.h"


int main(void)
{
	char key_pressed;
    LCD_init();
	keypad_init();
	

	uint8_t x;
	
	UART_Init();
	LCD_write_string("UART: ");
	UART_Send('M');
	UART_Send('Y');
	UART_Send('T');
	LCD_GOTO(2,0);
	
	while (1)
	{
		x = UART_Receive();
		LCD_write_char(x);
	}
}

