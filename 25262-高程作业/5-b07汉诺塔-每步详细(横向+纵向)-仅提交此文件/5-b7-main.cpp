/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;

static int delay_time = 0;
static bool show_array = false;

/***************************************************************************
  函数名称：show_state
  功    能：纵向显示三根柱子的当前状态
***************************************************************************/
void show_state(int pillars[][10], int tops[], int n,
    int step, int disk, char src, char dst)
{
    int row, col;
    int empty_count, index, value;
    int i;

    cct_cls();

    if (step == 0)
    {
        cout << "初始状态" << endl;
    }
    else
    {
        cout << "第" << setw(4) << step << "步("
            << setw(2) << disk << "): "
            << src << "-->" << dst << endl;
    }

    cout << endl;

    for (row = 0; row < n; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (col == 0)
            {
                cout << "          ";
            }
            else
            {
                cout << "        ";
            }

            empty_count = n - tops[col];

            if (row < empty_count)
            {
                cout << "  ";
            }
            else
            {
                index = tops[col] - 1 - (row - empty_count);
                value = pillars[col][index];
                cout << setw(2) << value;
            }
        }

        cout << endl;
    }

    cout << "         =========================" << endl;
    cout << "           A         B         C" << endl;

    if (show_array)
    {
        cout << endl;
        cout << "内部数组值：" << endl;

        cout << "tops:";
        for (col = 0; col < 3; col++)
        {
            cout << setw(3) << tops[col];
        }
        cout << endl;

        for (col = 0; col < 3; col++)
        {
            cout << char('A' + col) << ":";

            for (i = 0; i < 10; i++)
            {
                cout << setw(3) << pillars[col][i];
            }

            cout << endl;
        }
    }

    if (delay_time > 0)
    {
        Sleep(delay_time);
    }
}

/***************************************************************************
  函数名称：move_disk
  功    能：移动一个盘，并刷新屏幕，返回步数
***************************************************************************/
int move_disk(int pillars[][10], int tops[], int n, char src, char dst, int step)
{
    int disk = 0;
    int s, d;

    s = src - 'A';
    d = dst - 'A';

    disk = pillars[s][--tops[s]];
    pillars[s][tops[s]] = 0;
    pillars[d][tops[d]++] = disk;

    step++;

    show_state(pillars, tops, n, step, disk, src, dst);

    return step;
}

/***************************************************************************
  函数名称：hanoi
  功    能：递归完成汉诺塔移动
***************************************************************************/
int hanoi(int pillars[][10], int tops[], int total_n, int n, char src, char tmp, char dst, int step)
{
    if (n == 1)
    {
        step = move_disk(pillars, tops, total_n, src, dst, step);
    }
    else
    {
        step = hanoi(pillars, tops, total_n, n - 1, src, dst, tmp, step);
        step = move_disk(pillars, tops, total_n, src, dst, step);
        step = hanoi(pillars, tops, total_n, n - 1, tmp, src, dst, step);
    }

    return step;
}

/***************************************************************************
  函数名称：main
  功    能：输入数据，初始化汉诺塔，启动动画
***************************************************************************/
int main()
{
    int n;
    char src, dst, tmp;

    int pillars[3][10] = { 0 };
    int tops[3] = { 0 };

    int i;
    int s;

    while (true)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;

        if (cin >> n && n >= 1 && n <= 10)
        {
            cin.ignore(256, '\n');
            break;
        }

        cin.clear();
        cin.ignore(256, '\n');
    }

    while (true)
    {
        cout << "请输入起始柱(A-C)" << endl;

        if (cin >> src)
        {
            cin.ignore(256, '\n');

            if (src >= 'a' && src <= 'c')
            {
                src = char(src - 32);
            }

            if (src >= 'A' && src <= 'C')
            {
                break;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    while (true)
    {
        cout << "请输入目标柱(A-C)" << endl;

        if (cin >> dst)
        {
            cin.ignore(256, '\n');

            if (dst >= 'a' && dst <= 'c')
            {
                dst = char(dst - 32);
            }

            if (dst == src)
            {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            }
            else if (dst >= 'A' && dst <= 'C')
            {
                break;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    int delay_level;
    while (true)
    {
        cout << "请输入移动延时(1-5)" << endl;

        if (cin >> delay_level && delay_level >= 1 && delay_level <= 5)
        {
            cin.ignore(256, '\n');
            break;
        }

        cin.clear();
        cin.ignore(256, '\n');
    }

    if (delay_level == 1)
    {
        delay_time = 1000;
    }
    else if (delay_level == 2)
    {
        delay_time = 500;
    }
    else if (delay_level == 3)
    {
        delay_time = 200;
    }
    else if (delay_level == 4)
    {
        delay_time = 50;
    }
    else
    {
        delay_time = 0;
    }

    int show_flag;
    while (true)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;

        if (cin >> show_flag && (show_flag == 0 || show_flag == 1))
        {
            cin.ignore(256, '\n');
            break;
        }

        cin.clear();
        cin.ignore(256, '\n');
    }

    show_array = show_flag;

    tmp = char('A' + 'B' + 'C' - src - dst);

    s = src - 'A';

    for (i = 0; i < n; i++)
    {
        pillars[s][tops[s]] = n - i;
        tops[s]++;
    }

    show_state(pillars, tops, n, 0, 0, src, dst);

    int step = 0;
    step = hanoi(pillars, tops, n, n, src, tmp, dst, step);

    cout << endl;
    cout << "移动完成，共" << step << "步。" << endl;

    system("pause");
    return 0;
}

