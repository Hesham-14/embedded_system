/*
 * state.h
 *
 *  Created on: Feb 21, 2023
 *      Author: hesham mohamed
 */

#ifndef STATE_H_
#define STATE_H_

//Automatic state function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//states connection
void UA_get_distance(int d); 	//define it in the receiving block.c
void DC_motor_set_speed(int s);	//define it in the receiving block.c

#endif /* STATE_H_ */
