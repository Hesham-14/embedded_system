/*
 * U8_L4_Section_SPI_Slave_ATmega32.c
 *
 * Created: 5/27/2023 8:48:47 PM
 * Author : hesham mohamed
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/iom32.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

//commands
#define SET_BIT(reg,bit) (reg |= (1<< bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit) (reg ^= (1<< bit))


void SPI_Slave_Init()
{
	//0. Enable output pin: PB5/MISO
	DDRB |= 1<<MISO;
	DDRB &= ~(1<<MOSI) & ~(1<<SS) & ~(1<<SCK);
		
	//1. SPE: Enable SPI
	SPCR = 1 << SPE;
}

uint8_t SPI_Slave_Receive(uint8_t data)
{
	/* Start transmission */
	SPDR = data;
	
	//1. Wait for reception complete 
	while( !(SPSR & (1<<SPIF)) );
	
	//2.return the received data
	return SPDR;
}

void Seven_Seg_init()
{
	//0. Enable output pins: PA0:PA7
	DDRA = 0xFF;
}
int main(void)
{
	uint8_t ch=0;
	SPI_Slave_Init();
	Seven_Seg_init();
	
	for(ch=0; ch <=255; ch++)
	{
		_delay_ms(1000);
		PORTA = SPI_Slave_Receive(ch);
	}
}



