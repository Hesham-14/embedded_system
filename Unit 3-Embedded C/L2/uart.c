//Eng. Hesham Mohamed
//6PM, 2 Fab 2023

#include "uart.h"
//first we need to set the uart register
#define UART0DR *((volatile unsigned int* const)((unsigned int*)0x101f1000)) //give the UART0DR value to the address which this pointer point at

void UART_send_string_func (unsigned char* p_tx_string)
{
	//loop until the end of the string
	while(*p_tx_string != '\0')
	{
		UART0DR = (unsigned int)(*p_tx_string); 	//transmit char
		p_tx_string++;		//move to next char
	}
}