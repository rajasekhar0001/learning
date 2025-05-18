#include <bits/stdc++.h>
using namespace std;
int rows[] = {0, 0, 1, -1};
    int cols[] = {1, -1, 0, 0};
void dfs(int i, int j, int n, int m, vector<vector<char>>& matrix, vector<vector<bool>> & visited, vector<vector<int>> &components, int compId, int &stars) {
    visited[i][j] = true;
    components[i][j] = compId;
    if (matrix[i][j] == '*') {
        stars++;
    }
    
    for (int k=0;k<4;k++) {
        int r = rows[k] + i;
        int c  = cols[k] + j;
        if (r >= 0 && r < n && c>=0 && c< m && !visited[r][c] && matrix[r][c] != '#') {
            dfs(r, c, n, m, matrix, visited, components, compId, stars);
        }
    }
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> matrix(n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			char ch;
			cin >> ch;
			matrix[i].push_back(ch);
		}
	}
 
	//
	vector<vector<bool>> visited(n, vector<bool>(m, false)); // false -> unvisited
	queue<pair<pair<int, int>, pair<int, int>>> q; // {row, col};

    vector<vector<int>> components(n, vector<int>(m, 0));
    map<int, int> ct;
 
	int maxStars = 0;
	int compId = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (!visited[i][j] && matrix[i][j] != '#') {
                compId++;
                int stars = 0;
                dfs(i, j, n, m, matrix, visited, components, compId, stars);
                ct[compId] = stars; 
                // maxStars = 0
			}
		}
	}
for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
        if (matrix[i][j] == '#') {
            set<int> s;
            for (int k=0;k<4;k++) {
                int r = i + rows[k];
                int c = j + cols[k];
                if (r >= 0 && r<n && c>=0 && c< m && matrix[r][c] != '#') {
                    s.insert(components[r][c]); 
                }
            }
            int cc = 0;
            cout << i << " : " << j << endl;
            cout << "st: ";
            for (auto it: s) {
                if (it == 0) continue; // ✅ This avoids invalid lookups
                cout << it << " ";
                cc += ct[it];
            }  
            cout << endl;
            maxStars = max(maxStars, cc);
        }
    }
    cout << endl;
}
        cout << "components sze: " << ct.size() << endl;

    for (auto it: ct) {
        cout << it.first << " : " << it.second << endl;
    }
    if (ct.size() == 1)  {
        cout << ct[1] << endl;
    }
    else 
        cout << maxStars << endl;
 
	// return maxStars;
 
 
}