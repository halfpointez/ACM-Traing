#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int m, a, b, c;
		cin >> m >> a >> b >> c;
		int h1 = m, h2 = m, ans = 0;
		if(a >= h1) {
			ans += h1;
			h1 = 0;
		} else {
			ans += a;
			h1 -= a;
		}

		if(b >= h2) {
			ans += h2;
			h2 = 0;
		} else {
			ans += b;
			h2 -= b;
		}

		if(c >= h2 + h1) {
			ans += (h1 + h2);
		} else {
			ans += c;
		}
		cout << ans << endl;
	}
	
}