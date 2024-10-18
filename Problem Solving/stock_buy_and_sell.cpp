/**
 * Brute Force Approach and Optimal approach
 * Optimal Approach 
 * * We will linearly travel the array. We can maintain a minimum from the start of the array and 
 * * compare it with every element of the array, if it is greater than the minimum then take the difference
 * * and maintain it in max, otherwise update the minimum
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices) {
    // Brute Force approach
    // int maxi = 0;
    // for(int i=0;i<prices.size();i++) {
    //     for(int j=i+1;j<prices.size();j++) {
    //         if (prices[i] < prices[j])
    //             maxi = max(prices[j] - prices[i], maxi);
    //     }
    // }
    // return maxi;

    // Optimal approach
    int mini=INT_MAX;
    int sum = 0;
    for(int i=0;i<prices.size();i++) {
        if (mini > prices[i])
            mini = prices[i];
        else
        {
            if((prices[i]-mini) > sum)
                sum = prices[i]-mini;
        }
    }
    return sum;
}

int main() {
    cout << maxProfit({7,1,5,3,6,4}) << endl;
}