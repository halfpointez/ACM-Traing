#include <bits/stdc++.h>
using namespace std;
vector<int> random_arry(int n, int min_num, int max_num) {
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = min_num + rand() % (max_num - min_num + 1);
  }
  return arr;
}
int binary_search(vector<int> arr, int need_find) {
  int l = 0, r = arr.size() - 1, m;
  while (l <= r) {
    m = l + r / 2;
    if(arr[m]==need_find){
      return m;
    }
    if(arr[m]>need_find){
      r=m-1;
    }
    else if(arr[m]<need_find){
      l=m+1;
    }
  }
  return -1;
}

int binary_search_huger(vector<int> arr, int need_find) {
  int l = 0, r = arr.size() - 1, m,ans=-1;
  while (l <= r) {
    m = l + ((r-l)>>1);
    if (arr[m] <= need_find) {
      ans=m;
      l=m+1;
    }
    else  {
      r =  m - 1;
    } 
  }
  return ans;
}

int main() {
  srand(time(0));
  vector<int> a(10);
  for (auto &i : a) {
    cin>>i;
  }
  sort(a.begin(), a.end());
  for(auto i:a){
    cout<<i<<' ';
  }
  cout<<binary_search_huger(a,4);
}