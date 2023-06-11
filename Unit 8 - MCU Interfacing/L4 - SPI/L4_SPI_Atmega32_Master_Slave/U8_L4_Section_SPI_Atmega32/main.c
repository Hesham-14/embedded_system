/*
 * U8_L4_Section_SPI_Atmega32.c
 *
 * Created: 5/27/2023 7:20:57 PM
 * Author : hesham mohamed
 */ 

//this code for the SPI Master

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


void SPI_Master_Init()
{
	//0. Enable output pins: PB4/SS, PB5/MOSI, PB7/SCK
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	DDRB &= ~(1<<MISO);	
		
	//1. SPE: Enable SPI
	//2. MSTR: select master
	//3. SPR0: SPI Clock Rate, F/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

uint8_t SPI_Master_Transmit(uint8_t data)
{
	//1. Copy data into SPDR
	SPDR = data;
	
	//2. check if data send successfully or not
	while( !(SPSR & (1<<SPIF)));
	
	//3.return the received data
	return SPDR;
}

void Seven_Seg_init()
{
	//0. Enable output pins: PA0:PA7
	DDRA = 0xFF;
}
int main(void)
{
	uint8_t data=0;
	Seven_Seg_init();
	SPI_Master_Init();
	
	for(data=0; data<=255; data++)
	{
		_delay_ms(1000);
		PORTA = SPI_Master_Transmit(data);
	}
}

