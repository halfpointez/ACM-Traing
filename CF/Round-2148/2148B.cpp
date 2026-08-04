#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector<int> a(n), b(m);
		for(auto &i:a) cin >> i; for(auto &i:b) cin >> i;
		cout << n + m << endl;
	}
	
}