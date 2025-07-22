#include<iostream>
using namespace std;
 
const int MAX_SIZE = 1000;  //数字位数
 
//相乘函数
int multi(int* fact, int i, int len)
{
	int c = 0;  //进位
	//如果没定义len，则for的判断语句（k < MAX_SIZE）
	for (int k = 0; k < len; k++)   
	{
		int mul = fact[k] * i + c;  //位数相乘结果，并加上前一位数的进位
		fact[k] = mul % 10;  //更新当前位数
		c = mul / 10;        //更新进位
	}
	//最后一位相乘的结果可能有进位，我们要把进位更新到fact中，并且更新长度
	while (c)
	{
		fact[len++] = c % 10;
		c /= 10;
	}
	return len; 
	//如果函数参数len是用引用传递的话，这里不用返回也可以更新len的值
	//详见（函数参数传递，值传递、引用传递和地址传递的区别）
}
//加法函数
int add(int* fact, int* res, int len)
{
	//len表示 fact 和 res，两个数组中的位数较大值 
	int c = 0;  //进位
	
	for (int k = 0; k < len; k++)
	{
		int sum = fact[k] + res[k] + c;  //位数相加，并加上前一位数的进位
		res[k] = sum % 10;  //更新当前位数
		c = sum / 10;        //更新进位
	}
	//最后一位相加的结果可能有进位，我们要把进位更新到res中，并且更新长度
	while (c)
	{
		res[len++] = c % 10;
		c /= 10;
	}
	return len;
}
 
int main()
{
	int n;  cin >> n;
	//定义两个数组，分别表示阶乘，阶乘和
	int fact[MAX_SIZE], res[MAX_SIZE];  
	//初始化两个数组
	for (int i = 0; i < MAX_SIZE; i++)
	{
		fact[i] = 0;
		res[i] = 0;
	}
 
	fact[0] = 1;
 
	int fact_len = 1, res_len = 0;  //两个数组的位数
	
	for (int i = 1; i <= n; i++)
	{
		fact_len = multi(fact, i, fact_len);//计算i的阶乘，并返回阶乘结果fact长度
		res_len = add(fact, res, fact_len); //计算i的阶乘和，并返回相加结果res长度
 
		//add的函数第三个参数表示有效位数，所以传入两个数组长度的较大值
		// fact_len的有效位一般比res_len大，所以传入fact_len
		//如果不知道fact_len和res_len那个大，可以用下面代码解决
		/*
		int temp_len = max(fact_len, res_len);
		res_len = add(fact, res, temp_len);
		*/
	}
	//输出（从高位开始输出）
	for (int i = res_len - 1; i >= 0; i--)
	{
		cout << res[i];
	}
	cout << endl;
}
