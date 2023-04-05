/*
 * US.h
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#ifndef US_H_
#define US_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

//define states
enum{
	US_busy
}US_state_id;

//declare states functions US
STATE_define(US_busy);

//initialize US
void US_init();

//STATE Pointer to function
void (*US_state)();


#endif /* US_H_ */
