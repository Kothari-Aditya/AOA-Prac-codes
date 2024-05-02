#include <stdio.h>
#include <limits.h>

#define clrscr(); system('cls');
#define V 5 // Number of vertices in the graph

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index, v;

    for(v = 0; v < V; v++ )
        if(!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    int i;
    printf("Vertex \t Distance from the source\n");
    for(i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int i, count, v;
    int dist[V]; // Holds the shortest distance from src to vertex i
    int sptSet[V]; // is set to 1 if vertex i in included in the shortest path set

    for(i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;

    for(count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for(v = 0; v < V; v++)
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

void main()
{
    /*
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 },
    };
    */

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6 ,0, 0},
    };

    dijkstra(graph, 0);
}
