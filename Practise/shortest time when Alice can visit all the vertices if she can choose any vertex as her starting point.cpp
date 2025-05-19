/**
 * Steps to solve problem if graph is acyclic
 * maxDistance = 0;
 * Step 1: Find the farthest node from an arbitrary starting node (node 0)
 * maxDistance = 0
 *  Step 2: Find the farthest node from the previously found farthest node
 * 
 *  ==> maxDistance that we find from step 2is the diameter of the tree
 * Step 3: The shortest time to visit all vertices is twice the total weight of the tree minus the diameter
 *  ==> diameter is the maxDistance
 */

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int &farthestNode, int &maxDistance, int currentDistance) {
    visited[node] = true;
    if (currentDistance > maxDistance) {
        maxDistance = currentDistance;
        farthestNode = node;
    }
    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            dfs(neighbor.first, adj, visited, farthestNode, maxDistance, currentDistance + neighbor.second);
        }
    }
}

int shortestTime(int N, vector<vector<int>> &Edges) {
    vector<vector<pair<int, int>>> adj(N);
    for (auto &edge : Edges) {
        adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        adj[edge[1] - 1].push_back({edge[0] - 1, edge[2]});
    }

    // Step 1: Find the farthest node from an arbitrary starting node (node 0)
    vector<bool> visited(N, false);
    int farthestNode = 0, maxDistance = 0;
    dfs(0, adj, visited, farthestNode, maxDistance, 0);

    // Step 2: Find the farthest node from the previously found farthest node
    fill(visited.begin(), visited.end(), false);
    maxDistance = 0;
    dfs(farthestNode, adj, visited, farthestNode, maxDistance, 0);

    // Step 3: The shortest time to visit all vertices is twice the total weight of the tree minus the diameter
    int totalWeight = 0;
    for (auto &edge : Edges) {
        totalWeight += edge[2];
    }

    return 2 * totalWeight - maxDistance; // maxDistance is the diameter
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> Edges(N - 1, vector<int>(3));
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> Edges[i][j];
        }
    }

    cout << shortestTime(N, Edges) << endl;
    return 0;
}
