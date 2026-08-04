#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

int lowbit(int x) {
	return x & -x;;
}

void update(int x, int n) {
	for(int i = x; i <= n; i += lowbit(i)) {
		tree[i] += 1;
	}
}

int query(int x) {
	int res = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) {
		res += tree[i];
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1); for(int i = 1; i <= n; i++) {cin >> a[i];}
	tree.resize(n + 1, 0);
	vector<int> ans(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		ans[i] = i - 1 - query(a[i]);
		update(a[i], n);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
	
} 