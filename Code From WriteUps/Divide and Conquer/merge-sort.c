#include <stdio.h>
#include <conio.h>

void merge(int[],int,int,int);
void mergeSort(int[],int,int);


void main(){
	int arr[]={10,40,20,30,90,50,80,60,70,100};
	printf("Your orignal array is: ");
	for (int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
		
	mergeSort(arr,0,9);
	printf("\nYour Sorted array is: ");
	for (int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
	
	getch();
}

void mergeSort(int x[],int lb,int ub){
	if(lb<ub){
		int mid = (lb+ub)/2;
		mergeSort(x,lb,mid);
		mergeSort(x,mid+1,ub);
		merge(x,lb,mid,ub);
	}
}
// 20 10 30        11 33 12			10 11 12 20 30 33
// i               j                k

void merge(int x[],int lb,int mid,int ub){
	int i,j,k;
	int temp[10];
	i=lb;
	j=mid+1;
	k=0;

	while(i<=mid && j<=ub){
		if(x[i]<x[j]){
			temp[k++]=x[i++];
		}
		else{
			temp[k++]=x[j++];
		}
	}

	while(i<=mid){
		temp[k++]=x[i++];
	}
	while(j<=ub){
		temp[k++]=x[j++];
	}
	for(int i=lb,k=0;i<=ub;i++,k++){
		x[i]=temp[k];
	}
}