#include <stdio.h>
#include <limits.h>

#define N 8
#define INF INT_MAX

int min(int a, int b) {
    return (a < b) ? a : b;
}

int shortestDist(int graph[N][N]) {
    int dist[N];
    int i, j;

    // Set the distance to the destination node (N-1) as 0
    dist[N - 1] = 0;

    // Calculate shortest path for the rest of the nodes
    for (i = N - 2; i >= 0; i--) {
        // Initialize distance from i to destination (N-1)
        dist[i] = INF;

        // Check all nodes of next stages to find shortest distance from i to N-1
        for (j = i; j < N; j++) {
            // Reject if no edge exists
            if (graph[i][j] == INF)
                continue;

            // Apply equation to distance to target through j and compare with minimum distance so far
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }

    return dist[0];
}

int main() {
    // Graph stored in the form of an adjacency matrix
    int graph[N][N] = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    printf("Shortest distance from vertex 0 to vertex %d: %d\n", N - 1, shortestDist(graph));
    return 0;
}
