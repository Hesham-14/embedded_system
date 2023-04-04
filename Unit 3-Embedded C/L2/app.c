//Eng. Hesham Mohamed
// 6PM, 2 Fab 2023

#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:<hesham>";
unsigned char const string_buffer2=5;
unsigned char string_buffer3;

void main(void)
{
	UART_send_string_func(string_buffer);
}