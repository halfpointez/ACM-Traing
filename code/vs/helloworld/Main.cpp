#include <iostream>
using namespace std;
int main()
{    
	int temp;
	int arr[9] = {44,55,7,8,11,4,98,11,77};
	for (int a = 0;a <8;a++)
	{		
		for (int j = 0;j < 8 - a;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp =arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
	for (int h = 0;h < 9;h++)
	{
		cout << arr[h] <<" ";
	}

	
		system("pause");
		return 0;
}