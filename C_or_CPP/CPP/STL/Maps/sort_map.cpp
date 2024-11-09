/**
 * map
 * Sort map based on value
 * * since map can't be sorted using sort, used vector with pair type as an element
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> m = {{'a',2}, {'x', 7}, {'b', 3}};
    vector<pair<char, int>> v {m.begin(), m.end()};
    
    for(auto it:v) {
        cout << it.first << "  " << it.second << endl;
    }
    auto cmp = [] (pair<char, int> a, pair<char, int> b) {
      return a.second < b.second;  
    };
    
    sort(v.begin(), v.end(), cmp);
    cout << "AFter sort\n";
    for(auto it:v) {
        cout << it.first << "  " << it.second << endl;
    }
}