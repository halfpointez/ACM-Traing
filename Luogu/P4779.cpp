#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<bool> vis;
int main() {
	cin >> n >> m >> s;
	vis.resize(n + 1, 0);
	vector<vector<pair<int, int>>> E(n + 1);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({w, v});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> dis(n + 1, 1e9 + 5);
	dis[s] = 0;
	pq.push({0,s});

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto [w, v]:E[u]) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
	
}