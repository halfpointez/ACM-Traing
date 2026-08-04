#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        i64 a, b, c;
        cin >> a >> b >> c;

     
        if (c != a + 1) {
            cout << -1 << endl;
            continue;
        }

        i64 stage = 0;
        i64 atmp = a;   
        i64 q = 1;   

     
        while (atmp >= q) {
            atmp -= q;
            q *= 2;
            stage++;
        }


        if (atmp > 0) {
            i64 need1 = q - atmp; 
            if (b < need1) {
               
                cout << stage + 1 << endl;
                continue;
            }
            b -= need1;
            q += atmp;    
            atmp = 0;
            stage++;
        }

     
        if (b > 0) {
            stage += (b + q - 1) / q;  
        }

        cout << stage << endl;
    }
    return 0;
}