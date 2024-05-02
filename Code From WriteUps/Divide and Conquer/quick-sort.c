#include <stdio.h>
#include <conio.h>
#define MAX 10
#define clrscr() \
    ;            \
    system("cls"); // in vs code

void quickSort(int[], int, int);
int partition(int[], int, int);

void main()
{
    int n, i, x[MAX];
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the numbers one by one: ");
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    printf("\nYour Orignal Array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);

    quickSort(x, 0, n - 1);

    printf("\nYour Sorted Array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
    getch();
}

void quickSort(int x[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int j = partition(x, lowerBound, upperBound);
        quickSort(x, lowerBound, j - 1);
        quickSort(x, j + 1, upperBound);
    }
}

int partition(int x[], int lowerBound, int upperBound)
{
    int pivot, up, down, temp;
    pivot = x[lowerBound];
    down = lowerBound;
    up = upperBound;

    while (down < up)
    {
        while (x[down] <= pivot && down <= upperBound)
            down++;
        while (x[up] > pivot)
            up--;
        if (down < up)
        {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lowerBound] = x[up];
    x[up] = pivot;

    return up;
}