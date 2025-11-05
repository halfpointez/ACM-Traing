/* #include <bits/stdc++.h>
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
  
} */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
bool cmp(i64 a, i64 b) { return a > b; }
int main() {  
  int n,ans=0;
  cin>>n;
  vector <i64> apple(n);
  for(auto &i:apple) {
    cin>>i;
  }

  sort(apple.begin(),apple.end(),cmp);

  while (apple.size()-2) {
    int i=apple.size()-1;
    int sum=0;
      if(apple[i]>apple[i-1]) {
        swap(apple[i],apple[i-1]);
        }
        if(apple[i-1]>apple[i-2]) {
          swap(apple[i-1],apple[i-2]);
      }
      if(apple[i]>apple[i-1]) {
        swap(apple[i],apple[i-1]);
        }

      sum=apple[i]+apple[i-1];
        ans+=sum;
        apple.pop_back();
        apple.pop_back();
        apple.push_back(sum);

  }
    ans+=(apple[0]+apple[1]);

    cout<<ans;
}