#include<bits/stdc++.h>
using namespace std;
struct hhh{
  long long num;
  int ord;
};
bool cmp(hhh a,hhh b){
    if(a.num==b.num){
      return a.ord < b.ord;
    }
    return a.num<b.num;
}

int main(){
    int n;
    double sum=0;
    double ans = 0;
    cin>>n;
    vector <hhh> a(n);
    for (int i = 0; i < n;i++){
        cin>>a[i].num;
        a[i].ord = (i + 1);
    } 
    
    sort(a.begin(), a.end(), cmp);
    for (auto i : a) {
      cout << i.ord<<" ";
    }
    cout << endl;
    for (int i = 0; i < n;i++){
        sum+=(n-(i+1))*a[i].num;
    }
    ans = double(sum / n);
    cout << fixed << setprecision(2) << ans;
}