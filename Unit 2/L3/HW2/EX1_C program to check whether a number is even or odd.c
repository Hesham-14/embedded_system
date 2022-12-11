/*
 * EX1.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d", &x);
	if (x%2 == 0)
		printf("%d is even", x);
	else
		printf("%d is odd", x);

}
