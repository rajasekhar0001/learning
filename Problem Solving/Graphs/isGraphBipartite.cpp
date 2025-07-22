// Graph must be coloured with 2 colors, no two adjacents have the same color
// Consider 0 and 1 as two colors
/** Addition info
    --> If a graph has odd length cycle or not having cycle -> Graph is not Bi-partite
    --> Else Graph is bi-partite

*/

class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int> & visited, int color) {
        visited[node] = color;
        
        // visit adjacent nodes
        for (int adjNode: graph[node]) {
            // if adjacent node is not visited
            if (visited[adjNode] == -1) {
                if(!dfs(adjNode, graph, visited, 1 - color)) return false;
            }
            // If the adjcent nodes has the same color, return false
            else if(visited[adjNode] == color) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Graph must be coloured with 2 colors, no two adjacents have the same color
        // Consider 0 and 1 as two colors
        /** Addition info
            --> If a graph has odd length cycle or not having cycle -> Graph is not Bi-partite
            --> Else Graph is bi-partite

        */
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i=0;i<n;i++) {
            if (visited[i] == -1) {
                if(!dfs(i, graph, visited, 0)) return false;
            }
        }
        return true;
    }
};