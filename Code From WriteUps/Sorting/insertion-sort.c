#include<stdio.h>
#include<conio.h>
#define MAX 10

void insert(int x[], int n)
{
    int i, numToBeInserted, j;

    for(i=1;i<n;i++)
    {
        numToBeInserted = x[i];

        for(j=i-1; j>=0 && x[j]>numToBeInserted ; j--) // < for descending sort
        {
            x[j+1] = x[j];
            x[j] = numToBeInserted;
        }
    }
}

void main()
{
    int n, x[MAX],i;
    //clrscr();
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements one by one: ");
    for (i = 0; i<n ; i++)
    {
        scanf("%d",&x[i]);
    }

    printf("\nYour original array: ");
    for (i = 0; i<n ; i++)
    {
        printf("%d ",x[i]);
    }

    insert(x,n);

    printf("\nYour sorted array: ");
    for (i = 0; i<n ; i++)
    {
        printf("%d ",x[i]);
    }
}