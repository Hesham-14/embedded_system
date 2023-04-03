/*
 * EX4.c
 *
 *  Created on: Jan 25, 2023
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	int i=0, num;
	char str[15];
	char* ptr;
	ptr=str;

	printf("Enter the number of elements to store in the array (max 15): ");
	fflush(stdout);
	scanf("%d", &num);
	for(;i<num; i++)
	{
		printf("element - %d : ", i+1);
		fflush(stdout);
		scanf("%s", &str[i]);
		ptr++;
	}
	--ptr;
	printf("\nReversed : \n");
	while(i>0)
	{
		printf("element - %d : %c\n", i, *ptr);
		ptr--;
		i--;
	}


	return 0;
}
