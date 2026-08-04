#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
using i128 = __int128_t;
bool is_c(char c) {
	if(c == 'b' || c == 'c' || c== 'd') return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector <bool> pos(n, 0)
		vector<bool> chosen(n, 0);
		for(int i = 0; i < n; i++) {
			if(is_c(s[i])) {
				if(i + 1 < n && !is_c(s[i + 1])) {
					pos[i + 1] = 1;
					chosen[i] = 1;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(is_c(s[i]) && chosen[i] == 0) {
				pos[i - 1] = 0, pos[i] = 1;
			}
		}
		for(int i = 0; i < n; i++) {
			cout << s[i];
			if(pos[i] == 1 && i != n - 1) cout << '.';
		}
		cout << endl;
	}
	
	
}