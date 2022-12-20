/*
 * EX7.c
 *
 *  Created on: Dec 6, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);

	/* We can just swap in output same as EX6, or we can use some mathematical equation as following
	 * the only difference that in EX6 we swapped values only in output screen, but in memory nothing changed.
	 * But here, we swapped values in memory.
	 */

	a += b;
	b = a-b;
	a -= b;

	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of b = %f\n",b);
}
