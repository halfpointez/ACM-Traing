#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<i64> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		i64 ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				ans = max(ans, a[i] ^ a[j]);
			}
		}
		cout << ans << endl;
	}
	
}