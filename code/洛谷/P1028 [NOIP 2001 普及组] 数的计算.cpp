#include<bits/stdc++.h>
using namespace std;
long long f[1005];
long long sum[1005];
int main(){
    int n;
    cin>>n;
    f[1]=1;
    f[2]=2;
    sum[1]=f[1];
    sum[2]=f[1]+f[2];

    for(int i=3;i<=n;i++){
        f[i]=1+sum[i/2];
        sum[i]=f[i]+sum[i-1];
    }

    cout<<f[n];
}