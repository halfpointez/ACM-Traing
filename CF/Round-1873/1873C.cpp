#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	
	while (T--) {
		vector<vector<char>> mp(10, vector<char>(10));
		int ans = 0;
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				cin >> mp[i][j];
				if(mp[i][j] == 'X') {
					int a = 9, b = 0, dis = 0;
					while(dis <= 4) {
						if(i <= a - dis && i >= b + dis && j == b + dis) {
							ans += dis + 1;
							break;
						} else if(i <= a - dis && i >= b + dis && j == a - dis) {
							ans += dis + 1;
							break;
						} else if(j <= a - dis && j >= b + dis && i == a - dis) {
							ans += dis + 1;
							break;
						} else if(j <= a - dis && j >= b + dis && i == b + dis) {
							ans += dis + 1;
							break;
						}
						dis++;
					}
					
				}
			} 
		}
		cout << ans << endl;

	}
	
}