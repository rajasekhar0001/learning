/**
 * Longest continuous subarray sum
 * and the longest subarray
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i =0; i<len;i++) {
        if (sum == 0)
            start = i;
        sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        // If sum < 0, discard the sum
        if (sum < 0)
            sum = 0;
        cout <<"start: " << ansStart << endl;
        cout << "end: " << ansEnd << endl;
    }
    // cout << 
    for(int i= ansStart;i<=ansEnd;i++) {
        cout << nums[i] << "  ";
    }
    cout << endl;
    return maxSum;
}

int main() {
    vector<int> nums {-9, -2, -2, -7, -9};
    cout << maxSubArray(nums) << endl;
}
