#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(c == a || c == b || d == a || d == b) {
			cout << "YES" << endl;
			break;
		} 
		int Max = max(a, b);
		int Min = min(a, b);
		if(Max > c && c > Min && (d > Max || d < Min)) cout << "YES" << endl;
		else if(Max > d && d > Min && (c > Max || c < Min)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}