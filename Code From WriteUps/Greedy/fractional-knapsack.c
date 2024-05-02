#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct 
{
    double value;
    double weight;
    double ratio; // value-to-weight ratio
} Item;

// Compare function for sorting items based on value-to-weight in descending order
int compare(const void *a, const void *b)
{
    double ratio_a = ((Item*)a)->ratio;
    double ratio_b = ((Item*)b)->ratio;

    return ratio_b - ratio_a;
}

double fractionKnapsack(int n, double capacity, Item items[])
{
    int i;
    double totalValue = 0.0;
    double currentWeight = 0.0;
    double remainingWeight;

    // Calculate value-to-weight ratio for each item
    for(i = 0; i < n; i++)
        items[i].ratio = items[i].value / items[i].weight;

    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    // Fill the Knapsack
    for(i = 0; i < n; i++)
    {
        if(currentWeight + items[i].weight <= capacity)
        {
            // Include the whole item
            currentWeight += items[i].weight;
            totalValue +=  items[i].value;
        }
        else
        {
            // Include the fraction of the item
            remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;

            break; // Knapsack is full
        }
    }

    return totalValue;
}

void main()
{
    int n, i;
    double capacity, result;
    Item items[MAX];

    // clrscr();

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of items one by one:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter for item %d: ",i+1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
    }
    
    printf("Enter the capacity of Knapsack: ");
    scanf("%lf", &capacity);

    result = fractionKnapsack(n, capacity, items);

    printf("Maximum value in the Knapsack = %.2f\n", result);

    // getch();
}
