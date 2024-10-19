/**
 * Brute force: create some other matrix and copy in correct way
 * Optimal: Transpose and reverse each roe
 */

/**
 * https://leetcode.com/problems/rotate-image/
 */

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // // Brute Force solution
    // int m = matrix.size()-1;
    // int n = matrix[0].size()-1;
    // vector<vector<int>> rotate = matrix;
    // for (int i=0;i<=m;i++) {
    //     for (int j=0;j<=n;j++) {
    //         matrix[i][j] = rotate[n-j][i];
    //     }
    // }

    // Optimal
    int m = matrix.size();
    int n = m;
    for (int i=0;i<m;i++) {
        for (int j=0;j<i;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i=0;i<m;i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a- b;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for (int i=0;i<matrix.size();i++) {
        for (int j =0;j < matrix[0].size();j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
    