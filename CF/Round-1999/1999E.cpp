#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int baseCnt[MAXN + 1];
long long pref[MAXN + 1]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    for (int i = 1; i <= MAXN; i++) {
        int tmp = i;
        int cnt = 0;
        while (tmp) {
            tmp /= 3;
            cnt++;
        }
        baseCnt[i] = cnt;          
        pref[i] = pref[i-1] + cnt; 
    }

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;

        long long ans = (pref[r] - pref[l - 1]) + baseCnt[l];
        cout << ans << '\n';
    }
    return 0;
}