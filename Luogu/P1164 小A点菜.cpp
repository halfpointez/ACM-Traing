#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[105][10005]={0};
int main(){
    ll M,N,ans=0;
    cin>>N>>M;
    vector <ll> arr(N+1);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(j==arr[i]){
                dp[i][j]=1+dp[i-1][j];
            }
            else if(j<arr[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
            }
        }
    }
    cout<<dp[N][M];
}