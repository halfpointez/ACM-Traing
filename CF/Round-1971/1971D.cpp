#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int t1 = 0, t2 = 0, time = 0;

		bool jud = 0;
		for(int i = 0; i < s.size() - 1; i++) {
			if(s[i] != s[i + 1] && jud == 0 && s[i] == '0' && s[i + 1] == '1') {
				jud = 1;
			} else if(s[i] != s[i + 1]) {
				t1++;
			}

		}

		jud = 0;

		cout << t1 + 1 << endl;
	}
	
}
	