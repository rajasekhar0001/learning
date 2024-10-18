/**
 * Longest_subarray_length_with_sum_k (only positives including 0)
 * Logic using hashing can be used for POSITIVES and NEGATIVES as well
 * 
 */

#include <bits/stdc++.h>

using namespace std;


// Using two pointer approacg can be used with positive numbers including 0
int getMaxSubArrayLength(vector<int> &arr, int k) {
    int vectorLength = arr.size();

    long sum = 0;
    int maxLen = 0;
    int left = 0, right = 0;
    while (right < vectorLength) {  // O(n)

        sum += arr[right];
        while (left < right && sum > k) {   // O(k) -> hardly n times for the all iterations
            sum -= arr[left];
            left--;
        }
        cout << "sum : " << sum << endl;
        if (sum == k)  {
            maxLen = max(maxLen, right - left + 1);
            cout << "right-left+1 : " << right - left + 1 << endl; 
            cout << "maxLen : " << maxLen << "  sum :  " << sum << endl;
        }
        
        right++;


    }
    return maxLen;
    
}
// T.C-> O(n + n) -> O(2n) -> O(n)


// using hashing (map) can be used for negatives as well
int getMaxSubArrayLengthMap(vector<int> &arr, int k) {
    map<int, int> preSum;
    long sum = 0;
    int maxLen = 0;
    for (int i=0;i<arr.size();i++){
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }

        int rem = sum - k;
        if (preSum.find(rem) != preSum.end())
            maxLen = max(maxLen, i - preSum[rem]);
        
        if (preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }
    return maxLen;
}
//T.C -> O(n)

int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        long sum = 0;
        int maxLen = 0;
        map<int, int> preSumMap;
        for (int i=0;i<N;i++) {
            sum += A[i];
            
            if (sum == K)
                maxLen = max(maxLen, i+1);
            
            int rem = sum - K;
            
            if (preSumMap.find(rem) != preSumMap.end()){
                maxLen = max(maxLen, i- preSumMap[rem]);
            }
            
            if (preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
            
        }
        return maxLen;
    } 

int main() {
    int  list[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    int k = 10;
    cout << lenOfLongSubarr(list,17, 15) << endl;

}