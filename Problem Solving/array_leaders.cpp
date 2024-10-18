/**
 * Array leaders
 * If the elements, right to an element are greater than that element, then it is considered as leader
 * return an array of such leaders
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> leaders;
    int maxi = arr[arr.size()-1];
    leaders.push_back(maxi);
    for(int i=arr.size()-2;i>=0;i--) {
        if (arr[i] >= maxi) {
            maxi = arr[i];
            leaders.push_back(maxi);
        }
    }
    reverse(leaders.begin(), leaders.end()); // or insert a postion '0' using v.insert()
    return leaders;
}
int main() {
    vector<int> nums {16, 17, 4, 3, 5, 2};
    vector<int> r = leaders(nums);
    for(int i:r) {
        cout << i << " ";
    }
    cout << endl;
}