#include <bits/stdc++.h>
using namespace std;
#define int long long
const int X = 2e5 + 5, Y = 2;
bool axis[X][Y] = {0};
signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y, axis[x][y] = 1;
		}
		int ans = 0;
		for(int i = 0; i <= n; i++) {
			if(axis[i][0] == 1 && axis[i][1] == 1) ans += n - 2;
			if(axis[i][0] && axis[i + 1][1] && axis[i + 2][0]) ans ++;
			if(axis[i][1] && axis[i + 1][0] && axis[i + 2][1]) ans ++;
		}
		cout << ans << endl;

		for(int i = 0; i <= n; i++) {
			axis[i][0] = 0, axis[i][1] = 0;
		}
	}
	return 0;
}