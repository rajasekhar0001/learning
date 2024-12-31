/**
 * DFS TRaversal (Using Recursion) 
 * Adjacency list creation and DFS traversal
 * 
 * S.C => O(N) + O(N) + O(N) = O(N)
 * T.C: => O(N)+O(2E)  [ total degree of a graph is 2E (Edges)]
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfsTraversalFunction(int node, vector<vector<int>> &adjacencyList, vector<int> &visited, vector<int> &dfsTraversal) {
    dfsTraversal.push_back(node);
        
    for (int i: adjacencyList[node]) {
        if (!visited[i]) {
            visited[i] = 1;
            dfsTraversalFunction(i, adjacencyList, visited, dfsTraversal);
        }
    }
}

void printAdjacencyList(vector<vector<int>> &list, int n) {
    for (int i=1;i<=n;i++) { // since 1- based indexing
        for (int ele: list[i]) {
            cout << ele <<  " ";
        } cout << endl;
    }
}

void printVector(vector<int> &arr) {
    for (int i: arr) {
        cout << i << " ";
    } cout << endl;
}

int main() {
    // Given input
    int n = 8;  // NUmber of nodes
    int m = 7;  // Number of edges
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 5}, {2, 6}, {3, 4}, {3, 7}, {4, 8}};

    // Using 1- based indexing
    vector<vector<int>> adjacencyList(n+1);
    for (int i=0;i<n;i++) {
        adjacencyList[edges[i].first].push_back(edges[i].second);
        adjacencyList[edges[i].second].push_back(edges[i].first); // Skip this line in case of directed graph
    }

    cout << "Adjacency List : " << endl;
    printAdjacencyList(adjacencyList, n); 
    cout << endl;

    /** BFS traversal logic start */

    vector<int> dfsTraversal; // To store the traversal Result
    vector<int> visited(n+1, 0);
    visited[1] = 1;
    int start = 1; // since using 1- based indexing
    dfsTraversalFunction(start, adjacencyList, visited, dfsTraversal);

    printVector(dfsTraversal);
}