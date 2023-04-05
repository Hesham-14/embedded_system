/*
 * US.c
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#include "US.h"

//variables
static int US_distance = 0;

//STATE Pointer to function
void (*US_state)();

//generate distance value randomly
int US_get_distance_random(int l, int r, int count);

void US_init()
{
	//initialize US Driver
	printf("US_driver_init \n");
}


STATE_define(US_busy)
{
	//state_name
	US_state_id = US_busy;

	//state_action, read distance
	US_distance = US_get_distance_random(45, 55, 1);

	//event_check
	printf("US_busy state: distance=%d\n", US_distance);

	//send value to the CA block
	UA_get_distance(US_distance);

	//loop in the US_busy state
	US_state = STATE(US_busy);
}

int US_get_distance_random(int l, int r, int count)
{
	//this function generates random number in range l and r
	int i;
	for(i = 0; i < count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
	return 0;
}



