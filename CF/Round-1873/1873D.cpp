#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = 0;
		for(int i = 0; i < n;) {
			if(s[i] == 'B') {
				int j = i;
				ans++;
				for(j = i; j < n && j < i + k; j++) {
					s[j] = 'W';
				}
				i = j;
			} else i++;
		}
		cout << ans << endl;
	}
	
}