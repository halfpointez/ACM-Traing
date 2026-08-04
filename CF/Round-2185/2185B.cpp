#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, MAX = 0;
		cin >> n;
		int T = n;
		while (T--) {
			int tmp;
			cin >> tmp;
			MAX = max(MAX, tmp);
		}
		cout << MAX * n << endl;
	}
	
}