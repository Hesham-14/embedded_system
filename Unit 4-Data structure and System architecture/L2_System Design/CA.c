/*
 * CA.c
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#include "CA.h"

//variables
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

//STATE Pointer to function
void (*CA_state)();

//read from the US
void UA_get_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));	//check state
	printf("   US -----distance=%d-----> CA   \n", CA_distance);
}

STATE_define(CA_waiting)
{
	//state_name
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance=%d speed-->(from:%d ", CA_distance, CA_speed);

	//state_action
	CA_speed = 0;
	printf("to:%d)\n",CA_speed);
	DC_motor_set_speed(CA_speed);

	//US_get_distance(CA_distance)
	//(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));	//check state
}

STATE_define(CA_driving)
{
	//state_name
	CA_state_id = CA_driving;
	printf("CA_driving state: distance=%d speed-->(from:%d ", CA_distance, CA_speed);

	//state_action
	CA_speed = 30;
	printf("to:%d)\n",CA_speed);
	DC_motor_set_speed(CA_speed);

	//US_get_distance(CA_distance)
	//(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));	//check state

}




