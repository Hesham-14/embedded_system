/*
 * EX2.c
 *
 *  Created on: Dec 18, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int factorial_func(int x);

int main()
{
	int x=0;
	printf("Enter an positive integer: ");
	fflush(stdout);
	scanf("%d", &x);
	printf("factorial of %d = %d ", x, factorial_func(x));
	return 0;
}

int factorial_func(int x)
{
	if(x>1)
		return x*factorial_func(x-1);
	else
		return 1;
}
