/**
 * Spiral Matrix
 * ONly one solution
 * 
 * In this approach, we will be using four loops to print all four sides of the matrix.

        1st loop: This will print the elements from left to right.

        2nd loop: This will print the elements from top to bottom.

        3rd loop: This will print the elements from right to left.

        4th loop: This will print the elements from bottom to top.
 */

/**
 * https://leetcode.com/problems/spiral-matrix/
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> order;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    int left = 0;
    int top = 0;
    while (top <= bottom && left <= right) {
        for (int i=left;i<=right;i++) {
            order.push_back(matrix[top][i]);
        }
        top++;
        for (int i=top;i<=bottom;i++) {
            order.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i=right;i>=left;i--) {
                order.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <=right) {
            for(int i=bottom;i>=top;i--) {
                order.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return order;
    
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> order = spiralOrder(matrix);
    for (int i : order) {
        cout << i << " " ;
    }
    cout << endl;
}