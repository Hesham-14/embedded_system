/*
 * EX2.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

void main()
{
	char x;

	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &x);

	if (x == 65 || x == 69 || x == 73 || x == 79 || x == 85 ||
			x == 97 || x == 101 || x == 105 || x == 111 || x == 117)
		printf("%c is vowel", x);
	else
		printf("%c is consonant", x);

}
