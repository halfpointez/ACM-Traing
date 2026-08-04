#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
using i64 = long long;
using i128 = __int128_t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		i64 n, c;
		cin >> n >> c;
		i128 curr_sum = 0;
		i64 a_2 = 0, a_sum = 0;
		for(int i = 0; i < n; i++) {
			i64 k;
			cin >> k;
			a_2 += (k * k), a_sum += k;
		}
		i64 l = 0, r = 1e9;
		while (l < r) {
			i64 mid = l + ((r - l) >> 1) + 1;
			curr_sum = (i128)a_2 + (i128)2 * a_sum * mid * 2 + (i128)2 * mid * 2 * mid * n;
			if(curr_sum > c) {
				r = mid - 1;
			} else if(curr_sum <= c) {
				l = mid;
			}
		}
		cout << l << endl;
		
	}
	
}