/*
 * AAD.c
 *
 *  Created on: Mar 3, 2023
 *      Author: hesham mohamed
 */

#include "ALG.h"


//variables
static int ALG_pVal = 0;
static int ALG_threshold = 20;

//STATE Pointer to function
void (*ALG_state)();

//read from Pressure Sensor
void set_pressure_val(int pVal)
{
	ALG_pVal = pVal;
	//printf("   PSD -----pVal=%d-----> ALG   \n", pVal);
	if(ALG_pVal<=ALG_threshold)
		ALG_state = STATE(detection);
	else
	{
		//first send signal to MonitorAlarm.c
		high_pressure_detect();

		//loop
		ALG_state = STATE(detection);
	}
}

STATE_define(detection)
{
	//state_name
	ALG_state_id = detection;

	//event check
	//printf("ALG_detection state: ...\n");

	//loop
	ALG_state = STATE(detection);
}

