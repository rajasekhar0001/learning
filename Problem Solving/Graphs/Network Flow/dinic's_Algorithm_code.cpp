#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000;  // Max number of nodes
const int INF = 1e9;   // A very large number used as "infinite" capacity

struct Edge {
    int to;     // destination node
    int rev;    // index of reverse edge in adj[to]
    int cap;    // remaining capacity
};

vector<Edge> adj[MAX]; // adjacency list
int level[MAX];        // level of each node (BFS)
int ptr[MAX];          // current edge pointer (DFS)
int source, sink;      // source and sink nodes

// Adds a directed edge with capacity, and its reverse edge with 0 capacity
void addEdge(int u, int v, int cap) {
    adj[u].push_back({v, (int)adj[v].size(), cap});    // forward edge
    adj[v].push_back({u, (int)adj[u].size() - 1, 0});   // reverse edge
}

// Builds the level graph using BFS
bool bfs() {
    fill(level, level + MAX, -1);  // reset level array
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (Edge &e : adj[u]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[sink] != -1;
}

// DFS to send flow through level graph
int sendFlow(int u, int flow) {
    if (u == sink) return flow;

    // If I couldn;t find a path to sink with first edge in adj[u], check next, try all edges till u find a path
    for (int &i = ptr[u]; i < adj[u].size(); ++i) {
        Edge &e = adj[u][i];

        // Only continue if edge is in the level graph and has capacity
        if (e.cap > 0 && level[e.to] == level[u] + 1) { // important condition in Dinic's algo
            int minFlow = min(flow, e.cap);
            int pushed = sendFlow(e.to, minFlow);

            if (pushed > 0) {
                e.cap -= pushed; // updating forwad edge, decrease by pushed
                adj[e.to][e.rev].cap += pushed; // updating reverse edge, increase by pushed
                return pushed; // return  min value in this path
            }
        }
    }

    return 0;
}

// Dinic's algorithm main function
int dinic() {
    int totalFlow = 0;

    // Keep building level graph and sending flows
    while (bfs()) {
        memset(ptr, 0, sizeof(ptr));  // reset DFS pointers

        while (int pushed = sendFlow(source, INF)) {
            totalFlow += pushed;
        }
    }

    return totalFlow;
}

// Example usage
int main() {
    int n = 4; // Number of nodes: 0 to 3
    source = 0;
    sink = 3;

    // Construct the graph
    // Graph:
    // 0 → 1 (capacity 3)
    // 0 → 2 (capacity 2)
    // 1 → 2 (capacity 1)
    // 1 → 3 (capacity 2)
    // 2 → 3 (capacity 4)

    addEdge(0, 1, 3);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 2);
    addEdge(2, 3, 4);

    int maxFlow = dinic();
    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}
