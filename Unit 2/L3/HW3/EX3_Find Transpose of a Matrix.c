/*
 * EX3.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
	float a[100][100], trans[100][100];
	int i=0,j=0,r=0,c=0;
	printf("Enter row & column of matrix: ");
	fflush(stdout);
	scanf("%d %d",&r,&c);

	//Storing matrix a
	for(i=0; i<r;i++)
	{
		for(j=0; j<c;j++)
		{
			printf("Enter element a[%d][%d] :",i,j);
			fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}

	//Displaying the matrix a
	printf("The matrix is\n");
	for(i=0; i<r;i++)
	{
		for(j=0; j<c;j++)
			printf("%0.2f\t",a[i][j]);
		printf("\r\n");
	}

	//Transposing the matrix
	for(i=0; i<r;i++)
		for(j=0; j<c;j++)
				trans[j][i] = a[i][j];

	//Displaying the transpose
	printf("The Transpose matrix is\n");
	for(i=0; i<c;i++)
	{
		for(j=0; j<r;j++)
			printf("%0.2f\t",trans[i][j]);
		printf("\r\n");
	}

	return 0;
}
