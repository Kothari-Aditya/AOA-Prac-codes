#include <stdio.h>
#include <stdbool.h>

void printSubsetUtil(int set[], int subset[], int n, int sum, int currIndex, int currSum)
{
    if (currSum == sum) {
        printf("{");
        bool isFirstElementPrinted = false;
        for (int i = 0; i < currIndex; i++) {
            if (subset[i] != -1) {
                if (isFirstElementPrinted) {
                    printf(", ");
                }
                printf("%d", subset[i]);
                isFirstElementPrinted = true;
            }
        }
        printf("}\n");
        return;  // Add return here to stop further recursion
    }

    if (currIndex == n || currSum > sum)
        return;

    // Include the current element and backtrack
    subset[currIndex] = set[currIndex];
    printSubsetUtil(set, subset, n, sum, currIndex + 1, currSum + set[currIndex]);

    // Exclude the current element and backtrack
    subset[currIndex] = -1; // Mark the current element as excluded
    printSubsetUtil(set, subset, n, sum, currIndex + 1, currSum);
}

void printSubsets(int set[], int n, int sum)
{
    int subset[n];
    for (int i = 0; i < n; i++) {
        subset[i] = -1; // Initialize subset array with -1
    }
    printSubsetUtil(set, subset, n, sum, 0, 0);
}

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    if (subset[n][sum]) {
        printf("Subsets with sum %d:\n", sum);
        printSubsets(set, n, sum);
        return true;
    }

    return false;
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 7;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");
    return 0;
}