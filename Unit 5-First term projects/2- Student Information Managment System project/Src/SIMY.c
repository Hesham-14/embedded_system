/*
 * SIMY.c
 *
 *  Created on: Mar 7, 2023
 *      Author: hesham mohamed
 */

// SIMY = Student Information Management System
#include "SIMY.h"
#include "fifo.h"


//initialize FIFO

void add_student_file()
{
	//check if FIFO is full
	if(FIFO_FULL(&st_fifo) == FIFO_full)
	{
		DPRINTF("Sorry, the data set is full, try to remove a student then add another");
	}
	else
	{
		//variables: initialize and declare file pointer
		FILE* txt_file = fopen("students_record.txt", "r");
		int ii;

		//check it could read file
		if(txt_file == NULL)
		{
			DPRINTF("Error: could not open %S", txt_file);
		}
		else
		{
			//loop until the end of the file to read every line
			while(!feof(txt_file))
			{
				fscanf(txt_file, "%d", &st.roll);
				//check if the roll is token
				if(search_id(st.roll))
				{
					DPRINTF("\nRoll Number %d is already taken\n", st.roll);

					//to scan every thing before \n then discard it
					fscanf(txt_file, "%*[^\n]");

					// move to the next line
					continue;
				}

				//read the rest of the student data
				fscanf(txt_file, "%s", st.fname);
				fscanf(txt_file, "%s", st.lname);
				fscanf(txt_file, "%f", &st.GPA);
				for (ii = 0; ii < 5; ii++)
				{
					fscanf(txt_file, "%d", &st.cid[ii]);
				}
				DPRINTF("\nRoll Number %d saved successfully\n", st.roll);

				//add student data to the FIFO data set
				FIFO_enqueue(&st_fifo, st);

				//move to the next line
			}

			//close file
			fclose(txt_file);
		}
	}
}

void add_student_manually()
{
	//check if FIFO is full
	if(FIFO_FULL(&st_fifo) == FIFO_full)
	{
		DPRINTF("Sorry, the data set is full, try to remove a student then add another");
	}
	else
	{
		int i;
		//add roll
		DPRINTF("Please, Enter the roll number: ");
		scanf("%d", &st.roll);
		if(!search_id(st.roll))
		{
			//add first name
			DPRINTF("Please, Enter student first name: ");
			scanf("%s", st.fname);
			//add last name
			DPRINTF("Please, Enter student last name: ");
			scanf("%s", st.lname);
			//add GPA
			DPRINTF("Please, Enter student GPA: ");
			scanf("%f", &st.GPA);
			//add cid
			DPRINTF("Please, Enter Course ID of each course: \n");
			for(i=0; i<5;i++)
			{
				DPRINTF("Course %d: ", i+1);
				scanf("%d", &st.cid[i]);
			}

			//add student data to the FIFO data set
			FIFO_enqueue(&st_fifo, st);
		}
		else
		{
			DPRINTF("The referred roll number is already used\n");
		}
	}
}

void find_using_id()
{
	//check FIFO empty
	if(st_fifo.count == 0)
	{
		DPRINTF("Sorry, there is no students in the data set\n");
	}
	else
	{
		int i=0;
		element_type* temp_ptr = st_fifo.tail;

		//get roll number
		DPRINTF("Enter the Roll Number of the student: ");
		scanf("%d", &st.roll);

		//search for the student
		while(i <= st_fifo.count)
		{
			if(temp_ptr->roll == st.roll)
			{
				//show info
				DPRINTF("the Student Details is:\n");
				DPRINTF("\tFirst name: %s\n", temp_ptr->fname);
				DPRINTF("\tLast name: %s\n", temp_ptr->lname);
				DPRINTF("\tRoll number: %d\n", temp_ptr->roll);
				DPRINTF("\tGPA: %f\n", temp_ptr->GPA);
				DPRINTF("\tCourses: \n");
				for(i=0; i<5;i++)
					DPRINTF("\t\tCourse %d: %d\n", i+1, temp_ptr->cid[i]);

				DPRINTF("------------------------------------\n");
				break;
			}
			else
			{
				temp_ptr++;
				i++;
			}
			if(i > st_fifo.count)
				DPRINTF("No student with such a roll number\n");
		}
	}
}

void find_using_fname()
{
	//check FIFO empty
	if(st_fifo.count == 0)
	{
		DPRINTF("Sorry, there is no students in the data set\n");
	}
	else
	{
		int i=0, check=0;
		element_type* temp_ptr = st_fifo.tail;

		//get roll number
		DPRINTF("Enter the first name of the student: ");
		gets(st.fname);

		//search for the student
		while(i <= st_fifo.count)
		{
			if(!stricmp(temp_ptr->fname, st.fname))
			{
				check++;
				//show info
				DPRINTF("------------------------------------\n");
				DPRINTF("the Student Details is:\n");
				DPRINTF("\tFirst name: %s\n", temp_ptr->fname);
				DPRINTF("\tLast name: %s\n", temp_ptr->lname);
				DPRINTF("\tRoll number: %d\n", temp_ptr->roll);
				DPRINTF("\tGPA: %f\n", temp_ptr->GPA);
				DPRINTF("\tCourses: \n");
				for(i=0; i<5;i++)
					DPRINTF("\t\tCourse %d: %d\n", i+1, temp_ptr->cid[i]);

				DPRINTF("------------------------------------\n");
			}
			temp_ptr++;
			i++;
		}
		if(check == 0)
			DPRINTF("No student with such a name\n");
	}

}

void find_c()
{
	//check FIFO empty
	if(st_fifo.count == 0)
	{
		DPRINTF("Sorry, there is no students in the data set\n");
	}
	else
	{
		//variables
		int i=0, check=0, temp;
		element_type* temp_ptr = st_fifo.tail;

		//get roll number
		DPRINTF("Enter the course ID: ");
		scanf("%d", &temp);

		//search for the student
		while(i <= st_fifo.count)
		{
			if(search_c(temp_ptr->cid, temp, 5))
			{
				check++;
				//show info
				DPRINTF("------------------------------------\n");
				DPRINTF("Student No.%d Details are:\n", check);
				DPRINTF("\tFirst name: %s\n", temp_ptr->fname);
				DPRINTF("\tLast name: %s\n", temp_ptr->lname);
				DPRINTF("\tRoll number: %d\n", temp_ptr->roll);
				DPRINTF("\tGPA: %f\n", temp_ptr->GPA);
			}
			temp_ptr++;
			i++;
		}
		if(check == 0)
			DPRINTF("No student with such an enrolled course\n");
	}
}

void tot_st()
{
	DPRINTF("-----------------\n");
	DPRINTF("The total number of Student is %d\n", st_fifo.count);
	DPRINTF("You can add up to %d students\n", st_fifo.length);
	DPRINTF("You can add %d more students\n", st_fifo.length - st_fifo.count);
}

void del_st()
{
	int i, temp;
	//get roll number
	DPRINTF("Enter the Roll Number which you want to delete: ");
	scanf("%d", &temp);

	//point at the required roll number
	for(i=0;i<st_fifo.count;i++)
	{
		if(temp==(st_fifo.base)[i].roll)
			break;
	}

	//delete student record from FIFO
	//by moving backward every FIFO element after the required element
	if(i<st_fifo.count)
	{
		DPRINTF("The Roll Number %d is removed Successfully\n",(st_fifo.base)[i].roll);
		for(;i<st_fifo.count; i++)
		{
			(st_fifo.base)[i]=(st_fifo.base)[i+1];
		}
		//decreasing count, then move head a step backward
		st_fifo.count --;
		st_fifo.head --;
	}

	//no record for the referred roll number
	else
	{
		DPRINTF("This Roll Number %d not found\n", temp);
	}
}

void update_st()
{
	int i, temp, x;
	//get roll number
	DPRINTF("Enter the Roll Number to update the entry: ");
	scanf("%d", &temp);

	//point at the required roll number
	for(i=0;i<st_fifo.count;i++)
	{
		if(temp==(st_fifo.tail)[i].roll)
			break;
	}

	//Function code
	if(i<st_fifo.count)
	{
		//select the required section to update
		DPRINTF("1. First name\n");
		DPRINTF("2. Last name\n");
		DPRINTF("3. GPA\n");
		DPRINTF("4. Courses\n");
		DPRINTF("Select the required section to be updated: ");
		scanf("%d", &x);
		switch(x)
		{
		case 1:
			//add first name
			DPRINTF("Please, Update student first name: ");
			scanf("%s", (st_fifo.tail)[i].fname);
			break;
		case 2:
			//add last name
			DPRINTF("Please, Update student last name: ");
			scanf("%s", (st_fifo.tail)[i].lname);
			break;

		case 3:
			//add GPA
			DPRINTF("Please, Update student GPA: ");
			scanf("%f", &(st_fifo.tail)[i].GPA);
			break;

		case 4:
			//add course id
			DPRINTF("Please, Update Course ID of each course: \n");
			for(i=0; i<5;i++)
			{
				DPRINTF("Course %d: ", i+1);
				scanf("%d", &(st_fifo.tail)[i].cid[i]);
			}
		}
	}

	//no record for the referred roll number
	else
	{
		DPRINTF("This Roll Number %d is not found\n", temp);
	}
}

void show_st()
{
	FIFO_print(&st_fifo);
}

int search_c(int *c, int id, int size)
{
	int i=0;
	for(;i<size; i++)
		if(c[i] == id)
			return 1;
	return 0;
}

int search_id(int rollNumber)
{
	int i;
	element_type* temp_ptr = st_fifo.tail;
	for(i=0; i<st_fifo.count; i++)
		if(temp_ptr->roll == rollNumber)
			return 1;
		else
			temp_ptr++;
	return 0;
}
