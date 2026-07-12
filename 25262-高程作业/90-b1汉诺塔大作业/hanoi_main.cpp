/* 个人信息已删除 */
#include <iostream>
#include <Windows.h>
#include <conio.h>   //本源程序允许使用，因为要_getch()
#include "cmd_hdc_tools.h"
#include "cmd_console_tools.h"
#include "hanoi.h"

using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

int main()
{
	// 确认cmd窗口
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1)
	{
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
		{
			cout << "程序结束，拜拜爱你哦，辛苦辛苦了" << endl;
			return 0;
		}
	}

	// 选择选项
	int choice;
	while (1)
	{
		choice = hanoi_menu();

		if (choice == 0)
		{
			cout << "程序结束，拜拜爱你哦，辛苦辛苦了" << endl;
			break;
		}
		else if (choice == 1)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi1();
		}
		else if (choice == 2)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi2();
		}
		else if (choice == 3)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi3();
		}
		else if (choice == 4)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi4();
		}
		else if (choice == 5)
		{
			Sleep(200);
			cout << endl;
			hanoi5();
		}
		else if (choice == 6)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi6();
		}
		else if (choice == 7)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi7();
		}
		else if (choice == 8)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi8();
		}
		else if (choice == 9)
		{
			Sleep(200);
			cout << endl << endl;
			hanoi9();
		}
	}

	return 0;
}

