#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> ans(n);
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= 4; j++) {
				char c;
				cin >> c;
				if(c == '#') {
					ans[i] = j;
			
				}
			}
		}
		reverse(ans.begin(), ans.end());
		for(auto &i:ans) cout << i << ' ';
		cout << endl;
	}
	
}