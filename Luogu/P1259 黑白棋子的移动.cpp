#include<bits/stdc++.h>
using namespace std;
string s;
void swap(char &a,char &b){
    char temp = a;
    a=b;
    b=temp;
}
int main(){
    int n;
    int ord_l=0,ord_r=0;
    cin>>n;
    for(int i=0;i<n;i++){
        s+='o';
    }
    for(int i=0;i<n;i++){
        s+='*';
    }
    s+="--";
    for(auto i:s){
        cout<<i;
    }
    cout<<endl;
    int counter=n;
    while (counter-->4){
        swap(s[n-1-ord_l],s[2*n+2-1-1-ord_r]);
        swap(s[n-ord_l],s[2*n+2-1-ord_r]);
        for(auto i:s){
            cout<<i;
        }
        cout<<endl;
        swap(s[n-1-ord_l],s[2*n+2-1-1-2-ord_r]);
        swap(s[n-ord_l],s[2*n+2-2-1-ord_r]);
        for(auto i:s){
            cout<<i;
        }
        cout<<endl;
        ord_l++;
        ord_r+=2;
    }
        swap(s[n-1-ord_l],s[2*n+2-1-1-ord_r]);
        swap(s[n-ord_l],s[2*n+2-1-ord_r]);
        for(auto i:s){
            cout<<i;
        }
        cout<<endl;
        string sub=s.substr(9);
        string a[4];
        a[0]="ooo*o**--";
        a[1]="o--*o**oo";
        a[2]="o*o*o*--o";
        a[3]="--o*o*o*o";
        for(int i=0;i<4;i++){
            a[i]+=sub;
        }

        for(int i=0;i<4;i++){
            for(auto j:a[i]){
                cout<<j;
            }
            cout<<endl;
        }

    



}