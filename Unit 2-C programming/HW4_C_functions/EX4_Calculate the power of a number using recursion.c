/*
 * EX4.c
 *
 *  Created on: Dec 18, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

// reverse function declaration
int power_func(int x, int n);


int main()
{
	// x for base number, n for power number
	int x,n;
	printf("Enter Base number: ");
	fflush(stdout);
	scanf("%d",&x);
	printf("Enter power number (positive integer): ");
	fflush(stdout);
	scanf("%d",&n);
	printf("%d^%d = %d",x,n, power_func(x,n));
	return 0;
}

// reverse function definition
int power_func(int x, int n)
{
	if(n>=1)
		return x*power_func(x,n-1);
	else
		return 1;
}

