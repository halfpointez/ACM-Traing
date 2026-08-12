#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n';

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;
    i64 ans = 0;
    for(int j = 1; j * j - j <= n; j++){
        i64 M = j * (j + 1);
        i64 t = (n + 1) / M;
        ans += j * t;
        i64 res = n + j + 1 - (t + 1) * M;
        if(res > 0) ans += rem;
    }
    cout << ans << endl;
    return 0;
}