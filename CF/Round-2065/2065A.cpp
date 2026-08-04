#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--) {
		string s, ans;
		cin >> s;
		int End = s.size() - 2;
		if(End < 0) End = 0;
		ans = s.substr(0, End) + "i"; 
		cout << ans << endl;
	}
	
}