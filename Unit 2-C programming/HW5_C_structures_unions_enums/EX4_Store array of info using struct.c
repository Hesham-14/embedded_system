/*
 * EX4.c
 *
 *  Created on: Dec 31, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

struct Sstudent
{
	char m_name[10];
	int m_roll;
	float m_marks;
};

int main()
{
	struct Sstudent s[10];
	int i;

	printf("Enter information of students:\n");

	//storing every student data
	for(i=1; i<=10; i++)
	{
		s[i].m_roll = i;
		printf("\nFor roll number %d\n", s[i].m_roll);

		printf("Enter name: ");
		fflush(stdout);
		scanf("%s", s[i].m_name);

		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f", &s[i].m_marks);
	}

	//printing data
	printf("\n\nDisplaying information of students:\n");
	for(i=1; i<=10; i++)
	{
		printf("\nInformation for roll number %d:\n", s[i].m_roll);
		printf("Name: %s\n", s[i].m_name);
		printf("Marks: %.1f\n", s[i].m_marks);
		if(s[i].m_roll == 0)
			break;
	}
	return 0;
}
