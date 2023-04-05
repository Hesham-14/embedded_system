/* main.c
 *
 *  Created on: Feb 25, 2023
 *      Author: hesham mohamed
 */

#include <stdio.h>
#include "ALG.h"
#include "PSD.h"
#include "AAD.h"
#include "MonitorAlarm.h"
#include "driver.h"


void setup()
{
	//init all the drivers
	GPIO_INITIALIZATION();
	//init IRQ ...
	//init HAL
	//init block
	PSD_init();
	AAD_init();
	//set states pointers for each block
	PSD_state = STATE (PSD_reading);
	ALG_state = STATE (detection);
	M_state = STATE (M_alarmOFF);
	AAD_state_ptr = STATE(AAD_waitingf);
}

int main()
{
	volatile int d, a =0;
	setup();

	while(a<30)
	{
		//call state for each block
		//printf("\ntest: %d\n",a);
		PSD_state();
		ALG_state();
		M_state();
		AAD_state_ptr();
		for(d=0; d<1000; d++);
		a++;
		//printf("\n--------------------------------------------\n");
	}

	return 0;
}
