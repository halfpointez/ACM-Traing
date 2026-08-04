#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<vector<i64>> cnt(30, vector<i64>(4, 0));
    vector<vector<int>> change(31, vector<int>(2, 0));
    vector<vector<i64>> New(30, vector<i64>(4, 0));

    for (auto &cur : a) {
        for (int i = 0; i < 30; i++) {
            int low, high;
            if (i < 29) {
                low  = (cur >> i) & 1;
                high = (cur >> (i + 1)) & 1;
            } else {
                low  = (cur >> 29) & 1;
                high = 0;
            }

            if (high && low) cnt[i][3]++;
            else if (high == 0 && low == 1) cnt[i][1]++;
            else if (high == 0 && low == 0) cnt[i][0]++;
            else if (high == 1 && low == 0) cnt[i][2]++;
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int type, x;
        cin >> type >> x;

        change[30][0] = 0;
        change[30][1] = 0;
        for (int k = 0; k < 30; k++) {
            int bit = (x >> k) & 1;
            if (type == 1) {
                change[k][0] = 0;
                change[k][1] = bit;
            } else if (type == 2) {
                change[k][0] = bit;
                change[k][1] = 1;
            } else {
                change[k][0] = bit;
                change[k][1] = bit ^ 1;
            }
        }

        for (int i = 0; i < 30; i++) {
            fill(New[i].begin(), New[i].end(), 0);

            if (cnt[i][0] != 0) {
                int a = 0, b = 0;
                int na = change[i][a];
                int nb = change[i + 1][b];
                if (nb && na) New[i][3] += cnt[i][0];
                else if (nb == 0 && na == 1) New[i][1] += cnt[i][0];
                else if (nb == 0 && na == 0) New[i][0] += cnt[i][0];
                else if (nb == 1 && na == 0) New[i][2] += cnt[i][0];
            }
            if (cnt[i][1] != 0) {
                int a = 1, b = 0;
                int na = change[i][a];
                int nb = change[i + 1][b];
                if (nb && na) New[i][3] += cnt[i][1];
                else if (nb == 0 && na == 1) New[i][1] += cnt[i][1];
                else if (nb == 0 && na == 0) New[i][0] += cnt[i][1];
                else if (nb == 1 && na == 0) New[i][2] += cnt[i][1];
            }
            if (cnt[i][2] != 0) {
                int a = 0, b = 1;
                int na = change[i][a];
                int nb = change[i + 1][b];
                if (nb && na) New[i][3] += cnt[i][2];
                else if (nb == 0 && na == 1) New[i][1] += cnt[i][2];
                else if (nb == 0 && na == 0) New[i][0] += cnt[i][2];
                else if (nb == 1 && na == 0) New[i][2] += cnt[i][2];
            }
            if (cnt[i][3] != 0) {
                int a = 1, b = 1;
                int na = change[i][a];
                int nb = change[i + 1][b];
                if (nb && na) New[i][3] += cnt[i][3];
                else if (nb == 0 && na == 1) New[i][1] += cnt[i][3];
                else if (nb == 0 && na == 0) New[i][0] += cnt[i][3];
                else if (nb == 1 && na == 0) New[i][2] += cnt[i][3];
            }

            cnt[i] = New[i];
        }

        i64 ans = 0;
        for (int i = 0; i < 30; i++) ans += cnt[i][1];
        cout << ans << endl;
    }

}