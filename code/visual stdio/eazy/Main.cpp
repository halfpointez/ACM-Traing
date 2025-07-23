#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
struct contacts//��ϵ�˶���
{
	string name;//����
	string sex;//�Ա�
	int age;//����
	string number;//�绰��
	string addr;//סַ
};
#define max 1000
struct addressbook//�绰������
{
	struct contacts contactsarry[max];
	int people_num = 0;//ͨѶ¼����
};
/*��������*/
void showmenu();
void addcontacts(addressbook* p);
void display(addressbook* p);
void cancel(addressbook* p);
void check(addressbook* p);
void modification(addressbook* p);
void clear(addressbook* p);
/*��������*/
int main()
{
	showmenu();
	bool running = true;
	ExMessage msg;
	addressbook A;
	A.people_num = 0;
	while (running)
	{
		
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{

				int y;
				y = msg.y;
				int select = (y) / 50;
				switch (select)
				{
	
				case 1:
					addcontacts(&A);
					break;
				case 2:
					display(&A);
					break;
				case 3:
					cancel(&A);
					break;
				case 4:
					check(&A);
					break;
				case 5:
					modification(&A);
					break;
				case 6:
					clear(&A);
					break;
				case 7:
					cout << "�˳��ɹ�" << endl;
					system("pause");
					return(0);
					break;
				case 8:
					cout << A.contactsarry[0].name;
				default:
					break;
				}

			}
		}
	
	}

	


}
void showmenu()
{
	initgraph(300, 407);
	line(0, 50, 300, 50);
	line(0, 101, 300, 101);
	line(0, 152, 300, 152);
	line(0, 203, 300, 203);
	line(0, 254, 300, 254);
	line(0, 305, 300, 305);
	line(0, 356, 300, 356);
	settextstyle(25, 0, _T("����"));
	outtextxy(0, 0, _T("���������ִ�в�����"));
	settextstyle(50, 0, _T("����"));
	outtextxy(0, 51, _T("1.�����ϵ��"));
	outtextxy(0, 102, _T("2.��ʾ��ϵ��"));
	outtextxy(0, 153, _T("3.ɾ����ϵ��"));
	outtextxy(0, 204, _T("4.������ϵ��"));
	outtextxy(0, 255, _T("5.�޸���ϵ��"));
	outtextxy(0, 306, _T("6.�����ϵ��"));
	outtextxy(0, 357, _T("7.�˳�ͨѶ¼"));
}
void addcontacts(addressbook* p)//�����ϵ�˹��ܺ���
{

	if (p->people_num == max)
	{
		cout << "��������";
	}
	else
	{
		cout << "������������";
		string Name;
		cin >> Name;
		for (int i = 0;i <= p->people_num + 1;i++)
		{
			if (p->contactsarry[i].name == Name)
			{
				cout << "����ϵ���Ѵ���";
				system("pause");
				system("cls");
				break;
			}
			else if (i == p->people_num)
			{
				goto flag;
			}
		flag:
			p->contactsarry[p->people_num].name = Name;
			cout << "������绰���룺";
			cin >> p->contactsarry[p->people_num].number;
			cout << "�������Ա�";
			cin >> p->contactsarry[p->people_num].sex;
			cout << "���������䣺";
			cin >> p->contactsarry[p->people_num].age;
			cout << "�������ַ��";
			cin >> p->contactsarry[p->people_num].addr;
			cout << "��ϵ��" << p->people_num << "�����ɹ�" << endl;
			p->people_num++;
			system("pause");
			system("cls");
			break;



		}



	}
}
void display(addressbook* p)//��ʾ��ϵ�˹��ܺ���
{

	if (p->people_num == 0)
	{
		cout << "��ϵ��Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0;i < p->people_num;i++)
		{
			cout << i << "." << "����:" << p->contactsarry[i].name << " �绰����:" << p->contactsarry[i].number << " �Ա�:" << p->contactsarry->sex << " ����:" << p->contactsarry->age << " ��ַ:" << p->contactsarry->addr << endl;
		}
		system("pause");
		system("cls");
	}
}
void cancel(addressbook* p)//ɾ����ϵ�˺���
{
	if (p->people_num != 0)
	{
		cout << "������Ҫɾ������ϵ������" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "�ҵ���ϵ��:" << i << endl << "����:" << p->contactsarry[i].name << endl << "�绰����:" << p->contactsarry[i].number << endl << "�Ա�:" << p->contactsarry->sex << endl << "����:" << p->contactsarry->age << endl << "��ַ:" << p->contactsarry->addr << endl;
				cout << "�Ƿ�ȷ��ɾ��(�����롮�ǡ��򡮷�)" << endl;
				string b;
				cin >> b;
				if (b == "��")
				{
					for (int a = i;a < p->people_num;a++)
					{
						p->contactsarry[a] = p->contactsarry[a + 1];
						p->people_num--;
						cout << "ɾ���ɹ�";
						system("pause");
						system("cls");

					}
				}
				else
				{
					cout << "ȡ��ɾ��";
					system("pause");
					system("cls");

					break;
				}
				break;
			}
			else
			{
				cout << "��ϵ�˲�����";
				system("pause");
				system("cls");
				break;
			}
		}
	}
	else
	{
		cout << "��ϵ��Ϊ��" << endl;
		system("pause");
		system("cls");
	}
}
void check(addressbook* p)//������ϵ�˺���
{
	if (p->people_num != 0)
	{
		cout << "������Ҫ���ҵ���ϵ������" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "�ҵ���ϵ��" << i << endl << "����:" << p->contactsarry[i].name << endl << "�绰����:" << p->contactsarry[i].number << endl << "�Ա�:" << p->contactsarry->sex << endl << "����:" << p->contactsarry->age << endl << "��ַ:" << p->contactsarry->addr << endl;
				system("pause");
				system("cls");
				int a = 0;
				break;
			}
			else if (i == p->people_num)
			{
				cout << "δ�ҵ���ϵ��";
				system("pause");
				system("cls");
			}
		}




	}
	else
	{
		cout << "��ϵ��Ϊ��" << endl;
		system("pause");
		system("cls");

	}
}


void modification(addressbook* p)//�޸���ϵ�˺���
{
	if (p->people_num != 0)
	{
		cout << "������Ҫ���ĵ���ϵ������" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "�ҵ���ϵ��:" << i << endl << "����:" << p->contactsarry[i].name << endl << "�绰����:" << p->contactsarry[i].number << endl << "�Ա�:" << p->contactsarry->sex << endl << "����:" << p->contactsarry->age << endl << "��ַ:" << p->contactsarry->addr << endl;
				cout << "��ѡ��Ҫ���ĵ���Ϣ��� 1.���� 2.�绰���� 3.�Ա� 4.���� 5.��ַ" << endl;
				int b;
				cin >> b;
				string c1, c3, c5;
				int c2, c4;
				switch (b)
				{
				case 1:
					cout << "�������µ�����" << endl;
					cin >> c1;
					p->contactsarry[i].name = c1;
					cout << "�޸ĳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "�������µĵ绰��" << endl;
					cin >> c2;
					p->contactsarry[i].number = c2;
					cout << "�޸ĳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "�������µ��Ա�" << endl;
					cin >> c3;
					p->contactsarry[i].sex = c3;
					cout << "�޸ĳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "�������µĵ绰��" << endl;
					cin >> c4;
					p->contactsarry[i].age = c4;
					cout << "�޸ĳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				case 5:
					cin >> c5;
					p->contactsarry[i].addr = c5;
					cout << "�޸ĳɹ�" << endl;
					system("pause");
					system("cls");
					break;
				}
			defalut:
				cout << "�޴���" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "δ�ҵ���ϵ��" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	else
	{
		cout << "��ϵ��Ϊ��" << endl;
		system("pause");
		system("cls");

	}
}
void clear(addressbook* p)
{
	if (p->people_num != 0)
	{
		cout << "�Ƿ�ȷ��Ҫ���ͨѶ¼��" << endl << "�����롰�ǡ��򡰷�" << endl;
		string a;
		cin >> a;
		if (a == "��")
		{

			for (int i = 0;i <= p->people_num; i++)
			{
				p->contactsarry[i] = {};
			}
			p->people_num = 0;


		}
		else if (a == "��")
		{
			cout << "��ȡ����գ��������˵�";
			system("pause");
			system("cls");

		}
		else
		{
			cout << "ָ���ȷ���������˵�";
			system("pause");
			system("cls");

		}
	}
	else
	{
		cout << "��ϵ��Ϊ��" << endl;
		system("pause");
		system("cls");
	}
}
