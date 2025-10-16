#include <bits/stdc++.h>
#include <iomanip>
#include<algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  long long  n;
  long long ans = 0;
  long long max_num = 0;
  cin >> n;
  vector<long long> a(n);
  vector<long long> Num_Map(50005, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Num_Map[a[i]]++;
    max_num = max(a[i], max_num);
  }

  for (int i = 2; i <= max_num;i++){
    if(Num_Map[i]==0){
      continue;
    }
    long long large_sum = Num_Map[i];
    large_sum = large_sum * (large_sum - 1) / 2;
    long long small_sum = 0;
    for (long long small_num_a = 1; small_num_a <= i / 2; small_num_a++) {
      long long small_num_b = i - small_num_a;
      if(small_num_a==small_num_b){
        small_sum += Num_Map[small_num_a] * (Num_Map[small_num_a] - 1) / 2;
      } 
      else {
        small_sum += Num_Map[small_num_a] * Num_Map[small_num_b];
      }
    }
    ans += small_sum % MOD * large_sum % MOD;
  }
  cout << ans % MOD;
}