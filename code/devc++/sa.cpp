#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[5]={1,5,7,9,43};
	auto i=upper_bound(arr,arr+5,7);
	cout<<*i<<endl;
	int num=distance(arr,i);
	cout<<num;
}
