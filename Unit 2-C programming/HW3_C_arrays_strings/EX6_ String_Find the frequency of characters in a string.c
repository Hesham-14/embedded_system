/*
 * EX6.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	char s[100],c=0;
	int i=0, n=0;
	printf("Enter a string: ");
	fflush(stdout);
	gets(s);
	printf("Enter a character to find frequency: ");
	fflush(stdout);
	scanf("%c",&c);
	for(i=0;i<strlen(s);i++)
		if(s[i]==c)
			n++;
	printf("Frequency of %c = %d",c,n);
	return 0;
}
