#include <stdio.h>
#include <conio.h>
#define MAX 10

int binarySearch(int x[],int low,int high,int key)
{
    int mid;

    if(low>high)
        return -1; //Stops recursion if key not found

    mid = (low+high)/2;

    if(x[mid]==key)
        return mid;

    if(x[mid]>key)
        return binarySearch(x,low,mid-1,key);

    if(x[mid]<key)
        return binarySearch(x,mid+1,high,key);
}

void main()
{
    int key,index,i;
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\nEnter the key you want to search: ");
    scanf("%d",&key);

    index = binarySearch(arr,0,9,key);
    if(index<0)
        printf("\n%d element not found",key);
    else
        printf("\n%d element found at %d index",key,index);


}