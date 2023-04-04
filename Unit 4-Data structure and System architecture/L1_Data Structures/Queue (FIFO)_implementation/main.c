/*
 * main.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#include "fifo.h"



int main(void)
{
	element_type i, temp;
	FIFO_Buf_t uart_fifo;
	//init FIFO
	if(FIFO_init(&uart_fifo, uart_buffer, 5) == FIFO_no_error)
		printf("---FIFO init    -> Done---\n");

	//enqueue
	for(i=1; i<7; i++)
		if(FIFO_enqueue(&uart_fifo, i)== FIFO_no_error)
			printf("---FIFO enqueue -> Done---\n");
		else
			printf("***ERROR: While enqueue process***\n");

	//print FIFO
	FIFO_print(&uart_fifo);

	//dequeue
	if(FIFO_dequeue(&uart_fifo, &temp)== FIFO_no_error)
		printf("\n---FIFO dequeue: %x -> Done---\n", temp);
	else
		printf("\n***ERROR: While dequeue process***\n");

	//second dequeue
	if(FIFO_dequeue(&uart_fifo, &temp)== FIFO_no_error)
		printf("\n---FIFO dequeue: %x -> Done---\n", temp);
	else
		printf("\n***ERROR: While dequeue process***\n");

	//print FIFO
	FIFO_print(&uart_fifo);


	return 0;
}
