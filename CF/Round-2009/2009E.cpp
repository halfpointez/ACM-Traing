#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		i64 n, k;
		cin >> n >> k;
		i64 ans = 0, first = k, last = n + k - 1;
		i64 sum = (first + last) * n / 2;
		i64 l = first, r = last;
		while (l < r) {
			i64 x = l + ((r - l) >> 1) + 1;
			i64 pre = (first + x) * (x - first + 1);
			if(pre - sum > 0)  {
				r = x - 1;
			} else if(pre - sum <= 0) {
				l = x;
			}
		}
		ans = min(abs((first + l) * (l - first + 1) - sum),abs((first + l + 1) * ((l + 1) - first + 1)) - sum);
		cout << ans << endl;
	}
	
	

}