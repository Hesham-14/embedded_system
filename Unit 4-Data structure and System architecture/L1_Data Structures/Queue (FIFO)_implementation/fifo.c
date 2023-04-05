/*
 * fifo.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#include "fifo.h"

//APIs
FIFO_status_t FIFO_init (FIFO_Buf_t* fifo, element_type* buf, uint32_t length)
{
	///check buffer
	if(buf == NULL)
		return FIFO_null;

	//create FIFO
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}
FIFO_status_t FIFO_enqueue(FIFO_Buf_t* fifo, element_type item)
{
	//check FIFO existence
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//check FIFO FULL
	if(FIFO_FULL(fifo) == FIFO_full)
		return FIFO_full;
	//enqueue process
	*(fifo->head) = item;
	fifo->count++;

	//circler FIFO
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head=fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;
}
FIFO_status_t FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	//check FIFO existence
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//check FIFO empty
	if(fifo->count == 0)
		return FIFO_empty;

	//dequeue process
	*item = *(fifo->tail);
	fifo->count--;

	//circler FIFO
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail=fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;
}
FIFO_status_t FIFO_FULL(FIFO_Buf_t* fifo)
{
	//check FIFO existence
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//check fullness
	if(fifo->count == fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}

void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count == 0)
		printf("---FIFO is empty---\n");
	else
	{
		temp = fifo->tail;
		printf("\n=====fifo_print=====\n");
		for (i = 1; i <= fifo->count; ++i) {
			printf("element %d is : %x\n",i, *temp);
			temp++;
		}
		printf("=====print -> Done=====\n");
	}
}




