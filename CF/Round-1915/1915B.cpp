#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int t;
	cin >> t;
	while (t--) {
		vector<int> cnt(3, 0);
		vector<vector<char>> mp(3, vector<char>(3));
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> mp[i][j];
				if(mp[i][j] != '?') cnt[mp[i][j] - 'A']++;
			}
		}	
		for(int i = 0; i < 3; i++) {
			if(cnt[i] < 3) {
				char a = 'A' + i;
				cout << a << endl;
				break;
			}
		}
	}
	
}