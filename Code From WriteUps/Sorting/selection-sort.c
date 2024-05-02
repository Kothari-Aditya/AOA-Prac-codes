#include <stdio.h>
#include <conio.h>
#define MAX 10

void Selection(int x[],int n)
{
    int i,j,large,index;
    for(i=0;i<n-1;i++)
    {
        large = x[0];
        index=0;
        for(j=1;j<n-i;j++)
        {
            if(x[j]>large) // x[j] < large
            {
                large=x[j];
                index=j;
            }
        }
        x[index]=x[n-1-i];
        x[n-1-i]=large;
    }
}

void main()
{
    int i;
    int x[]={20,10,30,50,40,90,80,70,60,100};
    printf("Your Orignal Array: ");
    for(i=0;i<10;i++)
        printf("%d ",x[i]);

    Selection(x,10);

    printf("\nYour Sorted Array: ");
    for(i=0;i<10;i++)
        printf("%d ",x[i]);
    getch();
}