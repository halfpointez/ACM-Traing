#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
struct treasure{
    double w;
    double v;
    double per;
};

bool cmp(treasure a,treasure b) {
    return a.per>b.per;
}

int main(){
    double ans=0;
    int n,t;
    cin>>n>>t;
    vector<treasure> tre(n);
    for(int i=0;i<n;i++){
        cin>>tre[i].w>>tre[i].v;
        tre[i].per=tre[i].v/tre[i].w;
    }
    sort(tre.begin(),tre.end(),cmp);
    for(int i=0;i<n;i++){
        if(t>=tre[i].w){
            ans+=tre[i].v;
            t-=tre[i].w;
        }
        else{
            ans+=t*(tre[i].per);
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
}