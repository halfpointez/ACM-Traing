#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		i64 ans = 0, sum = 0;
		cin >> n;
		deque<i64> odd;
		for(int i = 0; i < n; i++) {
			i64 tmp;
			cin >> tmp;
			if(tmp & 1) {odd.push_back(tmp); sum += tmp;}
			else ans += tmp;
		}
		ans += sum;
		sort(odd.begin(), odd.end());
		for(int i = 0; i < odd.size() / 2; i++) {
			ans -= odd[i];
		}
		if(odd.size() == 0) {
			cout << 0 << endl;
		} else 
		cout << ans << endl;
		
	}
	
}