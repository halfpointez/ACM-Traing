#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool odd= 0, even = 0;
		vector<i64> a(n); 
		for(auto &i:a) {
			cin >> i;
			if(i & 1) odd = 1;
			else even = 1;
		}
		if(odd && even) sort(a.begin(), a.end());
		for(auto &i:a) cout << i << ' ';
		cout << endl;
	}
	
}