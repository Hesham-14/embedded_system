/*
 * EX7.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	char s[100];
	int i=0, n=0;
	printf("Enter a string: ");
	fflush(stdout);
	gets(s);
	for(i=0;i<100;i++)
	{
		if(s[i]==0)
			break;
		else
			n++;
	}
	printf("Length of string = %d",n);
	return 0;
}
