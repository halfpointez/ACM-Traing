#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
using i64 = long long;
using i128 = __int128_t;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		i64 sum = 0;
		while (n--) {
			i64 tmp;
			cin >> tmp;
			sum += tmp;
		}
		i64 a = sqrt(sum);
		if(a * a == sum) {cout << "YES" << endl;}
		else cout << "NO" << endl;
		
	}
	
}