/*
 * fifo.h
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

//user configuration
//select element type (uint8_t, uint26_t, uint32_t, ....)
#define element_type uint8_t

//create buffer with the same element buffer
#define width1 5
element_type uart_buffer[width1];

//FIFO data types definition
typedef struct {
	uint32_t length;
	uint32_t count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_status_t;


//APIs
FIFO_status_t FIFO_init (FIFO_Buf_t* fifo, element_type* buf, uint32_t length);
FIFO_status_t FIFO_enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_status_t FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_status_t FIFO_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);



#endif /* FIFO_H_ */
