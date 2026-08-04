#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		i64 x, y, z, k, mul = 0, ans = 0;
		cin >> x >> y >> z >> k;
		for(int i = 1; i <= x; i++) {
			for(int j = 1; j <= y; j++) {
				if(k % (i * j) == 0 && (k / (i * j)) <= z) {
					i64 a = i, b = j, c = k / (i * j);
					i64 tmp = (x - a + 1) * (y - b + 1) * (z - c + 1);
					ans = max(tmp, ans); 
				}
			}
		}
		cout << ans << endl;
	}
	
}