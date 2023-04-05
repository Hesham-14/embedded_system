/*
 * MonitorAlarm.c
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#include "MonitorAlarm.h"
#include "driver.h"

//variables
volatile static int alarmDuration = 600000;

//STATE Pointer to function
void (*M_state)();


void high_pressure_detect()
{
	//printf("   ALG -----high pressure-----> MonitorAlarm   \n");
	//moving to M_alarmON state
	M_state = STATE(M_alarmON);
	//M_state();
}

//first state
STATE_define(M_alarmOFF)
{
	//state name
	M_state_id = M_alarmOFF;

	//event check
	//printf("M_alarmOFF state: ...\n");

	//state action --> stop alarm
	stop_alarm();

}

//second state
STATE_define(M_alarmON)
{
	//state name
	M_state_id = M_alarmON;

	//event check
	//printf("M_alarmOFF state: ...\n");

	//state action --> start alarm
	start_alarm();

	//moving to the next state
	M_state = STATE(M_waiting);
	//M_state();

}

//third state
STATE_define(M_waiting)
{
	//state name
	M_state_id = M_waiting;

	//event check
	//printf("M_waiting state: starting a delay of 60 seconds\n");

	//state action --> set a 60 second delay
	Delay(alarmDuration);

	//moving to the next state
	M_state = STATE(M_alarmOFF);
	M_state();

}
