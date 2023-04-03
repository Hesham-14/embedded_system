/*
 * EX3.c
 *
 *  Created on: Dec 18, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

// reverse function declaration
void reverse_func(char *str);


int main()
{
	char str[50];
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(str);
	printf("Reversed Sentence: ");
	reverse_func(str);
	return 0;
}

// reverse function definition
void reverse_func(char *str)
{
	if (*str)
	{
		reverse_func(str+1);
		printf("%c", *str);
	}
}

