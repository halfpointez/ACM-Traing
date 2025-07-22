#include<bits/stdc++.h>
using namespace std;
vector <bool> list;
long long shai(long long n){
	list.resize(n+1);
	list[0]=true;
	list[1]=true;//trueºÏÊý£¬false¸´Êý 
	for(long long i=2;i<=i/n;i++){
		if(list[i]=false){
			for(long long j=i*i;j<=n;j+=i){
			list[j]=true;
			}
		}
	}
}
int main()
{
	long long a,b,t;
	while(cin>>a>>b){
		t=b/a;
		shai(b/a);
		for(int i=2;i<=t;i++){
			if(list[i]==true){
				if(n%i==0){
					
				}
			}
		}
	}
}
