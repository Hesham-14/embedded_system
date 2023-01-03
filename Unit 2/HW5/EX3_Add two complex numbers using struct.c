/*
 * EX3.c
 *
 *  Created on: Dec 31, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

struct SComplex
{
	float m_r;	//real number
	float m_i;	//imaginary number
};

struct SComplex read_func(char name[])
{
	struct SComplex C;
	printf("For %s complex number \nEnter real and imaginary respectively:", name);
	fflush(stdout);
	scanf("%f %f", &C.m_r, &C.m_i);
	return C;
}

struct SComplex add_func(struct SComplex A, struct SComplex B)
{
	struct SComplex C;
	C.m_r = A.m_r + B.m_r;
	C.m_i = A.m_i + B.m_i;
	return C;
}

void print_func(struct SComplex C)
{
	printf("The sum of the two complex number = %f + %f i", C.m_r, C.m_i);
}

int main()
{
	struct SComplex x,y;
	x = read_func("1st");
	y = read_func("2nd");
	print_func(add_func(x, y));
	return 0;
}


