#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> a(7);
		int sum = 0, MAX = 0;
		for(auto &i:a){cin >> i;} sort(a.begin(), a.end());
		for(int i = 0; i < 6; i++) {
			int tmp = -a[i];
			a[i] = -a[i];
		} 

		for(int i = 0; i < 7; i++) {
			sum += a[i];
		}

		cout << sum << endl;
		
	}
	
}