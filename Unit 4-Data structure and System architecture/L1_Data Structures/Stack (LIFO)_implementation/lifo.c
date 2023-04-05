/*
 * lifo.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#include "lifo.h"

//APIs
LIFO_status_t LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
	//check buffer availability
	if (buf == NULL)
		return LIFO_null;

	//initializing LIFO pointers
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}

LIFO_status_t LIFO_add_item (LIFO_Buf_t* lifo_buf, unsigned int item)
{
	//check LIFO existence
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_null;

	//check LIFO fullness
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	//adding value
	*(lifo_buf->head++) = item;
	lifo_buf->count++;

	return LIFO_no_error;
}

LIFO_status_t LIFO_get_item (LIFO_Buf_t* lifo_buf, unsigned int* item)
{
	//check LIFO existence
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_null;
	//check LIFO is empty
	if(lifo_buf->count == 0)
		return LIFO_empty;
	//getting value
	*item = *(--lifo_buf->head);
	lifo_buf->count--;

	return LIFO_no_error;
}



