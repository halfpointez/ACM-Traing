#include<bits/stdc++.h>
using namespace std;
string arr[2048];
int main(){
    int n;
    cin>>n;
    arr[1]="/__\\";
    arr[2]=" /\\ ";
    int len=4;
    int high=2;
    int max_high=(int)pow(2,n);
    while (--n)
    {
        int high_tmep=2*high;
        for(int i=high_tmep;i>high;i--){
            int space_num=high;
            for(int j=0;j<space_num;j++){
                arr[i]+=' ';
            }
            arr[i]+=arr[i-high];
            for(int k=0;k<space_num;k++){
                arr[i]+=' ';
            }
        }
       for(int i=1;i<=high;i++){
        arr[i]+=arr[i];
       }
       high*=2;
    }
    for(int i=max_high;i>0;i--){
        for(auto j:arr[i]){
            cout<<j;
        }
        cout<<endl;
    }
}



