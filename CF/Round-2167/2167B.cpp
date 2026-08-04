#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> cnt1(26, 0), cnt2(26, 0);
		for(int i = 0; i < n; i++) {
			cnt1[s1[i] - 'a']++; cnt2[s2[i] - 'a']++;
		}
		bool j = 0;
		for(int i = 0; i < 26; i++) {
			if(cnt1[i] != cnt2[i]) {
				cout << "NO" << endl;
				j = 1;
				break;
			}
		}
		if(!j) cout << "YES" << endl;
	}
	
}