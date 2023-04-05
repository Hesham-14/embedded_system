/*
 * main.c
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#include "stdio.h"
#include "CA.h"
#include "US.h"
#include "DC_Motor.h"

void setup()
{
	//init all the drivers
	//init IRQ ...
	//init HAL US_Driver DC_Driver
	//init block
	US_init();
	DC_init();
	//set states pointers for each block
	CA_state = STATE (CA_waiting);
	US_state = STATE (US_busy);
	DC_state = STATE (DC_idle);
}

int main()
{
	volatile int d, a =0;
	setup();

	while(a<30)
	{
		//call state for each block
		printf("\ntest: %d\n",a);
		US_state();
		CA_state();
		DC_state();
		for(d=0; d<1000; d++);
		a++;
	}

	//extern void (*CA_state)();
	return 0;
}
