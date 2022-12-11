/*
 * EX3.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	float num1, num2, num3;
	printf("Enter Three numbers: ");
	fflush(stdout);
	scanf("%f %f %f", &num1, &num2, &num3);

	if(num1>num2 && num1>num3)
		printf("Largest number = %f", num1);
	else if (num2>num1 && num2>num3)
		printf("Largest number = %f", num2);
	else if (num3>num1 && num3>num2)
		printf("Largest number = %f", num3);
	else
		printf("All numbers are equal.");
}
