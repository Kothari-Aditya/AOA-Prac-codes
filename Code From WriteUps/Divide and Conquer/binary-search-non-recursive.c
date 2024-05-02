#include <stdio.h>
#include <conio.h>
#define MAX 10

int binarySearch(int x[],int n,int key)
{
    int low,mid,high;
    low = 0;
    high = n-1;

    while(low<=high)
    {   mid=(low+high)/2;
        if(x[mid]==key)
            return mid;

        if(x[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

void main()
{
    int key,index,i;
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    clrscr();
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\nEnter the key you want to search: ");
    scanf("%d",&key);

    index = binarySearch(arr,10,key);
    if(index<0)
        printf("\n%d element not found",key);
    else
        printf("\n%d element found at %d index",key,index);

    getch();

}