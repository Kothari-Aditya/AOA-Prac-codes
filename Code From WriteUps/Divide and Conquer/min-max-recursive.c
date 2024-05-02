#include<stdio.h>
#include<conio.h>

int getMin (int num1, int num2) {return num1<num2 ? num1 : num2;}
int getMax (int num1, int num2) {return num1>num2 ? num1 : num2;}


// void findMinAndMax(int arr[], int low, int high, int *min, int *max) {
//     *min = *max = arr[low]; // Initialize min and max with the first element

//     for (int i = low + 1; i <= high; i++) {
//         if (arr[i] < *min) {
//             *min = arr[i];
//         } else if (arr[i] > *max) {
//             *max = arr[i];
//         }
//     } // non recursive
// }
void findMinAndMax(int arr[], int low, int high, int *min, int *max)
{
    int mid, leftMin, leftMax, rightMin, rightMax;
    if(low==high)
    {
        // If there is only one element in the array.
        *min = *max = arr[low];
        return;
    }

    if(high == low+1)
    {
        // If there are two elements in the array
        *min = getMin(arr[low], arr[high]);
        *max = getMax(arr[low], arr[high]);
        return;
    }

    // If there are more than two elements, divide the array into two halves
    mid = (low+high)/2;

    findMinAndMax(arr, low, mid, &leftMin, &leftMax);
    findMinAndMax(arr, mid+1, high, &rightMin, &rightMax);

    *min = getMin(leftMin, rightMin);
    *max = getMax(leftMax, rightMax);
}

void main()
{
    int arr[] = {3, 5, 1, 8, 4, 2, 69, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min, max;

    findMinAndMax(arr, 0, n-1, &min, &max);

    printf("Minimum Element: %d\n",min);
    printf("Maximum Element: %d\n",max);
}