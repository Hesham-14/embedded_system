/*
 * lifo.h
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdlib.h"

//type definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}LIFO_status_t;


//APIs
LIFO_status_t LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length);
LIFO_status_t LIFO_add_item (LIFO_Buf_t* lifo_buf, unsigned int item);
LIFO_status_t LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item);



#endif /* LIFO_H_ */
