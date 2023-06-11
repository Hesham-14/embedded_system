/*
 * main.c
 *
 * Created: 4/26/2023 5:20:30 AM
 *  Author: hesham mohamed
 */ 

#define F_CPU 8000000Ul
#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#define IO_BASE 0x20
#define IO_PORTD *(volatile uint8_t *)(IO_BASE + 0X12)
#define IO_DDRD *(volatile uint8_t *)(IO_BASE + 0X11)
#define IO_PIND *(volatile uint8_t *)(IO_BASE + 0X10)

void IO_init()
{
	//set input pin: PD0
	IO_DDRD |= (1 << 0);	//Button0
	
	//set output pins: PD4, PD5, PD6, PD7
	IO_DDRD |= (1 << 4);	//Buzzer
	IO_DDRD |= (1 << 5);	//LED0
	IO_DDRD |= (1 << 6);	//LED1
	IO_DDRD |= (1 << 7);	//LED2
}

void wait_ms(uint32_t time)
{
	uint32_t i, j;
	for(i=0; i < time; i++)
	for(j=0; j < 255; j++);
}


int main(void)
{
	int i;
	IO_init();
    while(1)
    {
		if( ((IO_PIND & (1 << 0)) >> 0) == 1)
		{
			for(i=0; i<3; i++)
			{
				IO_PORTD ^= (1 << (5+i));
				_delay_ms(500);
				IO_PORTD ^= (1 << (5+i));
			}
			IO_PORTD ^= (1 << 4);
			_delay_ms(250);
			IO_PORTD ^= (1 << 4);
			while(((IO_PIND & (1 << 0)) >> 0) == 1);
		}
    }
}