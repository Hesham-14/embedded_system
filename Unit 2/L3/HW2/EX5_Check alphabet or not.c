/*
 * EX5.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	char x;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &x);

	if (x >= 65 && x <= 122)
		printf("%c is an alphabet", x);
	else
		printf("%c is not an alphabet", x);
}
