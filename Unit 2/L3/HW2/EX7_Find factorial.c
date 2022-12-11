/*
 * EX7.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	int x, factorial=1;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &x);
	if(x<0)
		printf("Error!!! Factorial of negative number doesn't exist");
	else if(x==0)
		printf("Factorial = 1");
	else
	{
		do
		{
			factorial *= x--;
		}while(x>=1);
		printf("Factorial = %d", factorial);
	}
}
