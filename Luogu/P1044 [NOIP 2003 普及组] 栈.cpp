#include<bits/stdc++.h>
using namespace std;
int dp[20][20];
int main() {
    int N;
    cin>>N;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(!i){
                dp[i][j]=1;
            }
            else if(!j){
                dp[i][j]=dp[i-1][j+1];
            }
            else{
                dp[i][j]=dp[i][j-1]+dp[i-1][j+1];
            }
        }
    }
    cout<<dp[N][0];
}