/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: hesham mohamed
 */

#include "stdio.h"
#include "SIMY.h"

void startup()
{
	//variables
		int x=0;

	//set up system menu
	DPRINTF("WELCOME TO THE STUDENT MANAGMENT SYSTEM\n");
	DPRINTF("=======================================\n");
	while(1)
	{
		DPRINTF("Choose the task that you want to perform\n");
		DPRINTF("1. Add the student details from text file\n");
		DPRINTF("2. Add the student details manually\n");
		DPRINTF("3. Find the student details by Roll number\n");
		DPRINTF("4. Find the student details by first name\n");
		DPRINTF("5. Find the student details by course ID\n");
		DPRINTF("6. Find the total number of students\n");
		DPRINTF("7. Delete the student details by Roll number\n");
		DPRINTF("8. Update the student details by Roll number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("Enter your choice to perform the task:");
		scanf("%d", &x);
		switch(x)
		{
		case 1:
			add_student_file();
			break;
		case 2:
			add_student_manually();
			break;
		case 3:
			find_using_id();
			break;
		case 4:
			find_using_fname();
			break;
		case 5:
			find_c();
			break;
		case 6:
			tot_st();
			break;
		case 7:
			del_st();
			break;
		case 8:
			update_st();
			break;
		case 9:
			show_st();
			break;
		}
		DPRINTF("\n=======================================\n");
		if(x == 10)
			break;
	}

}

int main()
{
	//Initialize student data structure (FIFO)
	if(FIFO_init(&st_fifo, fifo_buffer, 50) == FIFO_no_error)
		DPRINTF("---FIFO initialize    -> Done---\n");

	//launch system
	startup();

	return 0;
}
