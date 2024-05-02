#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph 

int min(int a, int b) {
    return (a<b) ? a:b; 
}

int tsp_dp(int graph[V][V], bool visited[V], int pos, int count) {
    // If all the cities have been visited, return the cost from the current city to starting city 
    if(count == V-1) {
        return graph[pos][0];
    }

    int minCost = INT_MAX;

    // Try to visit every unvisited city
    for(int city = 0; city < V; city++) {
        // If a city is unvisited and there is a direct edge to it from the current city
        if(!visited[city] && graph[pos][city] != 0) {
            visited[city] = true;

            int cost = graph[pos][city] + tsp_dp(graph, visited, city, count+1);

            visited[city] = false; // For Back Tracking 

            // Updated the mininum cost if needed 
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[V];

    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int startingCity = 0;
    visited[startingCity] = true;

    int minCost = tsp_dp(graph, visited, startingCity, 0);

    printf("Minimum cost of the TSP: %d\n", minCost);
    return 0;
}