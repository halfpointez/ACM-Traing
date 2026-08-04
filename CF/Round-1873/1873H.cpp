#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<vector<int>> Node;
vector<bool> vis;
int dfs1(int cur, int fa) {
	vis[cur] = 1;
	for(auto &i:Node[cur]) {
		if(i == fa) continue;
		if(vis[i]) return i;
		int res = dfs1(i, cur);
		if(res != -1) return res;
	}
	return -1;
}

int bfs(int st, int end, int n) {
	deque<int> dq;
	dq.push_back(st);
	vector<int> dist(n + 1, 0);
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if(cur == end) return dist[cur];
		vis[cur] = 1;
		for(auto &i:Node[cur]) {
			if(vis[i]) continue;
			vis[i] = 1;
			dist[i] = dist[cur] + 1;
			dq.push_back(i);
		}
		
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		Node.clear(); vis.clear();
		Node.resize(n + 1); vis.resize(n + 1);
		for(int i =  1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
			Node[u].push_back(v);
			Node[v].push_back(u);
		}
		int V_entry = dfs1(b, 0);
		vis.assign(n + 1, 0);
		int M = bfs(a, V_entry, n);
		vis.assign(n + 1, 0);
		int V = bfs(b, V_entry, n);
		vis.assign(n + 1, 0);
		if(V < M) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}