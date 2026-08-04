#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt_a = 0, cnt_b = 0;
		for(auto &i:s) {
			if(i == 'A') cnt_a++;
			else cnt_b++;
		}
		if(cnt_a > cnt_b) cout << 'A' << endl;
		else cout << 'B' << endl;
	}
	
}