#include <bits/stdc++.h>

using namespace std;

// If we update parent during path compression, No need to update size, it remains same (number of node including that)

class DisjointSet {
    vector<int> parent, size;

    public:
    DisjointSet(int n) {
        parent.resize(n+1); // To support for 1- based indexing also
        size.resize(n+1, 1); // initilized with 1, including self node, same for 1- based too
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

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u); // Performing path compression while adding new edge
        int ulp_v = findParent(v); // same as above

        if (ulp_u == ulp_v) // alredy updated these two
            return;
        // lower size node is connected to higher size node, to reduce T.C
        if (size[ulp_u] < size[ulp_v]) { // update parent of ulp_u as ulp_v, and size also include size of u to v
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if (size[ulp_u] >= size[ulp_v]) { // update parent of ulp_v as ulp_u, and size also include size of v to u
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
        // we can remove else if and else, keep only since we have only same in both blocks
    }

    void printSize() {
        for (int i:size) {
            cout << i << " ";
        } cout << endl;
    }
};

int main() {
    DisjointSet ds(7); // number nodes as argument
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findParent(1) == ds.findParent(7)) {
        cout << "Same parent\n";
    }
    else {
        cout << "Not same\n";
    }
    ds.unionBySize(3, 7);
    if (ds.findParent(1) == ds.findParent(7)) {
        cout << "Same parent\n";
    }
    else {
        cout << "Not same\n";
    }
    ds.printSize();

}