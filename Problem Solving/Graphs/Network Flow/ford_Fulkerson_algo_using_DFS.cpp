#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

#define V 6

// DFS function to find a path from s to t in residual graph.
// Returns true if path exists and fills parent[] to store the path.
bool dfs(int rGraph[V][V], int s, int t, bool visited[], int parent[])
{
    visited[s] = true;
    if (s == t)
        return true;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && rGraph[s][v] > 0)
        {
            parent[v] = s;
            if (dfs(rGraph, v, t, visited, parent))
                return true;
        }
    }
    return false;
}

// Returns the maximum flow from s to t in the given graph using DFS
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;

    while (true)
    {
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        // If no augmenting path found using DFS, break
        if (!dfs(rGraph, s, t, visited, parent))
            break;

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

    return max_flow;
}

int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0} };

    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
