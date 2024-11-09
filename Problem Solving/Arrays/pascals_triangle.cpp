/**
 * Pascal triangle 
 * Each element at particular index can be computed by using the formula
 * Using Combination -> rowCcol (nCr in general)
 * Belo is the optimized code which will come from the above formula indirectly
 */

/**
 * Link: https://leetcode.com/problems/pascals-triangle/submissions/1447566888/
 */

#include <bits/stdc++.h>
using namespace std;


vector<int> generateRow(int row) {
    vector<int> temp;
    long ans = 1;
    temp.push_back(1);
    for (int col = 1;col < row;col++) {
        ans = ans * (row -  col);
        ans = ans / col;
        temp.push_back(ans);
    }
    return temp;
}
vector<vector<int>> generate(int numRows) {
    // We will be using the formaula -> row C col (C-> COmbination)
    
    vector<vector<int>> result;
    for (int i=1;i<=numRows;i++) {
        result.push_back(generateRow(i));
    }
    return result;
}

int main() {
    vector<vector<int>> v = generate(6);
    for (int i=0;i<v.size();i++) {
        for (int j=0;j<v[i].size();j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}