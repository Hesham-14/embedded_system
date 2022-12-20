/*
 * EX5.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	int a[30],n=0, element=0,i=0;

	//Knowing the elements number
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&n);

	//Storing the elements
	printf("Enter the elements : ");
	for(int i=0; i<n; i++)
	{
		fflush(stdout);
		scanf("%d",&a[i]);
	}

	//Storing the element value
	printf("Enter the element to be searched: ");
	fflush(stdout);
	scanf("%d",&element);

	//Searching for the element
	for(i=0;i<n;i++)
		if(a[i]==element)
		{
			printf("Number found at the location: %d\n",i+1);
			break;
		}
		else
			if(i==n-1)
				printf("Element not found!");


	return 0;
}
