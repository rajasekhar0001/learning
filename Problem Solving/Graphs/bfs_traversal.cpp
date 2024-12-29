/**
 * BFS TRaversal (Using Queue) -> SImilar to Level wise Traversal
 * Adjacency list creation and BFS traversal
 * 
 * S.C => O(N) + O(N) + O(N) = O(N)
 * T.C: => O(N)+O(2E)  [ total degree of a graph is 2E (Edges)]
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsTraversalFunction(int &n, vector<vector<int>> &adjacencyList, vector<int> &bfsTraversal) {
    vector<int> visitedArray(n+1, 0);
    // Consider givenVal as starting value
    int givenVal = 1; // consided this value is in level 0
    queue<int> que;
    que.push(givenVal);
    visitedArray[givenVal] = 1;
    while (!que.empty()) {
        int val = que.front();
        bfsTraversal.push_back(val);
        for (int i: adjacencyList[val]) {
            if (visitedArray[i] == 0) {
                que.push(i);
                // Mark node value as visited
                visitedArray[i] = 1;
            }
        }
        que.pop();
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
    int n = 9;  // NUmber of nodes
    int m = 9;  // Number of edges
    vector<pair<int, int>> edges = {{1, 2}, {1, 6}, {2, 3}, {2, 4}, {6, 7}, {6, 9}, {4, 5}, {7, 8}, {5, 8}};

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

    vector<int> bfsTraversal; // To store the traversal Result
    bfsTraversalFunction(n, adjacencyList, bfsTraversal);

    printVector(bfsTraversal);
}