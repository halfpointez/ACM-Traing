#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n';

i64 check(int a, vector<i64> &b, int a_last, int m) {
	int l = 1, r = m, mid;
	while (l < r) {
		mid = l + ((r - l) >> 1);
		i64 tmp = b[mid] - a;
		if(tmp >= a_last) {
			r = mid;
		} else if(tmp < a_last) {
			l = mid + 1;
		}
	}

	return (b[l] - a);	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<i64> a(n + 1); vector<i64> b(m + 1); 
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= m; i++) cin >> b[i];
		sort(b.begin() + 1, b.end());

		for(int i = 1; i <= n; i++) {
			if(i == 1) {
				a[i] = min(a[i], b[1] - a[i]); continue;
			}

			i64 tmp = check(a[i], b, a[i - 1], m);
			i64 MAX= max(a[i], tmp), MIN = min(a[i], tmp);

			if(MIN >= a[i - 1]) a[i] = MIN;
			else if(MAX >= a[i - 1]) a[i] = MAX;
			else goto bad;
		}
		
		cout << "YES" << endl; continue;
		bad: cout << "NO" << endl; continue;

	}
	
}