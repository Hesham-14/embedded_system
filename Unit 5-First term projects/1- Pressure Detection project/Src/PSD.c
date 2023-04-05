/*
 * PSD.c
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#include "PSD.h"
#include "driver.h"

//variables
static int pVal = 0;

//STATE Pointer to function
void (*PSD_state)();


void PSD_init()
{
	//initialize Pressure Sensor Driver
	//printf("PSD_init \n");
}

//first state
STATE_define(PSD_reading)
{
	//state_name
	PSD_state_id = PSD_reading;

	//state_action --> read pressure value
	pVal = getPressureVal();

	//event check
	//printf("PSD_reading state: pressure=%d\n", pVal);

	//moving to the next state
	STATE(PSD_sending)();

}

//second state
STATE_define(PSD_sending)
{
	//state_name
	PSD_state_id = PSD_sending;

	//event check
	//printf("PSD_sending state: ...\n");

	//moving to the next state
	STATE(PSD_waiting)();

	//state_action --> send value to mainALG.c
	set_pressure_val(pVal);

}

//second state
STATE_define(PSD_waiting)
{
	//state_name
	PSD_state_id = PSD_waiting;

	//event check
	//printf("PSD_waiting state: setting a delay of 90 seconds\n");

	//state action --> set a 90 second delay
	Delay(90000);

	//get back to reading state
	PSD_state = STATE(PSD_reading);

}


