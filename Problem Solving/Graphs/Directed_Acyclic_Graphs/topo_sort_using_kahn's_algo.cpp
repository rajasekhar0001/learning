/**
 * Topological sort using BFS
 * 
 * 
 * Input: V = 6, E = 6


Output: 5, 4, 2, 3, 1, 0
Explanation: A graph may have multiple topological sortings. 
The result is one of them. The necessary conditions 
for the ordering are:
According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.

The above result satisfies all the necessary conditions. 
[4, 5, 2, 3, 1, 0] is also one such topological sorting 
that satisfies all the conditions.

 */

/**
 Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges 
 and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an 
edge between node u and v(u -> v), node u appears before v in that ordering.

Now, let's understand Why topological sort only exists in DAG:

Case 1 (If the edges are undirected): If there is an undirected edge between node u and v, it signifies that there is an edge
 from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological
  sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. 
  So, it is only possible for directed edges.

Case 2: (If the directed graph contains a cycle): The following directed graph contains a cycle:

 If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must
 appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as 
 there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
        // which stores the elements which has in degree of each node as '0'
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
