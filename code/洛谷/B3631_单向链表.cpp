#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int MAX_N = 1'000'005;
void insert(vector<int> &num,vector <int> &next,int x,int y) {
    int temp_next=next[x];
    next[x]=y;
    num[y]=y;
    next[y]=temp_next;
}

void p(vector<int> &num,vector <int> &next,int x) {
    if(next[x]==-1){
        cout<<0<<endl;
    }
    else{
        cout<<next[x]<<endl;
    }
}

void del(vector<int> &num,vector <int> &next,int x) {
    int temp_next=next[next[x]];
    num[next[x]]=-1;
    next[x]=temp_next;
}
int main() {
    vector<int> num(MAX_N,-1);
    vector<int> next(MAX_N,-1);
    num[1]=1;
    int q;
    cin>>q;
    while (q--) {
        int a;
        cin>>a;
        if(a==1){
            int x,y;
            cin>>x>>y;
            insert(num,next,x,y);
        }
        else if(a==2) {
            int x;
            cin>>x;
            p(num,next,x);
        }
        else {
            int x;
            cin>>x;
            del(num,next,x);
        }
        
    }
    
}