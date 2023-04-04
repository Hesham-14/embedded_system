/*
 * main.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#include "lifo.h"

//initialize the buffer array
unsigned int buffer1 [5];

int main(void)
{
	unsigned int i=1,temp;

	//initialize 2 LIFO buffers
	LIFO_Buf_t uart_lifo, I2C_lifo;

	//using static allocation
	LIFO_init(&uart_lifo, buffer1, 5);

	//adding values
	for (; i<=6; i++)
	{
		if( LIFO_add_item(&uart_lifo, i) == LIFO_no_error)
			printf("UART_LIFO added item : %d\n",i);
		else if ( LIFO_add_item(&uart_lifo, i) == LIFO_full)
			printf("LIFO is full, buddy!!\n");
		else if ( LIFO_add_item(&uart_lifo, i) == LIFO_null)
			printf("C'mon man, there is no LIFO exist at all!!\n");
	}
	printf("\n*****************\n\n");

	//printing values
	for (i=1; i<=7; i++)
	{
		if( LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
			printf("UART_LIFO Printed item : %d\n",temp);
		else if ( LIFO_get_item(&uart_lifo, &temp) == LIFO_null)
			printf("C'mon man, there is no LIFO exist at all!!\n");
		else if ( LIFO_get_item(&uart_lifo, &temp) == LIFO_empty)
			printf("It's all out bro, LIFO is empty :)\n");
	}

	printf("\n===============================================\n\n");
	//using dynamic allocation
	unsigned int* buffer2 = (unsigned int*) malloc(5 * sizeof(unsigned int));
	LIFO_init(&I2C_lifo, buffer2, 5);
	//adding values
	for (i=1; i<=6; i++)
	{
		if( LIFO_add_item(&I2C_lifo, i) == LIFO_no_error)
			printf("UART_LIFO added item : %d\n",i);
		else if ( LIFO_add_item(&I2C_lifo, i) == LIFO_full)
			printf("LIFO is full, buddy!!\n");
		else if ( LIFO_add_item(&I2C_lifo, i) == LIFO_null)
			printf("C'mon man, there is no LIFO exist at all!!\n");
	}
	printf("\n*****************\n\n");

	//printing values
	for (i=1; i<=7; i++)
	{
		if( LIFO_get_item(&I2C_lifo, &temp) == LIFO_no_error)
			printf("UART_LIFO Printed item : %d\n",temp);
		else if ( LIFO_get_item(&I2C_lifo, &temp) == LIFO_null)
			printf("C'mon man, there is no LIFO exist at all!!\n");
		else if ( LIFO_get_item(&I2C_lifo, &temp) == LIFO_empty)
			printf("It's all out bro, LIFO is empty :)\n");
	}

	return 0;
}
