#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, l ,r;
		cin >> m >> n >> l >> r;
		int diff = m - n;
		if(diff - r > 0) {
			diff -= r;
			r = 0;
		} else if(diff - r <= 0) {
			r -= diff;
			diff = 0;
		}

		if(diff - abs(l) > 0) {
			diff -= abs(l);
			l = 0;
		} else if(diff - abs(l) <= 0) {
			l += diff;
			diff = 0;
		}

		cout << l << ' ' << r << endl;
	}
	
}