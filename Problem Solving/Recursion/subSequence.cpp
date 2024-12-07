/**
 * Subarray and Substring are different from subsequence
 * A subarray or substring will always be contiguous, but a subsequence need not be contiguous. 
    That is, subsequences are not required to occupy consecutive positions within the original sequences
 * Sub Sequence: A subsequence of an array/ string is a set of numbers that aren't necessarily adjacent in the array
    but that are in the same order as they appear in the array/string
 */

/**
 * Below code is about to generate all subsequences
 */
#include <bits/stdc++.h>
using namespace std;

void printS(vector<int> arr, int n, int index, vector<int> ds,int s, int sum) {
    // cout << "index : " << index << endl;
    /**
     * Leaf nodes in each path is checking for some draw tree
     * To get claroty why used (index == n)
     */
    if(index == n) { // makes sense
        if(sum == s) {
            for(int i:ds) {
                cout << i << " ";
            } cout << endl;
        } 
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    printS(arr, n, index+1, ds, s, sum);
    s -= arr[index];
    ds.pop_back();
    printS(arr, n, index+1, ds, s, sum);
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};
    int n = 4;
    int sum = 2;
    vector<int> ds;
    printS(arr, n, 0, ds,0, sum);

    return 0;
}