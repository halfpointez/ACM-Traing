#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
int f(int n, int k) {
    int odd = (n + 1) / 2;          // 奇数的个数
    if (k <= odd) {
        return 2 * k - 1;           // 第 k 个奇数
    } else {
        return 2 * f(n / 2, k - odd); // 跳过奇数，去偶数里找
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << f(n, k) << endl;
	}
	
}