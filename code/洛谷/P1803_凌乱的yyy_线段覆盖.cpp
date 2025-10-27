#include<bits/stdc++.h>
using namespace std;
bool num_map[100001]={0};
#define ll long long
bool cmp(ll a, ll b){
    return a<b;
}
int main() {
  vector<vector<ll> > a(100001);
  ll ans=0;
  ll time=0;
  int n;
  cin>>n;
  vector<ll> jud_num;  // 记录哪些时间头是有比赛的
  while (n--) {
    int t_st, t_fin;
    cin >> t_st >> t_fin;
    a[t_st].push_back(t_fin);
    num_map[t_st]=1;
    if(num_map[t_st]!=1){
      jud_num.push_back(t_st);
    }
  }
  for (auto i : jud_num) {
    sort(a[i].begin(), a[i].end(), cmp);
  }
  int ord=0;
  sort(jud_num.begin(),jud_num.end(),cmp);
  while (time<=jud_num.back()){
    if (time == jud_num[ord]) {
      time += a[jud_num[ord]][0];
      ans++;
      ord++;
    } 
    else if (time < jud_num[ord]){
      time=jud_num[ord];
    }
    else if(time>jud_num[ord]){
      while (jud_num[ord] < time) {
        ord++;
      }
    }
  }

  cout<<ans;

}