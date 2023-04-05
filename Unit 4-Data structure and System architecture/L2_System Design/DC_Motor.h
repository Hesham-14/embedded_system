/*
 * DC.h
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#ifndef DC_H_
#define DC_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

//define states
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//declare states functions DC
STATE_define(DC_idle);
STATE_define(DC_busy);

//initialize DC motor
void DC_init();

//STATE Pointer to function
void (*DC_state)();


#endif /* DC_H_ */
