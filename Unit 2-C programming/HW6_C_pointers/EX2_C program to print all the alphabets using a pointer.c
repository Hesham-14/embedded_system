/*
 * EX2.c
 *
 *  Created on: Jan 25, 2023
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	char alph[27];
	int i;
	char* ptr;
	ptr = alph;

	//store the alphabets
	for(i=0; i<26;i++)
	{
		*ptr = i+'A';
		ptr++;
	}
	ptr = alph;

	//printing the alphabets
	printf("The alphabets are: ");
	for(i=0; i<26; i++)
	{
		printf("%c ",*ptr);
		ptr++;
	}
	printf("\n");
	return 0;
}
