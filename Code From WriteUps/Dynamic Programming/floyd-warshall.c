#include<stdio.h>
#include<limits.h>

// Function to find the minimum of two numbers
int min(int a, int b)
{
    return (a<b) ? a:b;
}

// Function to perform Floyd-Warshall Algorithm
void floydWarshall(int graph[4][4], int V)
{
    int dist[V][V];

    // Initialize the distance martrix with the given graph
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    }

    // Update the distance matrix by considering all vertices as intermediate
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j then updated the distance
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] =  dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    printf("Shortest distances between every pair of vertices: \n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INT_MAX)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    // Example graph represented as an adjacency matrix
    // int graph[4][4] = {
    //  {0, 5, INT_MAX, 10},
    //  {INT_MAX, 0, 3, INT_MAX},
    //  {INT_MAX, INT_MAX, 0, 1},
    //  {INT_MAX, INT_MAX, INT_MAX, 0}
    // };
    int graph[4][4] = {
        {0, 5, 4, 1},
        {5, 0, 2, 3},
        {4, 2, 0, 6},
        {1, 3, 6, 0}
    };
    // Number of vertices in the graph
    int V = 4;
    // Call the floydWarshall Algorithm function
    floydWarshall(graph, V);
    return 0;
}
