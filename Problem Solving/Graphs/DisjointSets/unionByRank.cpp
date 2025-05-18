#include <bits/stdc++.h>

using namespace std;

// If we update parent during path compression we cant't update rank (like height)
// To avoid that problem, we use Union By Size

class DisjointSet {
    vector<int> parent, rank;
    // rank is like height

    public:
    DisjointSet(int n) {
        parent.resize(n+1); // To support for 1- based indexing also
        rank.resize(n+1, 0); // rank will be 0 at start (its like height), same for 1- based too
        for (int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) { // performing path compression too
        if (u == parent[u]) {
            return u;
        }

        return parent[u] = findParent(parent[u]); // since we are replacing parent, its path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u); // Performing path compression while adding new edge
        int ulp_v = findParent(v); // same as above

        if (ulp_u == ulp_v)
            return;
        // lower rank node is connected to higher rank node, to reduce T.C
        if (rank[ulp_u] < rank[ulp_v]) { // update parent of pu as pv, not required to update rank
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) { // update parent of pu as pv, not required to update rank
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};

int main() {
    DisjointSet ds(7); // number nodes as argument
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findParent(1) == ds.findParent(7)) {
        cout << "Same parent\n";
    }
    else {
        cout << "Not same\n";
    }
    ds.unionByRank(3, 7);
    if (ds.findParent(1) == ds.findParent(7)) {
        cout << "Same parent\n";
    }
    else {
        cout << "Not same\n";
    }

}