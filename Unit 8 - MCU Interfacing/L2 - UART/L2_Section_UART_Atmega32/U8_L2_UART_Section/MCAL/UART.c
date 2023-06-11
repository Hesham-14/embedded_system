/*
 * UART.c
 *
 * Created: 5/27/2023 3:47:53 PM
 *  Author: hesham mohamed
 */ 


#include "UART.h"

void UART_Init(void)
{
	//1. BoadRate
	UBRRL = 51;
	
	// Normal mode, divide by 16
	CLR_BIT(UCSRA, U2X);
	
	//2. Frame --> UCSRC
	// Bit 2:1 – UCSZ1:0: Character Size -- > 8-bit
	SET_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	CLR_BIT(UCSRC, UCSZ2);
	
	// Bit 3 – USBS: Stop Bit Select --> 1-bit
	CLR_BIT(UCSRB, USBS);
	
	// Bit 5:4 – UPM1:0: Parity Mode -->  no parity
	CLR_BIT(UCSRC, UPM1);
	CLR_BIT(UCSRC, UPM0);
	
	// Bit 6 – UMSEL: USART Mode --> Asynchro mode
	CLR_BIT(UCSRC, UMSEL);
	
	//3. Enable
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}


void UART_Send(uint8_t data)
{
	//wait for empty transmit buffer
	while(! ((UCSRA >> UDRE) & 0b1));
	
	//put data into buffer, send the data
	UDR = data;
}


uint8_t UART_Receive(void)
{
	//wait for data to be received
	while(! ((UCSRA >> RXC) & 0b1));
	
	//put data into buffer, send the data
	return UDR;
}
