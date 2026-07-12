/* 个人信息已删除 */
#include <iostream>
#include <windows.h>
#include "cmd_console_tools.h"
#include "color_linez.h"
using namespace std;

int main()
{

	/* 这是一段用于验证cmd_console_tools.cpp版本是否正确的代码，判断正确的具体标准在作业文档中 */
	cct_showstr(10, 2, "请输出雪花的大小", COLOR_BLACK, COLOR_WHITE, 2);
	cout << endl << endl;
	cct_showstr(10, 4, "╔═══汉诺塔═══╗", COLOR_BLACK, COLOR_WHITE, 1);
	cct_showstr(10, 5, "╔═══汉诺塔 ═══╗", COLOR_WHITE, COLOR_BLACK, 1);
	cct_showstr(10, 6, "╔═══H汉诺塔 ═══╗", COLOR_RED, COLOR_HYELLOW, 1);

	cct_showstr(10, 8,  "**╔═╦═╗中", COLOR_CYAN, COLOR_YELLOW, 1);
	cct_showstr(10, 9,  "中║测║试║**", COLOR_HBLUE, COLOR_HPINK, 1);
	cct_showstr(10, 10, "**╠═╬═╣**", COLOR_YELLOW, COLOR_HGREEN, 1);
	cct_showstr(10, 11, "中║ab║12║中", COLOR_HPINK, COLOR_HCYAN, 1);
	cct_showstr(10, 12, "**╚═╩═╝中", COLOR_GREEN, COLOR_HBLUE, 1);

    /* 本函数位于 color_linez_tools.cpp 中 */
	to_be_continued("请确认上面的输出没有乱码/字符相互重叠现象，如果有，说明cmd_console_tools.cpp不对");
    //给出后续的正常内容
	// 选择选项
	char choice;
	while (1)
	{
		choice = color_linez_menu();

		if (choice == 'Q')
		{
			cout << "程序结束，拜拜爱你哦，辛苦辛苦了" << endl;
			break;
		}
		else if (choice == 'A')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_A();
		}
		else if (choice == 'B')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_B();
		}
		else if (choice == 'C')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_C();
		}
		else if (choice == 'D')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_D();
		}
		else if (choice == 'E')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_E();
		}
		else if (choice == 'F')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_F();
		}
		else if (choice == 'G')
		{
			Sleep(200);
			cout << endl << endl;
			color_linez_G();
		}
	}

	return 0;
}

