#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		vector<int> v(n);
		for (int i=0;i<n;i++) {
			cin >> arr[i];
			v[i] = arr[i];
		}

        for (int i=0;i<n;i++) {
            cout << arr[i] << "  ";
        }cout << endl;
        cout <<"-----------"<< endl;
		sort(v.begin(), v.end());
		vector<int> r;
		int i=0;
		int j = 0;

        for (int i:v) {
            cout << i << " " ;
        }cout << endl << endl;
		while (i < n && j < n) {
			if ((v[j] >= arr[i]) && (v[j] % arr[i] == 0)) {
                cout << j << " " << i << endl;
				r.push_back(v[j]);
                // j++;
                i++;
			}
			else {
				j++;
			}
			// i++;
		}
		for (int i:r ) {
			cout << i << " ";
		}cout << endl;
	}
}