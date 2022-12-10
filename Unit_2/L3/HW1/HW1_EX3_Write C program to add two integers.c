/*
 * EX3.c
 *
 *  Created on: Dec 6, 2022
 *      Author: hesham mohamed
 */


#include <stdio.h>

void main()
{
	int x,y,z;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d\n%d", &x, &y);
	z = x+y;
	printf("Sum: %d", z);

}
