#include<bits/stdc++.h>
using namespace std;
bool num[100000001];
long long ord[10000000]={0};
vector<long long> ans;
void shai(int n){
	memset(num,true,sizeof(num));
	num[0]=false;
	num[1]=false;
	for(int i=2;i<=n;i++){
		if(num[i]==true){
			ans.push_back(i);
			for(long long j=i*i;j<=n;j+=i){
				num[j]=false;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n=0,q=0;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>ord[i];
	}
	shai(n);
	for(int i=0;i<q;i++){
		cout<<ans[ord[i]-1]<<'\n';
	}
	return 0;
}
