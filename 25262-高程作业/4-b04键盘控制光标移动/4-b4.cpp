/* 个人信息已删除 */
#include <iostream>
#include <cstdio>
#include <conio.h>   //预置头文件，本程序可用，不算违规，其它程序不可用
#include <time.h>    //预置头文件，本程序可用，不算违规，其它程序不可用
#include <windows.h> //预置头文件，本程序可用，不算违规，其它程序不可用
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：cct_cls
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：HANDLE hout ：输出设备句柄
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cct_cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void cct_gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void cct_showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	cct_gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	cct_gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		cct_showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：menu
  功    能：打印菜单并读取用户选择
  返 回 值：用户选择的选项 (0-4)
***************************************************************************/
int menu(const HANDLE hout)
{
	cct_cls(hout);

	cout << "1. 用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
	cout << "2. 用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
	cout << "3. 用箭头键控制上下左右(按大写HPKM不允许移动光标，边界停止)" << endl;
	cout << "4. 用箭头键控制上下左右(按大写HPKM不允许移动光标，边界回绕)" << endl;
	cout << "0. 退出" << endl;
	cout << "[请选择0-4] ";

	int choice;
	while (1)
	{
		choice = _getch();
		if (choice >= '0' && choice <= '4')
		{
			return choice - '0'; 
		}
	}
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：使用 I J K L 控制光标
  输入参数：wrap (0:边界停止, 1:边界回绕)
***************************************************************************/
void move_by_ijkl(const HANDLE hout, int wrap)
{
	int x = MAX_X / 2 + 1; // 光标初始位置在正中心
	int y = MAX_Y / 2 + 1;
	cct_gotoxy(hout, x, y);

	while (1)
	{
		int ch = _getch();

		// 如果读到了扩展码224或0，说明按下了方向键，必须把下一个真实键码吃掉并忽略
		if (ch == 224 || ch == 0)
		{
			_getch();
			continue;
		}

		if (ch == 'q' || ch == 'Q')
		{
			break;
		}
		else if (ch == ' ')
		{
			cct_showch(hout, x, y, ' '); // 消除字符
			cct_gotoxy(hout, x, y);      // 消除后光标位置不变
		}
		else if (ch == 'i' || ch == 'I') y--;
		else if (ch == 'k' || ch == 'K') y++;
		else if (ch == 'j' || ch == 'J') x--;
		else if (ch == 'l' || ch == 'L') x++;
		else continue; // 按其它键无反应

		// 边界处理
		if (wrap) // 边界回绕
		{
			if (x < 1) x = MAX_X;
			if (x > MAX_X) x = 1;
			if (y < 1) y = MAX_Y;
			if (y > MAX_Y) y = 1;
		}
		else // 边界停止
		{
			if (x < 1) x = 1;
			if (x > MAX_X) x = MAX_X;
			if (y < 1) y = 1;
			if (y > MAX_Y) y = MAX_Y;
		}

		cct_gotoxy(hout, x, y);
	}

	// 退出时的操作
	cct_gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单" << endl;
	while (_getch() != '\r'); // 等待按回车键('\r')
}

/***************************************************************************
  函数名称：move_by_arrow
  功    能：使用方向键控制光标
  输入参数：wrap (0:边界停止, 1:边界回绕)
***************************************************************************/
void move_by_arrow(const HANDLE hout, int wrap)
{
	int x = MAX_X / 2 + 1;
	int y = MAX_Y / 2 + 1;
	cct_gotoxy(hout, x, y);

	while (1)
	{
		int ch = _getch();

		// 只有遇到扩展码，才去读真实的扫描码并移动光标
		if (ch == 224 || ch == 0)
		{
			ch = _getch();
			if (ch == 72) y--;      // 上
			else if (ch == 80) y++; // 下
			else if (ch == 75) x--; // 左
			else if (ch == 77) x++; // 右
		}
		else // 普通字符处理
		{
			if (ch == 'q' || ch == 'Q')
			{
				break;
			}
			else if (ch == ' ')
			{
				cct_showch(hout, x, y, ' ');
				cct_gotoxy(hout, x, y);
			}
			// 其余字符（包括I/J/K/L和H/P/K/M）统统忽略
		}

		// 边界处理
		if (wrap)
		{
			if (x < 1) x = MAX_X;
			if (x > MAX_X) x = 1;
			if (y < 1) y = MAX_Y;
			if (y > MAX_Y) y = 1;
		}
		else
		{
			if (x < 1) x = 1;
			if (x > MAX_X) x = MAX_X;
			if (y < 1) y = 1;
			if (y > MAX_Y) y = MAX_Y;
		}

		cct_gotoxy(hout, x, y);
	}

	// 退出时的操作
	cct_gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";
	while (_getch() != '\r');
}

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	srand((unsigned int)(time(0))); //生成伪随机数的种子，只需在程序开始时执行一次即可

	while (1)
	{
		int choice = menu(hout);
		if (choice == 0)
		{
			break; // 退出程序
		}

		cct_cls(hout); //调用系统的cls命令清屏 
		init_border(hout);//显示初始的边框及其中的随机字符

		switch (choice)
		{
			case 1:
				move_by_ijkl(hout, 0);
				break; // IJKL 停止
			case 2:
				move_by_ijkl(hout, 1);
				break; // IJKL 回绕
			case 3:
				move_by_arrow(hout, 0);
				break; // 箭头 停止
			case 4:
				move_by_arrow(hout, 1);
				break; // 箭头 回绕
		}
	}

	return 0;
}


//		1、当srand的种子不变时，产生的伪随机数序列____(变/不变)
//		2、如果程序需要产生大量随机数，则srand_______ (仅需要在最开始调用一次/每次rand之前都需要调用)


