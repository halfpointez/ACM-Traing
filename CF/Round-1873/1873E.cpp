#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	int T;
	cin >> T;
	while (T--) {
		i64 n, x, water_sum = 0;
		cin >> n >> x;
		vector<i64> a(n);
		for(auto &i:a) cin >> i;
		i64 l = 0, r = 2e9;
		while (l < r) {
			water_sum = 0;
			i64 mid = l + ((r - l) >> 1) + 1;
			for(auto &i:a) {
				if(mid - i <= 0) continue;
				water_sum += (mid - i);
				if(water_sum > x) break;
			}
			if(water_sum > x) {
				r = mid - 1;
			} else if(water_sum <= x) {
				l = mid;
			}
		}
		cout << l << endl;
		
	}
	
}