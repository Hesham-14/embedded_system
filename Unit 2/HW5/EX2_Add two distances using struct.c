/*
 * EX2.c
 *
 *  Created on: Dec 31, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

struct Sdistance
{
	int m_feet;
	float m_inch;
};

struct Sdistance read_func(char n[]);
struct Sdistance add_func(struct Sdistance d1, struct Sdistance d2);
void print_func(struct Sdistance d);

int main()
{
	struct Sdistance d1, d2, sum;
	d1 = read_func("1st");
	d2 = read_func("2st");
	sum = add_func(d1, d2);
	print_func(sum);

	return 0;
}


// definition for read_func to read data
struct Sdistance read_func(char n[])
{
	struct Sdistance d;
	printf("Enter information for %s distance\n", n);

	//read distance in feet
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d", &d.m_feet);

	//read distance in inch
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f", &d.m_inch);

	return d;
}

struct Sdistance add_func(struct Sdistance d1, struct Sdistance d2)
{
	struct Sdistance d;
	d.m_feet = d1.m_feet + d2.m_feet;
	d.m_inch = d1.m_inch + d2.m_inch;
	while(d.m_inch >= 12)
	{
		d.m_feet++;
		d.m_inch -= 12;
	}

	return d;
}

void print_func(struct Sdistance d)
{
	printf("Sum of distances = %d' %.2f\"", d.m_feet, d.m_inch);
}
