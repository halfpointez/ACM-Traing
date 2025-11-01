#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a, ll b) { return a < b; }
int main() {
  ll n;
  ll ans = 0;
  cin >> n;
  vector<vector<ll>> apple(15);
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    apple[0].push_back(temp);
  }
  ll len = apple[0].size();
  ll counter = 0;
  if(len==1){
    cout<<0;
  }
  else{
    while (len != 1) {
      sort(apple[counter].begin(), apple[counter].end(), cmp);
      if (len % 2 == 0) {
        for (ll i = 0; i <= len - 2; i += 2) {
          apple[counter + 1].push_back(apple[counter][i] +
                                       apple[counter][i + 1]);
          ans += (apple[counter][i] + apple[counter][i + 1]);
        }
      } else {
        for (ll i = 0; i <= len - 3; i += 2) {
          apple[counter + 1].push_back(apple[counter][i] +
                                       apple[counter][i + 1]);
          ans += (apple[counter][i] + apple[counter][i + 1]);
        }
        apple[counter + 1].push_back(apple[counter].back());
      }
      len = apple[counter + 1].size();
      counter++;
    }
    cout << ans;
  }
  
}