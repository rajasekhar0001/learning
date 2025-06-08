#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 500;  // Adjust based on problem size

vector<int> adj[MAX];           // Adjacency list
int capacity[MAX][MAX];         // Capacity matrix

// BFS to find an augmenting path from source to sink
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1); // reset parent array
    parent[s] = s;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

// Edmonds-Karp (BFS-based max flow)
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(MAX);
    int new_flow;

    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


// main function
int main() {
    int mice = 3;
    int holes = 2;

    // reachable[i] = holes mouse i can reach
    vector<vector<int>> reachable = {
        {0, 1},  // Mouse 0 → Hole 0 and 1
        {1},     // Mouse 1 → Hole 1
        {0}      // Mouse 2 → Hole 0
    };

    vector<int> hole_capacity = {2, 1};  // Hole 0 can hold 2 mice, Hole 1 can hold 1

    int S = mice + holes;  // Source node index
    int T = S + 1;         // Sink node index

    // Connect source to mice
    for (int i = 0; i < mice; ++i) {
        adj[S].push_back(i);
        adj[i].push_back(S);
        capacity[S][i] = 1;
    }

    // Connect mice to reachable holes
    for (int i = 0; i < mice; ++i) {
        for (int h : reachable[i]) {
            int holeNode = mice + h;
            adj[i].push_back(holeNode);
            adj[holeNode].push_back(i);
            capacity[i][holeNode] = 1;
        }
    }

    // Connect holes to sink
    for (int i = 0; i < holes; ++i) {
        int holeNode = mice + i;
        adj[holeNode].push_back(T);
        adj[T].push_back(holeNode);
        capacity[holeNode][T] = hole_capacity[i];
    }

    // Run max flow
    int result = maxflow(S, T);
    cout << "Max number of mice saved: " << result << endl;
    return 0;
}
