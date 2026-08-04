#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int j = 0;
        int n = s.size(), m = t.size();

        for (int i = 0; i < n; i++) {
            if (j == m) break;                 
            if (s[i] == '?') {
                s[i] = t[j];                  
                j++;
            } else if (s[i] == t[j]) {
                j++;                           
            }

        }

        if (j == m) {

            for (char &c : s) {
                if (c == '?') c = 'a';
            }
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}