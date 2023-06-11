/*
 * U8_L4_Section_SPI_with_MAX7221_Atmega.c
 *
 * Created: 5/28/2023 3:30:42 AM
 * Author : hesham mohamed
 */ 

//Atmega SPI is used as a Master for this project

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

//MAX7221 transmit sequence
/*
0. MAX7221 frame consist of 16 bits, we send the first 8 bits then the other 8 bits
1. CS low
2. transmit 2 bytes of data
3. CS high
* first byte contains the command control bits 
	the second 4 bits of it are used to identify the meaning of the data byte to be followed
* the second byte contains the data
*/
void excute(uint8_t cmd, uint8_t data)
{
	//0. initialize the packet by polling SS low
	PORTB &= ~(1<<SS);
	
	//1. send cmd
	SPDR = cmd;
	
	//2. Wait until transmission is done
	while (!(SPSR & (1<<SPIF)));
	
	//3. send data
	SPDR = data;
	
	//4. Wait until transmission is done
	while (!(SPSR & (1<<SPIF)));
	
	//5. Terminate the packet by polling SS high
	PORTB |= (1<<SS);
}

void Max7221_Init()
{
	//1. decode all displays
	excute(0x09, 0xFF);
	
	//2. Set scan limit
	excute(0x0B, 0x07);
	
	//3. Set max intensity
	excute(0x0A, 0x0F);
	
	//4. Turn on display
	excute(0x0C, 0x01);
}
int main(void)
{
	uint8_t counter=0;
	uint32_t index_display=1;
	SPI_Master_Init();
	Max7221_Init();
	
	while (1)
	{
		for(index_display=1; index_display<9; index_display++)
			excute(index_display, counter++);
		_delay_ms(2000);
	}
	
	
}


