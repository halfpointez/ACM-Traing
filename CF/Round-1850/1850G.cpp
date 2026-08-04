#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		map<int, int> X, Y, _1, _minus_1;
		int n; cin >> n;
		vector<pair<int, int>> axis(n + 1);
		for(int i = 1; i <= n; i++) {
			int tmp_x, tmp_y;
			cin >> tmp_x >> tmp_y;
			axis[i].first = tmp_x, axis[i].second = tmp_y;
			X[tmp_x]++, Y[tmp_y]++;
			_1[tmp_x - tmp_y]++, _minus_1[tmp_x + tmp_y]++;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += X[axis[i].first]; ans += Y[axis[i].second];
			ans += _1[axis[i].first - axis[i].second];
			ans += _minus_1[axis[i].first + axis[i].second];
			ans -= 4;
		}

		cout << ans << endl;
	}
	

}