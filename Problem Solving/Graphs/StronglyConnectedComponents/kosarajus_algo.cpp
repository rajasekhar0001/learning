/**
 * 
 * Kosaraju's algorithm -> Used for DIrected Graph only
 * Helps to find Strongly Connected Components : means every node in that component is reachable to each other
 * 
 * 3 steps to be followed:
 * -> step 1: Sort all the nodes according to their finishing time:
        To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in 
        the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and 
        will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing
        all the nodes in the sorted order of their finishing time.
* -> step 2: Reverse all the edges of the entire graph:
        Now, we will create another adjacency list and store the information of the graph in a reversed manner.
* -> step 3: Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
        Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. 
        For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just 
        counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get 
        visited.
    
    Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to 
    store the nodes in some array during each individual DFS call in step 3.
 */

#include <bits/stdc++.h>
using namespace std;

//Position this line where user code will be pasted.
class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& s) {
        visited[node] = true;
        
        for (int adjNode: adj[node]) {
            if (!visited[adjNode]) {
                dfs(adjNode, adj, visited, s);
            }
        }
        
        s.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>& adj, vector<bool> &visited) {
        visited[node] = true;
        
        for (int adjNode: adj[node]) {
            if (!visited[adjNode]) {
                dfs2(adjNode, adj, visited);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // Kosaraju's algorithm for Directed graph only
        int n = adj.size();
        vector<bool> visited(n, false);
        stack<int> s;
        
        // step-1: sort all the nodes according to their finishing time
        for (int i=0;i<n;i++) { // There may be multiple connected components
        // that's why hecking from every node
            if (!visited[i]) 
                dfs(i, adj, visited, s);
        }
        
        // step-2: Reverse graph (reverse edges)
        vector<vector<int>> reversedAdj(n);
        for (int i=0;i<n;i++) {
            visited[i] = false; // clearing the visited array
            for (int j = 0;j<adj[i].size();j++) {
                reversedAdj[adj[i][j]].push_back(i);
            }
        }
        
        // step-3: Do dfs again for all the unvisited vertices in stack
        int sccCount = 0;
        while(!s.empty()) {
            int node = s.top();
            if (!visited[node]) {
                dfs2(node, reversedAdj, visited);
                sccCount++;
            }
            s.pop();
        }
        
        return sccCount;
    }
};

int main() {
    
}