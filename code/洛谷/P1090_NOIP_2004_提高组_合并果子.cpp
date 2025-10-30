#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a, ll b) { return a < b; }
int main() {
  ll n;
  ll ans = 0;
  cin >> n;
  vector<ll> apple;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    apple.push_back(temp);
  }
  ll len = apple.size();
  ll counter = 0;
  if(len==1){
    cout<<0;
  }
  else{
    while (len != 1) {
        sort(apple.begin(), apple.end(), cmp);
        apple.push_back(apple[0]+apple[1]);
        ans+=apple[0]+apple[1];
        apple.erase(apple.begin(),apple.begin()+2);
        len = apple.size();
    }
    cout << ans;
  }
  
}