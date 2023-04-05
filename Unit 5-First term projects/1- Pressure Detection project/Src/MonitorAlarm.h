/*
 * MonitorAlarm.h
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#ifndef MonitorAlarm_H_
#define MonitorAlarm_H_

#include "state.h"

//define states
enum{
	M_alarmOFF,
	M_alarmON,
	M_waiting
}M_state_id;

//declare states functions for MonitorAlarm
STATE_define(M_alarmOFF);
STATE_define(M_alarmON);
STATE_define(M_waiting);

//STATE Pointer to function
void (*M_state)();

#endif /* MonitorAlarm_H_ */
