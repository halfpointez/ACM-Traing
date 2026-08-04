#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int mask = (1 << 31) - 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		vector<i64> a(n + 1);
		map<int, int> cnt;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		for(auto &i:cnt) {
			while(i.second > 0) {
				if(cnt[(i.first ^ mask)] != 0) {
					cnt[(i.first ^ mask)]--;
				}
				i.second--;
				ans++;
			}
		}
		cout << ans << endl;
	}
	
}