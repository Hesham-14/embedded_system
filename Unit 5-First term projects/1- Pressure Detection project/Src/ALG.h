/*
 * ALG.h
 *
 *  Created on: Mar 3, 2023
 *      Author: hesham mohamed
 */

#ifndef ALG_H_
#define ALG_H_

#include "state.h"

//define states
enum{
	detection
}ALG_state_id;

//declare states functions for mainALG
STATE_define(detection);

//STATE Pointer to function
void (*ALG_state)();

#endif /* ALG_H_ */
