#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		i64 n, k;
		cin >> n >> k;
		vector<i64> a(n);
		for(auto &i:a) cin >> i;
		vector<i64> tree(n);
		for(auto &i:tree) cin >> i;
		i64 l = 0, r = 0, sum = 0, ans = 0;
		for(r = 0; r < n; r++) {
			if(r != 0 && tree[r - 1] % tree[r] != 0) {
				l = r;
				sum = 0;
			}
			sum += a[r];
			while(sum > k) {
				sum -= a[l];
				l++;
			}
			ans = max(ans, r - l + 1);
			
		}
		cout << ans << endl;
	}
}