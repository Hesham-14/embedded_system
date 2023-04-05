/*
 * main.c
 *
 *  Created on: Feb 15, 2023
 *      Author: hesham mohamed
 */

#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

//linked list node
struct SStudent
{
	struct Sdata data;
	struct SStudent* PNextStudent;
};

struct SStudent* gpFirstStudent = NULL;

void fill_student(struct SStudent* PNewStudent)
{
	char temp_text[40];
	//getting the id as a string then transferring it into integer
	DPRINTF("\nEnter student ID: ");
	gets(temp_text);
	PNewStudent->data.ID = atoi(temp_text);

	//getting the name
	DPRINTF("\nEnter student name: ");
	gets(PNewStudent->data.name);

	//getting the height
	DPRINTF("\nEnter student height: ");
	gets(temp_text);
	PNewStudent->data.height = atof(temp_text);
}

void add_student()
{
	struct SStudent* PNewStudent;
	struct SStudent* PLastStudent;

	//check list empty
	if(gpFirstStudent == NULL)
	{
		//create new record
		PNewStudent = (struct SStudent*) malloc (sizeof (struct SStudent));
		//assign it to the pFirstStudent
		gpFirstStudent = PNewStudent;
	}else	//if not empty... adding pointer to the record
	{
		PLastStudent = gpFirstStudent;
		//step from the first element to the last one
		while(PLastStudent->PNextStudent != NULL)
			PLastStudent = PLastStudent->PNextStudent;
		PNewStudent = (struct SStudent*) malloc (sizeof (struct SStudent));
		if(PNewStudent)
			PLastStudent->PNextStudent = PNewStudent;
		else
			DPRINTF("Error while creating place to the new student");
	}

	//filling the new record
	fill_student(PNewStudent);
	//setting the next pointer to NULL
	PNewStudent->PNextStudent = NULL;
}

int delete_student()
{
	//check is the record empty
	if(!gpFirstStudent)
	{
		DPRINTF("\nThere is no any record to delete, list is empty.\n");
	}
	else
	{
		struct SStudent* pSelectedStudent = gpFirstStudent;
		struct SStudent* pPreviousStudent;
		char temp_text[40];
		int selected_id;
		//getting the id as a string then transferring it into integer
		DPRINTF("\nEnter student ID to be deleted: ");
		gets(temp_text);
		selected_id = atoi(temp_text);

		//find the student record
		while(pSelectedStudent)
		{
			//check if the student id matches
			if(pSelectedStudent->data.ID == selected_id)
			{
				if(!pPreviousStudent)	// the first one is the selected id
					gpFirstStudent = pSelectedStudent->PNextStudent;
				else	//the selected id is not the first element
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;

				free (pSelectedStudent); // delete the selected data
				return 1;
			}
			//take a step
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
		DPRINTF("\nSory, can not find the mentioned ID.\n");
		return 0;
	}
	return 0;
}

void view_record()
{
	//check is the record empty
	if(!gpFirstStudent){
		DPRINTF("\nThere is no any record to view, list is empty.\n");
	}
	else
	{
		struct SStudent* pCurrentStudent = gpFirstStudent;
		int count = 0;
		DPRINTF("\nThe record is:\n");
		while(pCurrentStudent)
		{
			//print data
			DPRINTF("Student no.%d info:\n", ++count);
			DPRINTF("\tID: %d\n", pCurrentStudent->data.ID);
			DPRINTF("\tName: %s\n", pCurrentStudent->data.name);
			DPRINTF("\tHeight: %d\n\n", pCurrentStudent->data.height);
			//move to the next student
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	}
}

void delete_record()
{
	//check is the record empty
	if(!gpFirstStudent){
		DPRINTF("\nThere is no any record to delete, list is empty.\n");
	}
	else
	{
		struct SStudent* pCurrentStudent = gpFirstStudent;
		while(pCurrentStudent)
		{
			//move the record to a temp pointer
			struct SStudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
		DPRINTF("\n****Deleteing the record is done****\n");
	}
}

int main(void)
{
	char temp_text[40];
	//creating a menu
	while(1)
	{
		DPRINTF("\n=====================================\n");
		DPRINTF("\n========Wellcome to our record========\n");
		DPRINTF("\nChoose one of the following options:\n");
		DPRINTF("\t1: View Record\n");
		DPRINTF("\t2: Add Student\n");
		DPRINTF("\t3: Delete Student\n");
		DPRINTF("\t4: Delete Record\n");
		DPRINTF("\tEnter Option number:");
		gets(temp_text);

		DPRINTF("\n*************************\n");
		switch (atoi(temp_text))
		{
		case 1:
			view_record();
			break;
		case 2:
			add_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			delete_record();
			break;
		default:
			DPRINTF("\nWrong option");
			break;
		}
		DPRINTF("\n*************************\n");
	}
	return 0;
}
