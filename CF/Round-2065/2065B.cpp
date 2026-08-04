#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool j = 0;
		for(int i = 0; i < s.size() - 1; i++) {
			if(s[i] == s[i + 1]) {
				cout << 1 << endl;
				j = 1;
				break;
			} 
		}
		if(!j) cout << s.size() << endl;
	}
	
}