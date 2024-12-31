/**
 * Fibonacci using
 * 1) Memoization
 * 2) Tabulization
 * 3) If possible, trying to reduce the space complexity be excluding tabulization usage
 */
/**
 * To return the n-th value in Fibonacci sequence
 * Fibonacci sequence: 0 1 1 2 3 5 8 13 21 34 55 ..........
 */

#include <iostream>
#include <vector>

using namespace std;

// T.C: O(2 ^ n)
// S.C: O(n)
int normalRecursionApproach(int n) {
    if (n <= 1) {
        return n;
    }
    return normalRecursionApproach(n-1) + normalRecursionApproach(n-2);
}

// using recursion
// T.C: O(n)
// S.C: O(n) + O(n)
int memoization(int n, vector<int> &dp)  {
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return memoization(n-1, dp) + memoization(n-2, dp);
}

// using tabulization and without using recursion
// T.C: O(n)
// S.C: O(n)
int tabulization(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2;i<= n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// optimised, without using Memoization, tabulization and any extra space
// T.C: O(n)
// S.C: O(1)
int bestSolution(int n) {
    int prev1 = 1;
    int prev2 = 0;
    for (int i=2;i<=n;i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n = 5;
    int nthValue = 0;
    
    // Using normal approch (without using using DP)
    // {
    //     nthValue = normalRecursionApproach(n);
    // }

    // Using Memoization
    // {
    //     vector<int> dp(n+1, -1);
    //     nthValue = memoization(n, dp);
    // }

    // using Tabulization
    // {
    //     nthValue = tabulization(n);
    // }

    // Optimising Space complexity, i.e, without using memoization, tabulization and any extra space
    {
        nthValue = bestSolution(n);
    }


    cout << nthValue << endl;

}