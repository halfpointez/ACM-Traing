#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int A[2] = {a1, a2};
        int B[2] = {b1, b2};
        int ans = 0;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int sWins = 0, slavWins = 0;

                if (A[i] > B[j]) sWins++;
                else if (A[i] < B[j]) slavWins++;

                if (A[1 - i] > B[1 - j]) sWins++;
                else if (A[1 - i] < B[1 - j]) slavWins++;

                if (sWins > slavWins) ans++;
            }
        }
        cout << ans << '\n';
    }

}