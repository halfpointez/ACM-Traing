#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	i64 T;
	cin >> T;
	i64 n, k;
	while (T--) {
		cin >> n >> k;
		vector<i64> a(n);
		for(auto &i:a) cin >> i;
		sort(a.begin(), a.end());
		i64 MAX_len = 1, l = 0, r = 0;
		for(r = 0; r < n; r++) {
			if(r > 0 && abs(a[r] - a[r - 1]) > k) {
				l = r;
			}
			MAX_len = max(MAX_len, r - l + 1);
		}
		cout << n - MAX_len << endl;
	}
	
	
}