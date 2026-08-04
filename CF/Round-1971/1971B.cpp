#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int sum = 0;
		int pos1 = -1, pos2 = -1;
		vector<int> pos(26, -1);
		for(int i = 0; i < s.size(); i++) {
			if(pos[s[i] - 'a'] == -1) {
				pos[s[i] - 'a'] = i;
				sum++;
			}
			if(sum >= 2) {
				for(int j = 0; j < 26; j++) {
					if(pos[j] != -1 && pos1 == -1) pos1 = pos[j];
					else if(pos[j] != -1 && pos2 == -1) pos2 = pos[j];
				}
				break;
			}
		}
		if(pos1 != -1) {
			cout << "YES" << endl;
			swap(s[pos1], s[pos2]);
			cout << s << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}
	
} 