#include<bits/stdc++.h>
using namespace std;
struct race
{
  int t_begin;
  int t_end;
};
bool cmp(const race &a,const race &b){
  return a.t_end<b.t_end;
}
int main(){
  int ans=0;
  int n;
  cin>>n;
  vector<race> r(n);
  for(auto &i:r){
    cin>>i.t_begin;
    cin>>i.t_end;
  }
  sort(r.begin(),r.end(),cmp);
  int last_t=r.back().t_end;
  int t=0;
     for(auto i:r){
      if(i.t_begin>=t){
        t=i.t_end;
        ans++;
      }
      else{
        continue;
      }
     }
  cout<<ans;
}