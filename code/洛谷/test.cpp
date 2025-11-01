#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  vector<int> arr(a);
  for(auto &i:arr){
    cin>>i;
  }
  for(int i=1;i<a;i++){
    for(int j=i-1;j>=0&&arr[j]>=arr[j+1];j--){
      if(arr[j]>arr[i]){
        swap(arr[i],arr[j]);
        break;
      }
    }
  }

  for(auto i:arr){
    cout<<i;
  }
}