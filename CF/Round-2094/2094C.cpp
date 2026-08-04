#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
	cin >> n;
	vector<vector<int>> mp(n, vector<int>(n));
	vector<int> ans(2 * n);
	int cnt = 1;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if(i == 0 || j == n - 1) {
				ans[cnt] = mp[i][j];
 				cnt++;
				sum += mp[i][j];
			}
		}
	}
	ans[0] = ((1 + 2 * n) * 2 * n) / 2 - sum;
	for(auto &i:ans) cout << i << ' ';
	cout << endl;
	}
	
	
}