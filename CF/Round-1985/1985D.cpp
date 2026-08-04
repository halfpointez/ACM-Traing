#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> mp(n, vector<char>(m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> mp[i][j];
			}
		}

		int x, y;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(mp[i][j] == '#') {
					
					int k = i, len = 0;
					while(k < n && mp[k][j] == '#') {
						k++;
						len++;
					}

					x = i + len / 2;
					y = j;
					goto flag;
				}
			}
		}

		flag:
		cout << x + 1 << ' ' << y + 1 << endl;
	}
	
}