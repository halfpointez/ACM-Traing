#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m, h;
		cin >> n >> m >> h;
		vector<i64> a(n), origin(n); 
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			origin[i] = a[i];
		}
		vector<i64> edit_time(n, 0);
		i64 reset_time = -1, time = 0;
		for(int i = 0; i < m; i++) {
			i64 b, c; cin >> b >> c;
			b -= 1;
			if(reset_time == -1) {
				a[b] += c;
				if(a[b] > h) {
					reset_time = time;
					edit_time[b] = time;
					a[b] = origin[b];
				} else {
					edit_time[b] = time;
				}
			} else {
				if(edit_time[b] < reset_time) {
					a[b] = origin[b];
				} a[b] += c;
				if(a[b] > h) {
					reset_time = time;
					edit_time[b] = time;
					a[b] = origin[b];
				} else {
					edit_time[b] = time;
				}
			}
			time++;
		}

		for(int i = 0; i < n; i++) {
			if(edit_time[i] < reset_time) cout << origin[i] << ' ';
			else cout << a[i] << ' ';
		}
		cout << endl;
	}
	
}