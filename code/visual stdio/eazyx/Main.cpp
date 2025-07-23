#include <graphics.h>	// 引用图形库头文件
#include<iostream>
#include <conio.h>
using namespace std;
int main()
{
	initgraph(1280, 720);

	int x;
	int y;
	BeginBatchDraw();

		while (true)
		{
			ExMessage msg;
			while (peekmessage(&msg))
			{
				if (msg.message == WM_MOUSEMOVE)
				{
					x = msg.x;
					y = msg.y;

				}
			}
			cleardevice();
			solidcircle(x, y, 100);
			FlushBatchDraw;
		}
		EndBatchDraw();

}