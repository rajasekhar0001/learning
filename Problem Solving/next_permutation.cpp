/**
 * Next permutation means next greater permutation, if we consider teh vector as string or number(group of digits)
 * Brute Force Method:
 * * Generate all possible permutations
 * * Search input from all possible permutations
 * * print the permutation that is present just after the give permutation
 * * Complexity:  O(n)*O(n!) + O(n*n) + O(n)
 * 
 * Better approach:
 * * Use the STL to get next greater permutation
 * * method is std::next_permutation(v.begin(), v.end()); // it will replace the vector with next permutation
 * 
 *
 * * 
 */

/**
 *  Optimal Approach:
 * * Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
        For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
        To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
        If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
        So, in this case, we will reverse the whole array and will return it as our answer.
 * * If a break-point exists:
        Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
        Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
 */

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    // next_permutation(nums.begin(), nums.end());
    int len = nums.size();
    int breakVal  = len;
    for(int i=len-2;i>=0;i--) {
        if(nums[i] < nums[i+1]) {
            breakVal = i;
            break;
        }
    }
    if(breakVal == len) {
        reverse(nums.begin(), nums.end()); // present in algorithm header
        return;
    }

    for(int i=len-1;i>breakVal;i--) {
        if(nums[i] > nums[breakVal]) {
            int t = nums[i];
            nums[i] = nums[breakVal];
            nums[breakVal] = t;
            break;
        }
    }
    
    reverse(nums.begin()+breakVal+1, nums.end());
    // In place of reverse(), sort can also be used
}

int main() {
    vector<int> nums{5, 1, 4, 3, 2, 0, 0};
    nextPermutation(nums);
    for(int i:nums) {
        cout <<i << "  ";
    }
    cout << endl;
}