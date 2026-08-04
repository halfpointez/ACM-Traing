#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
char a = '#', b = '.';
void S(char &c) {
	if(c == a) c = b;
	else if(c == b) c = a;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0, cnt1 = 0;
		cin >> n;
		vector<vector<char>> mp(2 * n, vector<char>(2 * n));
		char s = a, c = s;
		for(int i = 0; i < 2 * n; i++) {
			if(cnt == 2) {
				S(s);
				cnt = 0;
			}
			cnt++;
			c = s;
			for(int j = 0; j < 2 * n; j++) {
				if(cnt1 == 2) {
					S(c);
					cnt1 = 0;
				}
				mp[i][j] = c;
				cnt1++;
			}
			cnt1 = 0;
		}

		for(int i = 0; i < 2 * n; i++) {
			for(int j = 0; j < 2 * n; j++) {
				cout << mp[i][j];
				if(j == 2 * n - 1) cout << endl;
			}
		}
	}
	
	
}