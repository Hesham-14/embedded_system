/*
 * EX1.c
 *
 *  Created on: Dec 31, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

struct student
{
	char name[10];
	int roll;
	float marks;
};

int main()
{
	struct student s;
	printf("Enter information of students:\n\n");

	printf("Enter name: ");
	fflush(stdout);
	gets(s.name);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d", &s.roll);

	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f", &s.marks);

	printf("\nDisplaying Information \nname: %s \nRoll: %d \nMarks: %0.3f", s.name, s.roll, s.marks);
	return 0;
}
