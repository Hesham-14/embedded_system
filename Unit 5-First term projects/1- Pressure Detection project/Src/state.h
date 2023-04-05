/*
 * state.h
 *
 *  Created on: Mar 1, 2023
 *      Author: hesham mohamed
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>


//Automatic state function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//states connection
void set_pressure_val(int pVal); 	//define it in the receiving block.c
void high_pressure_detect();		//define it in the receiving block.c
void start_alarm();					//define it in the receiving block.c
void stop_alarm();					//define it in the receiving block.c


#endif /* STATE_H_ */
