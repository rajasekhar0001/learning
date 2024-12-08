/**
 * Find majort elemests which appears more than n/3 times
 * Optimised
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findElements(vector<int> majority,vector<int> arr, int n) {
    int cnt1 = 0, cnt2 = 0;
    for (int i:arr) {
        if (majority[0] == i) cnt1++;
        if (majority[1] == i) cnt2++;
    }
    vector<int> r;
    if (cnt1 > n) {
        r.push_back(majority[0]);
    }
    if (cnt2 > n)
        r.push_back(majority[1]);
    return r;
}

vector<int> findMajorityElement(vector<int> arr, int n) {
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = 0;
    int ele2 = 0;
    for (int i: arr) {
        if (cnt1 == 0 && ele2 != i) {
            cnt1=1;
            ele1 = i;
        }
        else if (cnt2 == 0 && ele1 != i) {
            cnt2 = 1;
            ele2 = i;
        }
        else if (ele1 == i) {
            cnt1++;
        }
        else if (ele2 == i) {
            cnt2++;
        }
        else {
            cnt1--; cnt2--;
        }
    }
    return findElements({ele1, ele2}, arr, n/3);
}



int main() {
    vector<int> arr = {2, 1, 1, 2, 1, 2, 1, 2, 4};

    int n = arr.size();
    vector<int> res = findMajorityElement(arr, n);
    for (int i: res) {
        cout << i << " ";
    } cout << endl;
}