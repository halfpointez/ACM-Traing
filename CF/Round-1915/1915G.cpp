#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> step(const vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = a[(i+1)%n], z = a[(i-1+n)%n];
        if (x && y && z) b[i] = 0;
        else if (x != 1 && y != 1 && z != 1) b[i] = 1;
        else if (x != 2 && y != 2 && z != 2) b[i] = 2;
        else b[i] = 3;
    }
    return b;
}

string to(const vector<int>& a) {
    string s;
    for (int x : a) s += char('0' + x);
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int n = 1; n <= 1e4; ++n) {
        int total = 1;
        for (int i = 0; i < n; ++i) total *= 4;
        bool ok = true;
        for (int m = 0; m < total; ++m) {
            vector<int> a(n);
            int t = m;
            for (int i = 0; i < n; ++i) { a[i] = t % 4; t /= 4; }
            map<string, int> vis;
            vector<int> cur = a;
            int cnt = 0;
            vis[to(cur)] = cnt;
            while (true) {
                cur = step(cur);
                ++cnt;
                string s = to(cur);
                if (vis.count(s)) {
                    int st = vis[s];
                    int p = cnt - st;
                    if (p != 1 && p != 2) {
                        cout << "n=" << n << " p=" << p << " a:";
                        for (int x : a) cout << ' ' << x;
                        cout << endl;
                        ok = false;
                    }
                    break;
                }
                vis[s] = cnt;
                if (cnt > 100) break;
            }
        }
        if (ok) cout << "n=" << n << ": only 1,2" << endl;
    }
    return 0;
}