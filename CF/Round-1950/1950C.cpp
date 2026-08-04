#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string h_24;
		cin >> h_24;
		int hour_24 = stoi(h_24.substr(0, 2));
		int min_24 = stoi(h_24.substr(3, 2));
		int hour_12, min_12 = min_24;
		string d;
		if(hour_24 >= 12) d = "PM";
		else d = "AM";
		if(hour_24 > 12) hour_12 = hour_24 - 12;
		else if(hour_24 == 0) hour_12 = 12;
		else hour_12 = hour_24;
		if(hour_12 < 10) cout << 0;
		
		cout << hour_12 << ':';

		if(min_12 < 10) cout << 0;


		cout << min_12 << ' ' << d << endl;
	}

	
}