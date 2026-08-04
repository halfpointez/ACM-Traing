#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		i64 ans = 0, low = 0, times = 10;
		while(n) {
			i64 cur = n % 10; //当前位
			i64 x = n / 10; //当前位前的数
			ans += x * 45 * times / 10; //当前位经过的循环和
			ans += times / 10 * (cur - 1) * (cur) / 2;
			ans += cur * (low + 1);
			n /= 10;
			low += (times/10) * cur;
			times *= 10;
			
		}
		cout << ans << endl;
		

	}
	
}