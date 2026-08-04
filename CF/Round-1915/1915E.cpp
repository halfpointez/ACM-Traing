#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		if(n % 2 == 0) {
			a[0] = n / 2 + 1;
			b[n - 1] = 1;
			int a_s = n, b_s = 2;
			for(int i = 1; i < n; i++) {
				a[i] = a_s;
				a_s--;
			}
			for(int i = 0; i < n - 1; i++) {
				b[i] = b_s;
				b_s++;
			}
			for(int i = 0; i < n; i++) {
				cout << a[i] << ' ' << b[i] << ' ';
			}
			cout << endl;
		}

	}
	

}