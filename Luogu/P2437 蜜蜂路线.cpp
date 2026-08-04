#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> hp(const vector<ll> &a,const vector<ll> &b){
  vector <ll> sum;
  ll maxlen=max(a.size(),b.size());
  int carry=0;
  for(int i=0;i<maxlen;i++){
    if(i<a.size()){
      carry+=a[i];
    }
    if(i<b.size()){
      carry+=b[i];
    }
    sum.push_back(carry%10);
    carry/=10;
  }
  while (carry)
  {
    sum.push_back(carry%10);
    carry/=10;
  }
  return sum;
  
}
int main(){
    vector<ll> temp;
    vector<ll> pre;
    vector<ll> pre_pre;
    ll m,n;
    cin>>m>>n;
    pre.push_back(1);
    pre_pre.push_back(1);
    for(int i=m;i<=n-2;i++){
      temp=hp(pre,pre_pre);
      if(i!=n){
        pre_pre=pre;
        pre=temp;
      }
    }
    reverse(temp.begin(),temp.end());
    if(m==n||m==(n-1)){
      cout<<1;
    }
    else
    for(auto i:temp){
      cout<<i;
    }

}