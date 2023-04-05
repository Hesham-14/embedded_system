/*
 * AAD.h
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#ifndef AAD_H_
#define AAD_H_

#include "state.h"

//define states
enum{
	AAD_waiting,
	AAD_start,
	AAD_stop
}AAD_state_id;

//declare states functions for AAD
STATE_define(AAD_waitingf);
STATE_define(AAD_startf);
STATE_define(AAD_stopf);

//initialize Pressure Sensor Driver
//void AAD_init();

//STATE Pointer to function
void (*AAD_state_ptr)();

#endif /* AAD_H_ */
