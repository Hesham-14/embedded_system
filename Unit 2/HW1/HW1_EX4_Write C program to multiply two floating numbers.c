/*
 * EX4.c
 *
 *  Created on: Dec 6, 2022
 *      Author: hesham mohamed
 */


#include <stdio.h>

void main()
{
	float x,y,z;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f\n%f", &x, &y);
	z = x*y;
	printf("Product: %f", z);

}
