#include<iostream>
#include<graphics.h>
using namespace std;
/*1��ʾo��2��ʾx��0��ʾ��*/
int board_data[3][3] = { 0,0,0,
						 0,0,0,
						 0,0,0 };
int piece_now = 1;
void drawboard()//��������
{
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}
void drawpieces()//��������
{
	for (int i = 0;i <= 2;i++)
		for (int j = 0;j <= 2;j++)
		{
			switch (board_data[i][j])
			{
			case 1:
				circle(200 * j + 100, 200 * i + 100, 100);
				break;

			case 2:
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200 * (j + 1), 200 * i, 200 * j, 200 * (i + 1));
				break;
			defalut:
				break;
			}
		}
}
void prompting()//��ʾ��Ϣ
{
	static TCHAR str[64];
	if (piece_now == 1)
	{
		_stprintf_s(str, _T("��ǰ����Ϊ��o"));
	}
	else
	{
		_stprintf_s(str, _T("��ǰ����Ϊ��x"));
	}
	
	settextcolor(RGB(255, 175, 45));
	outtextxy(0, 0, str);
}
bool checkwin(int a)//����Ƿ��ʤ����
{
	if (board_data[0][0] == a && board_data[0][1] == a && board_data[0][2] == a)
		return true;
	if (board_data[1][0] == a && board_data[1][1] == a && board_data[1][2] == a)
		return true;
	if (board_data[2][0] == a && board_data[2][1] == a && board_data[2][2] == a)
		return true;
	if (board_data[0][0] == a && board_data[1][0] == a && board_data[2][0] == a)
		return true;
	if (board_data[0][1] == a && board_data[1][1] == a && board_data[2][1] == a)
		return true;
	if (board_data[0][2] == a && board_data[1][2] == a && board_data[2][2] == a)
		return true;
	if (board_data[0][0] == a && board_data[1][1] == a && board_data[2][2] == a)
		return true;
	if (board_data[0][2] == a && board_data[1][1] == a && board_data[2][0] == a)
		return true;

	return false;
	

}
bool checkdraw()//ƽ��
{
	for (int i = 0;i <= 2;i++)
		for (int j = 0;j <= 2;j++)
		{
			if (board_data[i][j] == 0)
			{
				return false;
			}
		}
	return true;
}//����Ƿ�ƽ��
int main()
{
	initgraph(600, 600);
	
	bool running = true;
	ExMessage msg;
	BeginBatchDraw;
	while (running)
	{
		DWORD start_time = GetTickCount();
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				
				int x = msg.x;
				int y = msg.y;//��ȡ���λ��	
				int idx = x / 200;
				int idy = y / 200;

				if (board_data[idy][idx] == 0)
				{
					board_data[idy][idx] = piece_now;
					if (piece_now == 1)
					{
						piece_now = 2;
					}
					else if (piece_now == 2)
					{
						piece_now = 1;
					}
				}
			}
		}
		cleardevice();
		drawboard();
		drawpieces();
		prompting();
		FlushBatchDraw();
		if (checkwin(1))
		{
			MessageBox(GetHWnd(), _T("o��ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (checkwin(2))
		{
			MessageBox(GetHWnd(), _T("x��ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (checkdraw())
		{
			MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		DWORD end_time = GetTickCount();
		DWORD time = end_time - start_time;
		if (time < 1000 / 60)
		{
			Sleep(1000 / 60);
		}

		

	}
	EndBatchDraw();
}
