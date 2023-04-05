/*
 * CA.h
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#ifndef CA_H_
#define CA_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

//define states
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE Pointer to function
void (*CA_state)();


#endif /* CA_H_ */
