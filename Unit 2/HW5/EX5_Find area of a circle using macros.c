/*
 * EX5.c
 *
 *  Created on: Dec 31, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

#define pi 3.14
#define area(a) printf("Area of the circle = %.2f", ((float)a*2*pi))

int main()
{
	int a;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%d", &a);
	area(a);
	return 0;
}
