#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define MAX 100

int dp[MAX][MAX];
int splitPoints[MAX][MAX];

void printMatrix(int n){
   int i, j;
   printf("Cost Matrix:\n");
    for(i=1; i<n; i++) {
        for(j=1; j<n; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("Matrix For k Values: \n");
    for(i=1; i<n; i++) {
        for(j=1; j<n; j++)
        {
            printf("%d ", splitPoints[i][j]);
        }
        printf("\n");
    }

}

// Function to find the minimum of two numbers
int min(int a, int b)
{
    return (a<b) ? a:b;
}

// Function for matrix chain multiplication
int matrixChainMultiplication(int* p, int i, int j)
{
    int k, a, b;
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (k = i; k < j; k++)
    {
        int newValue = matrixChainMultiplication(p, i, k)+ matrixChainMultiplication(p, k + 1, j)+ p[i - 1] * p[k] * p[j];
        dp[i][j] = min(
            dp[i][j], matrixChainMultiplication(p, i, k)
                     + matrixChainMultiplication(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);

        if (dp[i][j] == newValue)
            splitPoints[i][j] = k;
    }


    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMultiplication(p, i, j);
}

// Driver Code
int main()
{
    int arr[] = {10, 100, 5, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, 0, sizeof(dp)); // Fastest method to create an array in c , MUP instruction
    memset(splitPoints, 0, sizeof(splitPoints));
    int minNumberOfMultiplications = MatrixChainOrder(arr, n);
    printMatrix(n);
    printf("Minimum number of multiplications is: %d", minNumberOfMultiplications);
}