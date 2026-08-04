#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int MIN = 1e6;
		int sum = 0;
		bool j = 0;
		if(s[0] == 'B' || s.back() == 'B') {
			j = 1;
		}
		for(int i = 0; i < s.size();) {
			char cur = s[i];
			int len = 0;
			if(cur == 'A') {
				while (cur == 'A') {
					len++;
					i++;
					cur = s[i];
				}	
				sum += len, MIN = min(MIN, len);
			} else {
				int len_b = 0;
				while (cur == 'B') {
					len_b++;
					i++;
					cur = s[i];
				}
				if(len_b >= 2) j = 1;
			}
		}
		if(j) cout << sum << endl;
		else cout << sum - MIN << endl;
		
	}
	
}