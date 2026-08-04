#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'


const vector<i64> Prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    i64 g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = std::gcd(g, a[i]); 
    }

 
    for (i64 p : Prime) {
        if (g % p != 0) {
            cout << p << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}