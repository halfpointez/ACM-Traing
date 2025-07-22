#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c;
ll x,y,a[5000005],ans;

void dfs(int dep,ll s)
{
	if(dep>c)
	{
		if(s>=y/s) ans=min(ans,s);
		return;
	}
	dfs(dep+1,s);
	dfs(dep+1,s*a[dep]);
}

void sol()
{
	assert(x&&y);
	ans=LLONG_MAX;
	y/=x;
	c=0;
	ll i=2,m=y;
	while(m>1)
	{
		if(m%i)
		{
			i++;
			continue;
		}
		a[++c]=i;
		m/=i;
		while(m%i==0) a[c]*=i,m/=i;
	}
	dfs(1,1);
	printf("%lld %lld\n",y/ans*x,ans*x);
}

int main()
{
	while(cin>>x>>y) sol();
	return 0;
}

