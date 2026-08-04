#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(auto &i:a) cin >> i; sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		int i = 0; int ans = 0;
		while (i < n) {
			int len = 1;
			while (a[i] + 1 == a[i + 1] && i < n - 1) {
				len++;
				i++;
			}
			ans = max(len, ans);
			i++;
		}
		cout << ans << endl;
		
	}
	
}