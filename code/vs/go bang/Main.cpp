#include<iostream>
#include<graphics.h>
using namespace std;
/*1��ʾo��-1��ʾx��0��ʾ��*/
int board_data[15][15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                                           };
int piece_now = 1;
void drawboard()//��������
{
	int i = 0;
	while(i<=600)
	{
		line(0, i, 600, i);
		line(i, 0, i, 600);
		i += 40;
	}
	
}
void drawpieces()//��������
{
	for (int i = 0;i <= 14;i++)
		for (int j = 0;j <= 14;j++)
		{
			switch (board_data[i][j])
			{
			case 1:
				circle(40 * j + 20, 40 * i + 20, 20);
				break;

			case -1:
				line(40 * j, 40 * i, 40 * (j + 1), 40 * (i + 1));
				line(40 * (j + 1), 40 * i, 40 * j, 40 * (i + 1));
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
bool checkwin(int a,int x,int y)//����Ƿ��ʤ����
{
	if(board_data[x][y]+board_data[x+1][y] + board_data[x + 2][y] + board_data[x + 3][y] + board_data[x + 4][y]==5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y] + board_data[x - 2][y] + board_data[x - 3][y] + board_data[x - 4][y] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x + 1][y+1] + board_data[x + 2][y+2] + board_data[x + 3][y+3] + board_data[x + 4][y+4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y-1] + board_data[x - 2][y-2] + board_data[x - 3][y-3] + board_data[x -4][y-4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y] + board_data[x + 1][y] + board_data[x + 2][y] + board_data[x + 3][y] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y] + board_data[x - 2][y] + board_data[x + 1][y] + board_data[x + 2][y] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x + 1][y] + board_data[x - 1][y] + board_data[x - 2][y] + board_data[x - 3][y] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x][y - 1] + board_data[x][y +1] + board_data[x][y +2] + board_data[x][y +3] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x][y - 1] + board_data[x][y - 2] + board_data[x][y + 1] + board_data[x][y + 2] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x][y + 1] + board_data[x][y - 1] + board_data[x][y - 2] + board_data[x][y - 3] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y - 1] + board_data[x + 1][y + 1] + board_data[x + 2][y + 2] + board_data[x + 3][y + 3] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y - 1] + board_data[x + 1][y + 1] + board_data[x - 2][y - 2] + board_data[x + 2][y + 2] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y - 1] + board_data[x - 2][y - 2] + board_data[x - 3][y -3] + board_data[x + 1][y + 1] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y + 1] + board_data[x - 2][y + 2] + board_data[x - 3][y + 3] + board_data[x - 4][y + 4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x + 1][y - 1] + board_data[x - 1][y + 1] + board_data[x - 2][y + 2] + board_data[x - 3][y + 3] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x + 1][y - 1] + board_data[x +2][y - 2] + board_data[x - 2][y + 2] + board_data[x - 1][y + 1] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x - 1][y + 1] + board_data[x + 1][y - 1] + board_data[x + 2][y - 2] + board_data[x + 3][y - 3] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x + 1][y - 1] + board_data[x + 2][y - 2] + board_data[x + 3][y - 3] + board_data[x - 4][y + 4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x][y+1] + board_data[x][y+2] + board_data[x][y+3] + board_data[x][y+4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x][y-1] + board_data[x][y-2] + board_data[x][y-3] + board_data[x][y-4] == 5 * a)
		return true;
	if (board_data[x][y] + board_data[x+1][y - 1] + board_data[x+2][y - 2] + board_data[x+3][y - 3] + board_data[x+4][y - 4] == 5 * a)
		return true;


	return false;


}
bool checkdraw()
{
	for (int i = 14;i <= 14;i++)
		for (int j = 14;j <= 14;j++)
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
	initgraph(601,601);

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
				int idx = x / 40;
				int idy = y / 40;

				if (board_data[idy][idx] == 0)
				{
					board_data[idy][idx] = piece_now;
					if (piece_now == 1)
					{
						piece_now = -1;
					}
					else if (piece_now == -1)
					{
						piece_now = 1;
					}

				}
				if (checkwin(1,idy,idx))
				{
					drawpieces();
					MessageBox(GetHWnd(), _T("o��ʤ"), _T("��Ϸ����"), MB_OK);
					running = false;
				}
				else if (checkwin(-1,idy,idx))
				{
					drawpieces();
					MessageBox(GetHWnd(), _T("x��ʤ"), _T("��Ϸ����"), MB_OK);
					running = false;
				}
				else if (checkdraw())
				{
					drawpieces();
					MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
					running = false;
				}

			}
		}
		cleardevice();
		drawboard();
		drawpieces();
		prompting();
		FlushBatchDraw();
		
		DWORD end_time = GetTickCount();
		DWORD time = end_time - start_time;
		if (time < 1000 / 60)
		{
			Sleep(1000 / 60);
		}



	}
	EndBatchDraw();
}
