/*
 * EX5.c
 *
 *  Created on: Dec 6, 2022
 *      Author: hesham mohamed
 */


#include <stdio.h>

void main()
{
	char x;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &x);
	printf("ASCII value of %c = %d", x, x);
}
