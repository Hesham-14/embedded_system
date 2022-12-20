/*
 * EX2.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	float a[100],x=0;
	int n,i;
	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&n);

	for(i=0; i<n;i++)
	{
		printf("Enter number: ");
		fflush(stdout);
		scanf("%f",&a[i]);
		x +=a[i];
	}
	x /= n;
	printf("Average = %0.2f",x);

	return 0;
}
