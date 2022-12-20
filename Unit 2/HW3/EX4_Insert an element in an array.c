/*
 * EX4.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	int a[30],n=0, element=0, pos=0,i=0;

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
	printf("Enter the element to be inserted: ");
	fflush(stdout);
	scanf("%d",&element);

	//Storing the element position
	printf("Enter its location: ");
	fflush(stdout);
	scanf("%d",&pos);


	//Adding the element
	for(i=n+1;i>=pos;i--)
		a[i]=a[i-1];
	a[pos-1]=element;

	//Displaying the array
	for(i=0; i<n+1;i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}
