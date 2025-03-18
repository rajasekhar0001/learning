/**
 * Bitwise AND of numbers between range [l, r]
 * shortcut
 * problem: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */

#include <bits/stdc++.h>
using namespace std;


 int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {  
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}


int main() {
    int left = 10;
    int right = 20;
    cout << rangeBitwiseAnd(left, right) << endl;
    

    left = 5, right = 7;
    cout << rangeBitwiseAnd(left, right) << endl;
}