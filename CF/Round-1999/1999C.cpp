#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s, m;
		cin >> n >> s >> m;
		vector<pair<int, int>> a(n);
		for(auto &i:a) cin >> i.first >> i.second;
		int MAX = 0;
		for(int i = 0; i < n; i++) {
			if(i == 0) {
				MAX = max(a[i].first, MAX);
			} else MAX = max((a[i].first - a[i - 1].second), MAX);
		}
		MAX = max(m - a.back().second, MAX);
		if(MAX >= s) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}