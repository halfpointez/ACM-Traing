#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<pair<char, int>> a, b;

		for(int i = 0; i < s1.size();) {
			char curr = s1[i]; int cnt = 0;
			while (i < s1.size() && s1[i] == curr) {
				i++;
				cnt++;
			}
			a.push_back({curr ,cnt});
		}

		for(int i = 0; i < s2.size();) {
			char curr = s2[i]; int cnt = 0;
			while (i < s2.size() && s2[i] == curr) {
				i++;
				cnt++;
			}
			b.push_back({curr, cnt});
		}
		bool j = 0;
		
		for(int i = 0; i < a.size(); i++) {
			if(a.size() != b.size()) {
				cout << "NO" << endl;
				j = 1;
				break;
			}
			if(a[i].second > b[i].second || abs(a[i].second - b[i].second) > a[i].second || a[i].first != b[i].first) {
				cout << "NO" << endl; j = 1;
				break;
			}
		}
		if(!j) cout << "YES" << endl;


	}
	
}