#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 n;
bool dfs(i64 cur, vector<vector<pair<int, int>>> &Node, vector<i64> &Right, vector<bool> &vis) {
	for(auto &j:Node[cur]) {
		i64 tmp = Right[cur] + j.second;
		if(!vis[j.first]) {
			vis[j.first] = 1;
			Right[j.first] = tmp;
			if(!dfs(j.first, Node, Right, vis)) return 0;
		} else {
			if(tmp != Right[j.first]) return 0;
		}
		
	}
	return 1;
}
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		i64 m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> Node(n + 1);
		vector<bool> vis(n + 1, 0);
		vector<i64> Right(n + 1, 0);
		for(int i = 0; i < m; i++) {
			i64 a, b, d;
			cin >> a >> b >> d;
			Node[a].push_back({b, d});
			Node[b].push_back({a, -d});
		}
		bool j = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 0) {
				vis[i] = 1;
				if(!dfs(i, Node, Right, vis)) {
					cout << "NO" << endl;
					j = 1;
					break;
				}
			}
		}
		if(!j) {
			cout << "YES" << endl;
		}
	}
	
}