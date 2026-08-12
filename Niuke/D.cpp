#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

using i64 = long long;
const i64 INF = 4e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> even(n + 1, -1), odd(n + 1, -1);
        vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
        queue<pair<int, int>> q; //0是奇数 1是偶数 等下记不得回来自己看

        even[1] = 0;
        vis[1][0] = true;
        q.push({1, 0});

        while (!q.empty()) {
            auto [u, p] = q.front(); q.pop();
            for (int v : g[u]) {
                int np = 1 - p; 
                if (!vis[v][np]) {
                    vis[v][np] = true;
                    if (np == 0) {
                        even[v] = (p == 0 ? even[u] : odd[u]) + 1;
                    } else {
                        odd[v] = (p == 0 ? even[u] : odd[u]) + 1;
                    }
                    q.push({v, np});
                }
            }
        }
        for (int u = 1; u <= n; ++u) {
            i64 ans = INF;
            if (even[u] != -1) {
                i64 d0 = even[u], cand;
                if (k % 2 == 1) {
                    i64 base = 0;
                    if (d0 <= base) cand = base;
                    else {
                        i64 diff = d0 - base;
                        cand = base + ((diff + (i64)2 * k - 1) / ((i64)2 * k)) * ((i64)2 * k);
                    }
                } else {
                    cand = ((d0 + k - 1) / k) * k;
                }
                if (cand < ans) ans = cand;
            }

            if (odd[u] != -1) {
                i64 d0 = odd[u], cand;
                if (k % 2 == 1) {
                    i64 base = k;
                    if (d0 <= base) cand = base;
                    else {
                        i64 diff = d0 - base;
                        cand = base + ((diff + (i64)2 * k - 1) / ((i64)2 * k)) * ((i64)2 * k);
                    }
                } else {
                    cand = INF;
                }
                if (cand < ans) ans = cand;
            }

            if (ans == INF) cout << -1;
            else cout << ans;
            if (u < n) cout << ' ';
        }
        cout << endl;
    }

}