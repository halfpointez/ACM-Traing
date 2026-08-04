#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, k, ans = 0;
		cin >> x >> y >> k;
		int nx = (x + k - 1) / k, ny = (y + k - 1) / k;
		if(nx > ny) {
			ans = (x / k + (x % k ? 1 : 0)) * 2  - 1;
		} else if(nx <= ny) {
			ans = (y / k + (y % k ? 1 : 0)) * 2;
		}
		cout << ans << endl;
	}
	
}