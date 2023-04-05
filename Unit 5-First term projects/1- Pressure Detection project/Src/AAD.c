/*
 * AAD.c
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#include "AAD.h"
#include "driver.h"

//STATE Pointer to function
void (*AAD_state_ptr)();
/*
STATE_define(AAD_waiting);
STATE_define(AAD_start);
STATE_define(AAD_stop);*/

void AAD_init()
{
	//initialize AAD
	//printf("Alarm_Actuator_driver_init \n");
}

STATE_define(AAD_waitingf)
{
	//state name
	AAD_state_id = AAD_waiting;

	//printf("AAD_waiting state: ...\n");
	AAD_state_ptr = STATE(AAD_waitingf);
}

STATE_define(AAD_startf)
{
	//printf("AAD_start state: Alarm ON\n");

	//state action --> set alarm actuator ON
	Set_Alarm_actuator(0);

	//moving to waiting state
	AAD_state_ptr = STATE(AAD_waitingf);
}

STATE_define(AAD_stopf)
{
	//printf("AAD_stop state: Alarm OFF\n");

	//state action --> set alarm actuator OFF
	Set_Alarm_actuator(1);

	//moving to waiting state
	AAD_state_ptr = STATE(AAD_waitingf);
}

void start_alarm()
{
	//printf("   MonitorAlarm -----start_alarm-----> AAD   \n");
	AAD_state_ptr = STATE(AAD_startf);
	AAD_state_ptr();
}

void stop_alarm()
{
	//printf("   MonitorAlarm -----stop_alarm-----> AAD   \n");
	AAD_state_ptr = STATE(AAD_stopf);
	AAD_state_ptr();
}
