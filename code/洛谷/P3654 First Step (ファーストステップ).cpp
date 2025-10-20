#include<bits/stdc++.h>
using namespace std;
char stage[105][105];

int main() {
  int R, C, K,ans=0;
  cin >> R >> C >> K;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> stage[i][j];
    }
  }
  int length_limit=R+1-K, width_limit=C+1-K;
  for (int i = 0; i < C;i++){
    for (int j = 0; j < length_limit;j++){
      for (int k = 0; k < K ;k++){
        if (stage[j + k][i]!='.'){
            break;
        }
        else if(k==K-1){
          ans++;
        }
    }
    }
}

for (int i =0; i < R;i++){
  for (int j = 0; j < width_limit;j++){
    for (int k = 0; k < K;k++){
      if(stage[i][j+k]!='.'){
        break;
      }
      else if(k==K-1){
        ans++;
      }
    }
  }
}
if(K!=1)
cout << ans;
else
  cout << ans / 2;
}