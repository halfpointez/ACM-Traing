#include<bits/stdc++.h>
using namespace std;
#include <climits>
int ans = INT_MAX;
struct food {
  int s;
  int b;
};
void dfs(int have_choice_sum, const vector<food> &Food,vector<bool> &memory_map,int n,int sum,int multiple) {

    if(have_choice_sum==n){
      return;
    }

  for (int i = 0;i<n;i++){
    if(memory_map[i]==0){
      sum += Food[i].b;
      multiple *= Food[i].s;
      ans = min(ans, abs(sum - multiple));
      memory_map[i] = 1;
      dfs(have_choice_sum + 1, Food, memory_map, n, sum, multiple);
      memory_map[i] = 0;
      sum-=Food[i].b;
      multiple /= Food[i].s;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<food> Food(n);
  vector<bool> memory_map(n,false);
  for (int i = 0; i < n; i++) {
    cin >> Food[i].s >> Food[i].b;
  }
  dfs(0, Food, memory_map, n, 0, 1);
  cout << ans;
}