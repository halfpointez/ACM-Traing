#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(3 * n + 1); 
		for(int i = 1; i <= 3 * n; i++) a[i] = i;
		int end = 3 * n;
		for(int i = 1; i <= n; i++) {
			cout << a[i] << ' ' << a[end] << ' ' << a[end - 1] << ' ';
			end -= 2;
		}
		cout << endl;
	}
	
} 