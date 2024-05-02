#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct
{
    double value;
    double weight;
    double ratio; // value to weight ratio
}Item;

int compare(const void *a, const void *b)
{
    double ratio_a = ((Item*)a)->ratio;
    double ratio_b = ((Item*)b)->ratio;

    return ratio_b - ratio_a;
}

double fractionalKnapsack(int n, double capacity, Item items[])
{
    int i;
    double totalValue = 0.0;
    double currentWeight = 0.0;
    double remainingWeight;

    // Calc value to weight ratio
    for(i = 0; i < n; i++)
        items[i].ratio = items[i].value / items[i].weight;

    // Sort in descending order
    qsort(items, n , sizeof(Item), compare);

    // Fill knapsack
    for(i = 0; i < n; i++)
    {
        if(currentWeight + items[i].weight <= capacity)
            //Whole item
            currentWeight += items[i].weight, totalValue += items[i].value;
        else
        {
            // fraction of an item
            remainingWeight = capacity - currentWeight, totalValue += items[i].ratio * remainingWeight;
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

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of items one by one:\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter for item %d: ", i+1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
    }
    printf("Enter the capacity of KnapSack: ");
    scanf("%lf", &capacity);

    result = fractionalKnapsack(n, capacity, items);

    printf("Maximum Value in the knapsack = %.2f\n", result);
}