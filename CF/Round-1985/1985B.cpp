#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, ans;
		cin >> n;
		int MAX = 0;
		int down;
		for(int i = 2; i <= n; i++) {
			down = n / i;
			int sum = (down  + 1) * down * i / 2;
			if(sum > MAX) {
				ans = i;
				MAX = sum;
			}
		}
		cout << ans << endl;
	}
	
}