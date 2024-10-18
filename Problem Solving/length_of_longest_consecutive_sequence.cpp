/**
 * Length of longest consecutive sequence
 */

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> nums, int target) {
    for(int i:nums) {
        if(target == i)
            return true;
    }
    return false;
}

// Brute Force
// int longestConsecutive(vector<int>& nums) {
//     int maxLen = 0;
//     for(int i:nums) {
//         int cnt = 0;
//         int val = i;
//         while (linearSearch(nums, val) == true) {
//             cnt++;
//             val++;
//         }
//         maxLen = max(maxLen, cnt);
//     }
//     return maxLen;
// }
// // O(n)*O(n) -> O(n^2)

// Better Aproach (Using sorting)
// int longestConsecutive(vector<int>& nums) {
//     int len = nums.size();
//     int maxLen = 0;
//     sort(nums.begin(), nums.end());
//     int cnt = 1;
//     int lastElement = INT_MIN;
//     for(int i=0;i<len;i++) {
//         if (nums[i]-1 == lastElement) {
//             cnt++;
//         }
//         else if(nums[i] != lastElement) {
//             cnt = 1;
//         }
//         lastElement = nums[i];
//         maxLen = max(maxLen, cnt);
//     }
//     return maxLen;
// }
// // O(nlogn) + O(n)

// Optimal Approach using Set()
int longestConsecutive(vector<int>& nums) { 
    if(nums.size() == 0)
        return 0;   
    unordered_set<int> set1;
    for(int i=0;i<nums.size();i++) {
        set1.insert(nums[i]);
    }
    int maxLen = 1;
    int cnt=1;
    for(auto i:set1) {
        // cout << (i) << endl;
        if (set1.find(i-1) == set1.end()) {
            cnt = 1;
            int x = i;
            while (set1.find(x+1) != set1.end()) {
                cnt++;
                x = x+1;
            }
            maxLen = max(maxLen, cnt);
        }
    }
    return maxLen;
}
// O(n) + O(n) + O(n)

int main() {
    vector<int> nums {100, 200, 1, 3, 2, 4};
    cout << longestConsecutive(nums) << endl;
}