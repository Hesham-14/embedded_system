/*
 * EX8.c
 *
 *  Created on: Dec 10, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	//Declaration
	float x, y;
	char c;

	//goto function
	run_again:
	printf("Enter Operator either + or - or * or divide: ");
	fflush(stdout);
	scanf("%c",&c);

	//checking input
	if(c != '+' && c!= '+' && c != '*' && c!= '/')
	{
		printf("\nFalse input\n");
		goto run_again;
	}

	//taking numbers
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f",&x,&y);

	//switch statement to make the calculations
	switch(c)
	{
	case '+':
		printf("%.3f + %.3f = %.3f", x, y, x+y);
		break;
	case '-':
		printf("%.3f - %.3f = %.3f", x, y, x-y);
		break;
	case '*':
		printf("%.3f * %.3f = %.3f", x, y, x*y);
		break;
	case '/':
		printf("%.3f / %.3f = %.3f", x, y, x/y);
		break;
	}
	return 0;
}
