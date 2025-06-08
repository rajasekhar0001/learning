#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

// Scaling algorithm steps:
// 1. Identify the maximum capacity in the graph.
// 2. Start with the largest power of 2 less than or equal to the maximum capacity.
// 3. Use BFS to find paths with residual capacity >= delta.
// 4. Use DFS to send flow along these paths.
// 5. when BFS fails, Reduce delta by half and repeat until delta becomes 0.
// Note: Scaling improves efficiency by prioritizing higher-capacity edges first.

using namespace std;

// Number of vertices in given graph
#define V 6

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph with capacity >= delta. Also fills parent[] to store the path */
bool bfsWithScaling(int rGraph[V][V], int s, int t, int parent[], int delta)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] >= delta)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// Returns the maximum flow from s to t in the given graph using scaling
int scalingFordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    // Find the maximum capacity in the graph
    int max_capacity = 0;
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            max_capacity = max(max_capacity, graph[u][v]);

    // Start with the largest power of 2 less than or equal to max_capacity
    int delta = 1;
    while (delta <= max_capacity)
        delta *= 2;
    delta /= 2;

    while (delta > 0)
    {
        while (bfsWithScaling(rGraph, s, t, parent, delta))
        {
            int path_flow = INT_MAX;
            for (v = t; v != s; v = parent[v])
            {
                u = parent[v];
                path_flow = min(path_flow, rGraph[u][v]);
            }

            for (v = t; v != s; v = parent[v])
            {
                u = parent[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
            }

            max_flow += path_flow;
        }

        delta /= 2;
    }

    return max_flow;
}

// Driver program to test above functions
int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The maximum possible flow using scaling is " << scalingFordFulkerson(graph, 0, 5);

    return 0;
}
