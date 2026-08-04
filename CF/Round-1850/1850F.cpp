#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
using i64 = long long;
using i128 = __int128_t;
int main() {
	int T;
	cin >> T;
	while (T--) {
		map<int, int> cnt;
		int n;
		cin >> n;
		vector<int> dis(n + 1, 0);
		vector<int> a(n);
		vector<int> pos;
		for(auto &i:a) {
			cin >> i;
			cnt[i]++;
		}

		for(auto &i:cnt) {
			int curr = i.second;
			int curr_0 = i.first;
			int base = curr_0;
			while (curr_0 <= n) {
				dis[curr_0] += curr;
				curr_0 += base;
			}
		}

		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans = max(ans, dis[i]);
		}
		cout << ans << endl;
	}
	
}