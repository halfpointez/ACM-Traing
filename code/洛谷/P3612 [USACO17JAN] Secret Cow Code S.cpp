#include <bits/stdc++.h>
using namespace std;
string s;
long long n,len,i;
int main()
{
	cin>>s>>n;
	len=s.size();
	while(len<n)
	{
		i=len;
		while(n>i)	i*=2;
		n-=i/2+1;
		if(n==0)	n=i/2;
	}
	cout<<s[n-1];
}
