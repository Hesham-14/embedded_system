/*
 * EX6.c
 *
 *  Created on: Dec 6, 2022
 *      Author: hesham mohamed
 */


#include <stdio.h>

void main()
{
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);
	printf("After swapping, value of a = %f\n",b);
	printf("After swapping, value of b = %f\n",a);
}
