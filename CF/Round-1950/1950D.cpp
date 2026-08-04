#include <iostream>
#include <vector>

using namespace std;

int dx[] = {
    10, 11, 
    100, 101, 110, 111, 
    1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111,
    10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 
    11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 
    100000
};

bool dfs(int x) {
    if (x == 1) return true;


    for(int i = 0; i < 31; i++) {
        if(x % dx[i] == 0) {
            
            if(dfs(x / dx[i])) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if(dfs(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}