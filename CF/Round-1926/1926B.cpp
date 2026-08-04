#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<char>> mp(n, vector<char>(n));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> mp[i][j];
			}
		}
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(mp[i][j] == '1') {
					int x = i, y = j;
					while (x < n && mp[x][j] == '1') {
						cnt1++;
						x++;
					}
					while (y < n && mp[i][y] == '1') {
						cnt2++;
						y++;
					}
					if(cnt1 == cnt2) {
						cout << "SQUARE" << endl;
					} else cout << "TRIANGLE" << endl;
					goto a;
				}
			}
		}
		a:
	}
	
}