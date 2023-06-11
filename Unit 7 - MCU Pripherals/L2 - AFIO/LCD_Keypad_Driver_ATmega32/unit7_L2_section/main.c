/*
 * unit7_L2_section.c
 *
 * Created: 4/26/2023 9:34:54 AM
 * Author : hesham mohamed
 */ 

#include "LCD_driver/LCD.h"
#include "Keypad_driver/keypad.h"


int main(void)
{
	char key_pressed;
    LCD_init();
	keypad_init();
	
    while (1) 
    {
		key_pressed = keypad_get_key();
		switch(key_pressed)
		{
			case('A'):	//nothing pressed
			break;
			case('?'):
			{
				LCD_clear_screen();
				break;
			}
			default:
			{
				LCD_write_char(key_pressed);
				break;
			}
		}
    }
}

