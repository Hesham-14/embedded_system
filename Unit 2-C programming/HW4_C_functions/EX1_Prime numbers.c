/*
 * EX1.c
 *
 *  Created on: Dec 18, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

/*In this program, there are two ways to get prime numbers*/
/*First, using For loop with only one parameter*/
int check_prime(int x);

/*Second, using recursion with two prameters*/
int check_prime_recursion(int x, int i);

int main()
{
	//Declare variables
	int num1, num2;
	printf("Enter two numbers(intervals): ");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);
	printf("Prime numbers between %d and %d are: ", num1, num2);

	//loop to print primes within the given range
	for(int i=++num1; i<num2; i++)
		if(check_prime_recursion(i,2)==1)
		//if(check_prime(i))
			printf("%d ",i);
	return 0;
}

int check_prime(int x)
{
	int j, prime=1;
	for(j=2; j<x/2; j++)
		if(x%j == 0)
		{
			prime =0;
			break;
		}
	return prime;
}

int check_prime_recursion(int x, int i)
{

	if(x < 2)
		return 0;
	else if (x%i == 0)
		return 0;
	else if (i*i > x)
		return 1;
	return check_prime_recursion(x, i+1);
}

