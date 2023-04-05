/*
 * SIMY.h
 *
 *  Created on: Mar 7, 2023
 *      Author: hesham mohamed
 */

// SIMY = Student Information Management System
// FIFO = queue

#ifndef SIMY_H_
#define SIMY_H_
#include "fifo.h"

//declare student variable
element_type st;

//declare and initialize FIFO set
FIFO_set_t st_fifo;


//declare functions for SIMY
void add_student_file();
void add_student_manually();
void find_using_id();
void find_using_fname();
void find_c();
void tot_st();
void del_st();
void update_st();
void show_st();
int search_c(int *c, int id, int size);
int search_id(int rollNumber);




#endif /* SIMY_H_ */
