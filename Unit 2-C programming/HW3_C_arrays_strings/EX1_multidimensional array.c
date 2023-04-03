/*
 * EX1.c
 *
 *  Created on: Dec 14, 2022
 *      Author: hesham mohamed
 */

#include <stdio.h>

int main()
{
    float a[2][2], b[2][2],s[2][2];
    int i,j;
    printf("Enter the elements of 1st matrix\n");
    for(i=0; i<2;i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter a[%d][%d]: ",i,j);
            fflush(stdout);
            scanf("%f",&a[i][j]);
        }
    }
    printf("\r\nEnter the elements of 1st matrix\n");
    for(i=0; i<2;i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter b[%d][%d]: ",i,j);
            fflush(stdout);
            scanf("%f",&b[i][j]);
        }
    }
    printf("\r\nThe sum of them\n");
    for(i=0; i<2;i++)
    {
        for(j=0; j<2; j++)
        {
            s[i][j] = a[i][j]+b[i][j];
            printf("%0.1f \t",s[i][j]);
        }
        printf("\r\n");
    }

    return 0;
}
