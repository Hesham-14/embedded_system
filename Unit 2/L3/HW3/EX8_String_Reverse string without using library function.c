/*
 * EX8.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	char s[100], temp;
	int i=0, j=0;
	printf("Enter a string: ");
	fflush(stdout);
	gets(s);
	i=strlen(s)-1;
	while(i>j)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		j++;
		i--;
	}
	printf("Reverse string is: %s",s);
	return 0;
}
