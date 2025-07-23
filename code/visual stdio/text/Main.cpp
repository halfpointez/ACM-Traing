#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int x=100;
	int n;
	cin >> n;
	x = pow(2, n);
	int arr[x][x];
	for (int i = 0;i < x;i++)
	{
		for (int j = 0;j < x;j++)
			arr[i][j] = 1;
	}//初始化所有格子为1 

	for (int i = 0;i < x;i++)
	{
		for (int j = 0;j < x;j++)
		{
			cout << arr[i][j];
			if (j == (x - 1))
			{
				cout << endl;
			}
		}

	}//输出结果 
