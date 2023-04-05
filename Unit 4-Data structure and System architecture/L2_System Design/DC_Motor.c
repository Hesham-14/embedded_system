/*
 * DC.c
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#include "DC_Motor.h"

//variables
static int DC_speed = 0;

//STATE Pointer to function
void (*DC_state)();

void DC_init()
{
	//initialize PWM
	printf("DC_driver_init \n");
}

//read from CA
void DC_motor_set_speed(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("   CA -----speed=%d-----> DC   \n", DC_speed);
}

STATE_define(DC_idle)
{
	//state_name
	DC_state_id = DC_idle;

	/*state_action
	 * call PWM to make speed = DC_speed
	 */

	printf("DC_idle state: speed=%d\n", DC_speed);

}

STATE_define(DC_busy)
{
	//state_name
	DC_state_id = DC_busy;

	/*state_action
	 * call PWM to make speed = DC_speed
	 */

	printf("DC_busy state: speed=%d\n", DC_speed);

	//move to the idle state
	DC_state = STATE(DC_idle);

}




