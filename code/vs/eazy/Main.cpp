#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
struct contacts//联系人定义
{
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string number;//电话号
	string addr;//住址
};
#define max 1000
struct addressbook//电话本定义
{
	struct contacts contactsarry[max];
	int people_num = 0;//通讯录人数
};
/*函数声明*/
void showmenu();
void addcontacts(addressbook* p);
void display(addressbook* p);
void cancel(addressbook* p);
void check(addressbook* p);
void modification(addressbook* p);
void clear(addressbook* p);
/*函数声明*/
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
					cout << "退出成功" << endl;
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
	settextstyle(25, 0, _T("黑体"));
	outtextxy(0, 0, _T("鼠标左键点击执行操作："));
	settextstyle(50, 0, _T("黑体"));
	outtextxy(0, 51, _T("1.添加联系人"));
	outtextxy(0, 102, _T("2.显示联系人"));
	outtextxy(0, 153, _T("3.删除联系人"));
	outtextxy(0, 204, _T("4.查找联系人"));
	outtextxy(0, 255, _T("5.修改联系人"));
	outtextxy(0, 306, _T("6.清空联系人"));
	outtextxy(0, 357, _T("7.退出通讯录"));
}
void addcontacts(addressbook* p)//添加联系人功能函数
{

	if (p->people_num == max)
	{
		cout << "人数已满";
	}
	else
	{
		cout << "请输入姓名：";
		string Name;
		cin >> Name;
		for (int i = 0;i <= p->people_num + 1;i++)
		{
			if (p->contactsarry[i].name == Name)
			{
				cout << "该联系人已存在";
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
			cout << "请输入电话号码：";
			cin >> p->contactsarry[p->people_num].number;
			cout << "请输入性别：";
			cin >> p->contactsarry[p->people_num].sex;
			cout << "请输入年龄：";
			cin >> p->contactsarry[p->people_num].age;
			cout << "请输入地址：";
			cin >> p->contactsarry[p->people_num].addr;
			cout << "联系人" << p->people_num << "创建成功" << endl;
			p->people_num++;
			system("pause");
			system("cls");
			break;



		}



	}
}
void display(addressbook* p)//显示联系人功能函数
{

	if (p->people_num == 0)
	{
		cout << "联系人为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0;i < p->people_num;i++)
		{
			cout << i << "." << "姓名:" << p->contactsarry[i].name << " 电话号码:" << p->contactsarry[i].number << " 性别:" << p->contactsarry->sex << " 年龄:" << p->contactsarry->age << " 地址:" << p->contactsarry->addr << endl;
		}
		system("pause");
		system("cls");
	}
}
void cancel(addressbook* p)//删除联系人函数
{
	if (p->people_num != 0)
	{
		cout << "请输入要删除的联系人姓名" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "找到联系人:" << i << endl << "姓名:" << p->contactsarry[i].name << endl << "电话号码:" << p->contactsarry[i].number << endl << "性别:" << p->contactsarry->sex << endl << "年龄:" << p->contactsarry->age << endl << "地址:" << p->contactsarry->addr << endl;
				cout << "是否确定删除(请输入‘是’或‘否’)" << endl;
				string b;
				cin >> b;
				if (b == "是")
				{
					for (int a = i;a < p->people_num;a++)
					{
						p->contactsarry[a] = p->contactsarry[a + 1];
						p->people_num--;
						cout << "删除成功";
						system("pause");
						system("cls");

					}
				}
				else
				{
					cout << "取消删除";
					system("pause");
					system("cls");

					break;
				}
				break;
			}
			else
			{
				cout << "联系人不存在";
				system("pause");
				system("cls");
				break;
			}
		}
	}
	else
	{
		cout << "联系人为空" << endl;
		system("pause");
		system("cls");
	}
}
void check(addressbook* p)//查找联系人函数
{
	if (p->people_num != 0)
	{
		cout << "请输入要查找的联系人姓名" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "找到联系人" << i << endl << "姓名:" << p->contactsarry[i].name << endl << "电话号码:" << p->contactsarry[i].number << endl << "性别:" << p->contactsarry->sex << endl << "年龄:" << p->contactsarry->age << endl << "地址:" << p->contactsarry->addr << endl;
				system("pause");
				system("cls");
				int a = 0;
				break;
			}
			else if (i == p->people_num)
			{
				cout << "未找到联系人";
				system("pause");
				system("cls");
			}
		}




	}
	else
	{
		cout << "联系人为空" << endl;
		system("pause");
		system("cls");

	}
}


void modification(addressbook* p)//修改联系人函数
{
	if (p->people_num != 0)
	{
		cout << "请输入要更改的联系人姓名" << endl;
		string name;
		cin >> name;
		for (int i = 0;i <= p->people_num;i++)
		{
			if (p->contactsarry[i].name == name)
			{
				cout << "找到联系人:" << i << endl << "姓名:" << p->contactsarry[i].name << endl << "电话号码:" << p->contactsarry[i].number << endl << "性别:" << p->contactsarry->sex << endl << "年龄:" << p->contactsarry->age << endl << "地址:" << p->contactsarry->addr << endl;
				cout << "请选择要更改的信息编号 1.姓名 2.电话号码 3.性别 4.年龄 5.地址" << endl;
				int b;
				cin >> b;
				string c1, c3, c5;
				int c2, c4;
				switch (b)
				{
				case 1:
					cout << "请输入新的姓名" << endl;
					cin >> c1;
					p->contactsarry[i].name = c1;
					cout << "修改成功" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "请输入新的电话号" << endl;
					cin >> c2;
					p->contactsarry[i].number = c2;
					cout << "修改成功" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "请输入新的性别" << endl;
					cin >> c3;
					p->contactsarry[i].sex = c3;
					cout << "修改成功" << endl;
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "请输入新的电话号" << endl;
					cin >> c4;
					p->contactsarry[i].age = c4;
					cout << "修改成功" << endl;
					system("pause");
					system("cls");
					break;
				case 5:
					cin >> c5;
					p->contactsarry[i].addr = c5;
					cout << "修改成功" << endl;
					system("pause");
					system("cls");
					break;
				}
			defalut:
				cout << "无此项" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout << "未找到联系人" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	else
	{
		cout << "联系人为空" << endl;
		system("pause");
		system("cls");

	}
}
void clear(addressbook* p)
{
	if (p->people_num != 0)
	{
		cout << "是否确定要清空通讯录？" << endl << "请输入“是”或“否”" << endl;
		string a;
		cin >> a;
		if (a == "是")
		{

			for (int i = 0;i <= p->people_num; i++)
			{
				p->contactsarry[i] = {};
			}
			p->people_num = 0;


		}
		else if (a == "否")
		{
			cout << "已取消清空，返回主菜单";
			system("pause");
			system("cls");

		}
		else
		{
			cout << "指令不正确，返回主菜单";
			system("pause");
			system("cls");

		}
	}
	else
	{
		cout << "联系人为空" << endl;
		system("pause");
		system("cls");
	}
}
