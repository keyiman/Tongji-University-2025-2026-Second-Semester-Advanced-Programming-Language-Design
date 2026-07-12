/* 个人信息已删除 */
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "color_linez.h"
using namespace std;

char color_linez_menu()
{
    /*
      1. 字体：新宋体，高度28，宽度14
      2. 窗口大小：宽度80，高度28
      3. 缓冲区大小：宽度80，高度200
     */
    cct_setconsoletitle("【机密】基于C++伪图形界面的TJU-255xxxx彩球同色湮灭与寻路优化研究");
    cct_setconsoleborder(80, 28, 80, 200);
    cct_setcolor();
    cct_setfontsize("新宋体", 28, 14);

    while (1)
    {
        cct_cls();

        cout << "--------------------------------------------" << endl;
        cout << "A.内部数组，随机生成初始5个球" << endl;
        cout << "B.内部数组，随机生成60%的球，寻找移动路径" << endl;
        cout << "C.内部数组，完整版" << endl;
        cout << "D.画出n*n的框架（无分隔线），随机显示5个球" << endl;
        cout << "E.画出n*n的框架（有分隔线），随机显示5个球" << endl;
        cout << "F.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
        cout << "G.cmd图形界面完整版" << endl;
        cout << "Q.退出" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "[请选择:] ";

        char ch;
        while (1)
        {
            ch = _getch();

            if ((ch >= 'a' && ch <= 'g') || ch == 'q')
                ch = ch - 32;

            if ((ch >= 'A' && ch <= 'G') || ch == 'Q')
            {
                cout << ch << endl;
                return ch;
            }
        }
    }
}



