/**
 * Make Zeros
 * 
 * 
 * In the previous approach, the time complexity is minimal as the traversal of a matrix takes at least 
 * O(N*M)(where N = row and M = column). In this approach, we can just improve the space complexity. So,
 *  instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given
 *  matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try
 *  to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve 
 * this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix 
 * will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable 
 * will serve the purpose of the col array.
 */

/*
 *  https://leetcode.com/problems/set-matrix-zeroes/
 */
#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix, int r, int c) {
    for (int i=0;i < matrix[0].size();i++) {
        matrix[r][i] = 0;
    }
    for (int i=0;i<matrix.size();i++) {
        matrix[i][c] = 0;
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    // Better approach
    // vector <int> rows;
    // vector<int> cols;
    // for(int i=0;i < matrix.size();i++) {
    //     for(int j=0;j<matrix[i].size();j++) {
    //         if (matrix[i][j] == 0) {
    //             rows.push_back(i);
    //             cols.push_back(j);
    //             continue;
    //         }
    //     }
    // }
    // cout << rows.size() << "  " << cols.size() << endl;
    // for (int i=0;i < rows.size();i++) {
    //     cout << rows[i] <<"  " << cols[i] << endl;
    //     setZeros(matrix, rows[i], cols[i]);
    // }

    // Optimal approach
    int col0 =1;
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[0].size();j++) {
            if (matrix[i][j] == 0) {
                
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
                
                matrix[i][0] = 0;
            }
        }
    }
cout << "col0  : " << col0 << endl;
    // Make zeros
    for (int i=1;i<matrix.size();i++) {
        for (int j=1;j<matrix[0].size();j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int i=1;i<matrix[0].size();i++)
            matrix[0][i] = 0;
    }
    if (col0 == 0)
    {
        for (int i=0;i<matrix.size();i++) 
            matrix[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i=0;i<matrix.size();i++) {
        for (int j =0;j < matrix[0].size();j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}