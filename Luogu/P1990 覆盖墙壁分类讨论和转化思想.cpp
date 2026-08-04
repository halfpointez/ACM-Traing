#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=10000;
vector<ll> f(1000001,0);
vector<ll> g(1000001,0);
int main(){
    int N;
    cin>>N;
    g[0]=0;
    g[1]=1;
    g[2]=2;
    g[3]=4;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    f[3]=5;
    for(int i=4;i<=N;i++){
        g[i]=(f[i-1]+g[i-1])%mod;
        f[i]=((f[i-1]+f[i-2])%mod+(2*g[i-2])%mod)%mod;
    }
    cout<<f[N];
}    