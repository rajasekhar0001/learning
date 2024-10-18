#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> nums) {
    int len = nums.size();
    vector<int> result(len ,  0);
    int pos = 0;
    int neg = 1;
    for(int i=0;i<len;i++) {
        if(nums[i] > 0) {
            result[pos] = nums[i];
            pos+=2;
        }
        else {
            result[neg] = nums[i];
            neg+=2;
        }

    }
    for(int i:result) {
        cout << i <<  "  ";
    }
    cout << endl;
    return result;
}

int main() {
    // rearrangeArray({3, 1, -2, -5, 2, -4});
    rearrangeArray({1, 2, -1, -2});
}