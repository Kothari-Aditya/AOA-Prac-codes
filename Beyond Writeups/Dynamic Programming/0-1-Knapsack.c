#include <stdio.h>

// Function to find maximum of two numbers

int max(int a, int b){
    return (a>b) ? a:b;
}

// Recursive function to solve 0/1 knapsack
int knapsack(int w, int wt[], int val[], int n) {
    // Base case: If either the knapsack is full or there are no items left
    if(n == 0 || w == 0)
        return 0;

    // If the weight of nth item is more than the capacity of the knapsack
    // Then this item cannot be included in the optimal solution
    if(wt[n-1] > w)
        return knapsack(w, wt, val, n-1);
    
    // Return the maximum of two cases:
    // 1. The nth item is included 
    // 2. The nth item is not included 
    return max(val[n-1] + knapsack(w-wt[n-1], wt, val, n-1), knapsack(w, wt, val, n-1));
}

// Driver program to test the above function
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value that can be obtained is %d\n", knapsack(w, wt, val, n));
}