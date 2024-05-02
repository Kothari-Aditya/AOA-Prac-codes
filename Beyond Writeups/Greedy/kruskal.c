#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent, rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void unionSets(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void kruskalMST(struct Edge edges[], int V, int E);

int main()
{
    // Example graph represented by its edges
    int V = 4; // Number of vertices
    int E = 5; // Number of Edges
    struct Edge edges[] = {
    // src dest weight
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskalMST(edges, V, E);

    return 0;
}

//  Find set of an element i
int find(struct Subset subsets[], int i) 
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); // path compression

    return subsets[i].parent;
}

// Union of two sets X and Y
void unionSets(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    printf("\nxroot = %d and yroot = %d", xroot, yroot);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparsion function used by qsort to sort edges based on their weights
// const -> to ensure programmer that this function is not modifying value of that variable
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight; 
} 

void printSubset(struct Subset *subsets, int V)
{
    int i;
    printf("Node \t Parent \t Rank");
    for(int i = 0; i < V; i++) 
    {
        printf("\n%d \t %d \t\t %d",  i, subsets[i].parent, subsets[i].rank);
    }
    printf("\n");
}

//  Kruskal's algorithm to find minimum spanning tree
void kruskalMST(struct Edge edges[], int V, int E)
{
    // Allocate memory for subsets
    struct Subset *subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize the result of MST
    struct Edge result[3];

    int i, x, y, index;
    // Initialize each subset as a single element set with rank 0
    for(i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    // Sort the edges in the non-decreasing order by weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    printf("\nInitial subsets:\n");
    printSubset(subsets, V);
    index = 0; // Index to add to the result
    // Number of edges to be added to the MST
    for(i = 0; i < E && index < V - 1; i++)
    {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i];

        printf("\nSelected Edges for Processing: %d -> %d", nextEdge.src, nextEdge.dest);
        x = find(subsets, nextEdge.src);
        y = find(subsets, nextEdge.dest);

        printf("\nSelected Edge Group: %d -> %d", nextEdge.src, x);
        printf("\nSelected Edge Group: %d -> %d", nextEdge.dest, y);

        // If including this edge doesn't cause a cycle, add it to the MST
        if(x != y)
        {
            result[index++] = nextEdge;
            unionSets(subsets, x, y);
        }

        printf("\nSubsets After Pass:\n");
        printSubset(subsets, V);
        printf("\n");
    }
    
    // Print the result MST
        printf("Edges in the Minimum Spanning Tree:\n");
        for(i = 0; i < V - 1; i++)
            printf("(%d, %d) -> %d\n", result[i].src, result[i].dest, result[i].weight);

     // Free allocated memory
        free(subsets);
}