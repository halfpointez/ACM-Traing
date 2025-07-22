#include<iostream>
using namespace std;
 
const int MAX_SIZE = 1000;  //����λ��
 
//��˺���
int multi(int* fact, int i, int len)
{
	int c = 0;  //��λ
	//���û����len����for���ж���䣨k < MAX_SIZE��
	for (int k = 0; k < len; k++)   
	{
		int mul = fact[k] * i + c;  //λ����˽����������ǰһλ���Ľ�λ
		fact[k] = mul % 10;  //���µ�ǰλ��
		c = mul / 10;        //���½�λ
	}
	//���һλ��˵Ľ�������н�λ������Ҫ�ѽ�λ���µ�fact�У����Ҹ��³���
	while (c)
	{
		fact[len++] = c % 10;
		c /= 10;
	}
	return len; 
	//�����������len�������ô��ݵĻ������ﲻ�÷���Ҳ���Ը���len��ֵ
	//����������������ݣ�ֵ���ݡ����ô��ݺ͵�ַ���ݵ�����
}
//�ӷ�����
int add(int* fact, int* res, int len)
{
	//len��ʾ fact �� res�����������е�λ���ϴ�ֵ 
	int c = 0;  //��λ
	
	for (int k = 0; k < len; k++)
	{
		int sum = fact[k] + res[k] + c;  //λ����ӣ�������ǰһλ���Ľ�λ
		res[k] = sum % 10;  //���µ�ǰλ��
		c = sum / 10;        //���½�λ
	}
	//���һλ��ӵĽ�������н�λ������Ҫ�ѽ�λ���µ�res�У����Ҹ��³���
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
	//�����������飬�ֱ��ʾ�׳ˣ��׳˺�
	int fact[MAX_SIZE], res[MAX_SIZE];  
	//��ʼ����������
	for (int i = 0; i < MAX_SIZE; i++)
	{
		fact[i] = 0;
		res[i] = 0;
	}
 
	fact[0] = 1;
 
	int fact_len = 1, res_len = 0;  //���������λ��
	
	for (int i = 1; i <= n; i++)
	{
		fact_len = multi(fact, i, fact_len);//����i�Ľ׳ˣ������ؽ׳˽��fact����
		res_len = add(fact, res, fact_len); //����i�Ľ׳˺ͣ���������ӽ��res����
 
		//add�ĺ���������������ʾ��Чλ�������Դ����������鳤�ȵĽϴ�ֵ
		// fact_len����Чλһ���res_len�����Դ���fact_len
		//�����֪��fact_len��res_len�Ǹ��󣬿��������������
		/*
		int temp_len = max(fact_len, res_len);
		res_len = add(fact, res, temp_len);
		*/
	}
	//������Ӹ�λ��ʼ�����
	for (int i = res_len - 1; i >= 0; i--)
	{
		cout << res[i];
	}
	cout << endl;
}
