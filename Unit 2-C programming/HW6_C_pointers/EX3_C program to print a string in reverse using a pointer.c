/*
 * EX3.c
 *
 *  Created on: Jan 25, 2023
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	char str[50], revstr[50];
	int i=0;
	char* ptr;
	char* revptr;
	ptr = str;
	revptr = revstr;
	printf("Input a string: ");
	fflush(stdout);
	scanf("%s", str);
	//count string length
	while(*ptr)
	{
		ptr++;
		i++;
	}
	//setting reversed string
	while(i>0)
	{
		ptr--;
		*revptr = *ptr;
		revptr++;
		i--;
	}
	*revptr='\0';
	printf("Reversed string is : %s\n",revstr);

	return 0;
}
