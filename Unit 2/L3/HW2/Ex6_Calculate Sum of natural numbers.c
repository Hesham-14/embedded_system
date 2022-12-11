/*
 * EX6.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	int x, sum=0;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &x);
	do
	{
		sum += x--;
	}while(x>0);
	printf("Sum = %d", sum);
}
