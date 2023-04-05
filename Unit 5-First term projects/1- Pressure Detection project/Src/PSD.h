/*
 * PSD.h
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#ifndef PSD_H_
#define PSD_H_

#include "state.h"

//define states
enum{
	PSD_reading,
	PSD_sending,
	PSD_waiting
}PSD_state_id;

//declare states functions for PSD
STATE_define(PSD_reading);
STATE_define(PSD_sending);
STATE_define(PSD_waiting);

//initialize Pressure Sensor Driver
void PSD_init();

//STATE Pointer to function
void (*PSD_state)();

#endif /* PSD_H_ */
