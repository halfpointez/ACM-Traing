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
		vector<i64> a(n);
		for(auto &i:a) cin >> i;
		i64 sum = 0, MAX = 0, other = 0, cnt = 0;
		for(int i = 0; i < n; i++) {
			sum += a[i];
			MAX = max(a[i], MAX);
			other = sum - MAX;
			if(other == MAX) cnt++;
		}

		cout << cnt << endl;
	}
	

}