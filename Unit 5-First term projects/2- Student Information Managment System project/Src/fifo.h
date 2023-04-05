/*
 * fifo.h
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "platform_types.h"

/*to fix eclipse bug, I define this macro without needing to put fflush before each printf */
#define DPRINTF(...)      {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

//user configuration

//declare student set
typedef struct {
	char fname[25];
	char lname[25];
	int roll;
	float GPA;
	int cid[5];
} stinfo;

//select element type (uint8_t, uint26_t, uint32_t, ....)
#define element_type stinfo

//create buffer with the same element buffer
#define width 50
element_type fifo_buffer[width];

//FIFO data types definition
typedef struct {
	uint32_t length;
	uint32_t count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_set_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_status_t;


//APIs
FIFO_status_t FIFO_init (FIFO_set_t* fifo, element_type* buf, uint32_t length);
FIFO_status_t FIFO_enqueue(FIFO_set_t* fifo, element_type item);
//FIFO_status_t FIFO_dequeue(FIFO_set_t* fifo, element_type* item);
//FIFO_status_t FIFO_delete(FIFO_set_t* fifo, element_type* item);
FIFO_status_t FIFO_FULL(FIFO_set_t* fifo);
void FIFO_print(FIFO_set_t* fifo);



#endif /* FIFO_H_ */
