#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1005][1005] = {0};
void hp(ll a[]) int main() {
  int m, n;
  cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (i == m) {
      dp[m] = 1;
    } else if (i == m + 1) {
      dp[m + 1] = 1;
    } else
      dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n];
}