/*
 * EX5.c
 *
 *  Created on: Jan 25, 2023
 *      Author: hesham mohamed
 */

#include <stdio.h>

struct Semployee
{
	char m_first_name[10];
	int m_id;
};

int main()
{
	struct Semployee emp1={"John",1001}, emp2={"Alex",1002}, emp3 = {"Taylor",1003};
	//array of pointers point to each employee data
	struct Semployee* arr[5]={&emp1, &emp2, &emp3};
	struct Semployee *(*pt)[3]=&arr;

	return 0;

}
