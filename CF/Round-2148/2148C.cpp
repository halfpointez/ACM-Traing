#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		int cur = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			if(i == 0) {
				if(cur == b[i]) {
					if(a[i] & 1) {
						ans += a[i] - 1;
					} else ans += a[i];
				}
				else {
					if(a[i] & 1) {
						ans += a[i];
					} else ans += a[i] - 1;
				}
			} else {
				if(cur == b[i]) {
					if((a[i] - a[i - 1]) & 1) {
						ans += a[i] - a[i - 1] - 1;
					} else ans += a[i] - a[i - 1];
				}
				else {
					if((a[i] - a[i - 1]) & 1) {
						ans += a[i] - a[i - 1];
					} else ans += a[i] - a[i - 1] - 1;
				}
			}
			cur = b[i];
		}

		ans += (m - a[n - 1]);

		cout << ans << endl;
	}
	
}