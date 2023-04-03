/*
 * EX4.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	float num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f", &num);
	if(num > 0)
		printf("%f is positive", num);
	else if (num < 0)
		printf("%f is negative", num);
	else
		printf("You entered zero.");
}
