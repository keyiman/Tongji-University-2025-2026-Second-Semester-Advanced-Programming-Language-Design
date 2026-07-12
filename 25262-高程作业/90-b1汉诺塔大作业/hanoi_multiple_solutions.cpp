/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"
#include "hanoi.h"

using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

static int step = 0;                         // 当前移动步数
static int delay_time = 0;                   // 图形/字符演示延时
static int top[3] = { 0 };                   // A/B/C 三柱当前盘子数量
static int tower[3][MAX_LAYER] = { 0 };      // 每柱盘号，0 为底，top[col]-1 为顶
const int TEXT_CLEAR_WIDTH = 120;            // 字符区清行宽度

/***************************************************************************
  函数名称：clear_line
  功    能：清除控制台某一整行，并把光标留在行首
***************************************************************************/
void clear_line(int y)
{
    int i;

    cct_gotoxy(0, y);
    for (i = 0; i < TEXT_CLEAR_WIDTH; i++)
        cout << " ";
    cct_gotoxy(0, y);
}

/***************************************************************************
  函数名称：wait_for_enter
  功    能：等待用户按回车
  说    明：用于菜单结束处 or 图形 0ms 逐像素模式
***************************************************************************/
void wait_for_enter()
{
    while (_getch() != '\r')
        continue;
}

/***************************************************************************
  函数名称：input_hanoi_params
  功    能：菜单 1/2/3/4/6/7/8/9 共用输入函数
  输入参数：delay_max < 0 表示不输入速度；
            delay_max >= 0 表示速度范围为 0-delay_max；
            n/src/dst/delay 通过指针形参带回
***************************************************************************/
void input_hanoi_params(int delay_max, int* n, char* src, char* dst, int* delay)
{
    int ch;

    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10):" << endl;
        cin >> *n;
        if (cin.fail())
            cin.clear();
        while ((ch = cin.get()) != '\n' && ch != EOF)
            continue;
        if (*n >= 1 && *n <= 10)
            break;
    }

    while (1)
    {
        cout << "请输入起始柱(A-C):" << endl;
        cin >> *src;
        if (cin.fail())
            cin.clear();
        while ((ch = cin.get()) != '\n' && ch != EOF)
            continue;
        if (*src >= 'a' && *src <= 'c')
            *src = char(*src - 32);
        if (*src >= 'A' && *src <= 'C')
            break;
    }

    while (1)
    {
        cout << "请输入目标柱(A-C):" << endl;
        cin >> *dst;
        if (cin.fail())
            cin.clear();
        while ((ch = cin.get()) != '\n' && ch != EOF)
            continue;
        if (*dst >= 'a' && *dst <= 'c')
            *dst = char(*dst - 32);

        if (*dst == *src)
            cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
        else if (*dst >= 'A' && *dst <= 'C')
            break;
    }

    if (delay_max >= 0)
    {
        while (1)
        {
            cout << "请输入移动速度(0-" << delay_max
                << "：0-按回车单步演示 1-" << delay_max
                << ":延时1-" << delay_max << "ms)" << endl;
            cin >> *delay;
            if (cin.fail())
                cin.clear();
            while ((ch = cin.get()) != '\n' && ch != EOF)
                continue;
            if (*delay >= 0 && *delay <= delay_max)
                break;
        }
    }
}


/***************************************************************************
  函数名称：init_tower_state
  功    能：清空内部数组，然后把 n 个盘子放到 src 柱
***************************************************************************/
void init_tower_state(int n, char src)
{
    int i, j, s;

    for (i = 0; i < 3; i++)
    {
        top[i] = 0;
        for (j = 0; j < MAX_LAYER; j++)
            tower[i][j] = 0;
    }

    s = src - 'A';
    for (i = 0; i < n; i++)
    {
        tower[s][top[s]] = n - i;
        top[s]++;
    }
}

/***************************************************************************
  函数名称：print_status_line
  功    能：显示状态栏
***************************************************************************/
void print_status_line(int n, char src, char dst, int show_delay, int shown_delay)
{
    clear_line(Status_Line_Y);
    cct_gotoxy(Status_Line_X, Status_Line_Y);

    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
    if (show_delay)
        cout << "，延时设置为 " << shown_delay << "ms";
}

/***************************************************************************
  函数名称：show_x
  功    能：横向显示 A/B/C 三柱内部数组
***************************************************************************/
void show_x()
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        cout << char('A' + i) << ":";
        for (j = 0; j < top[i]; j++)
            cout << setw(2) << tower[i][j];

        if (i != 2)
        {
            for (j = top[i] * 2; j < 20; j++)
                cout << " ";
        }
        cout << " ";
    }
}

/***************************************************************************
  函数名称：show_y
  功    能：纵向显示三柱内部数组
***************************************************************************/
void show_y(int start_x, int start_y)
{
    int row, col, empty, index, i, clear_y;
    int total, x, base_y, name_y;

    total = top[0] + top[1] + top[2];
    x = start_x + Underpan_A_X_OFFSET;
    name_y = start_y + Underpan_A_Y_OFFSET;
    base_y = name_y - 1;

    for (clear_y = base_y - MAX_LAYER; clear_y <= base_y; clear_y++)
    {
        if (clear_y >= 0)
        {
            for (col = 0; col < 3; col++)
            {
                cct_gotoxy(x + col * Underpan_Distance, clear_y);
                cout << "  ";
            }
        }
    }

    for (row = 0; row < total; row++)
    {
        for (col = 0; col < 3; col++)
        {
            cct_gotoxy(x + col * Underpan_Distance, base_y - total + row);
            empty = total - top[col];
            if (row < empty)
                cout << "  ";
            else
            {
                index = top[col] - 1 - (row - empty);
                cout << setw(2) << tower[col][index];
            }
        }
    }

    cct_gotoxy(x - 1, base_y);
    for (i = 0; i < Underpan_Distance * 2 + 5; i++)
        cout << "=";

    cct_gotoxy(x + 1, name_y);
    cout << "A";
    cct_gotoxy(x + 1 + Underpan_Distance, name_y);
    cout << "B";
    cct_gotoxy(x + 1 + Underpan_Distance * 2, name_y);
    cout << "C";
}

/***************************************************************************
  函数名称：show_all
  功    能：完成内部数组纵向+横向显示
  输入参数：start_x/start_y ：纵向数组的基准位置;
           line_x          ：状态栏的起始 x;
           show_initial    ：是否在 step==0 时打印“初始:”
***************************************************************************/
void show_all(int start_x, int start_y, int line_x, int disk, char src, char dst, int show_initial)
{
    int i;

    show_y(start_x, start_y);

    cct_gotoxy(line_x, start_y);
    for (i = line_x; i < TEXT_CLEAR_WIDTH; i++)
        cout << " ";

    if (step == 0 && !show_initial)
    {
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        return;
    }

    cct_gotoxy(line_x, start_y);
    if (step == 0)
        cout << "初始:  ";
    else
        cout << "第" << setw(4) << step << " 步("
        << setw(2) << disk << "#: " << src << "-->" << dst << ")  ";
    show_x();
}

/***************************************************************************
  函数名称：draw3
  功    能：画三根柱子的底座和立柱
***************************************************************************/
void draw3()
{
    int i, x, base_width, pillar_x, pillar_y, pillar_high;

    base_width = HDC_Base_Width * 23;
    pillar_y = HDC_Start_Y - HDC_Base_High * 12;
    pillar_high = HDC_Base_High * 12;

    for (i = 0; i < 3; i++)
    {
        x = HDC_Start_X + i * (base_width + HDC_Underpan_Distance);
        hdc_rectangle(x, HDC_Start_Y, base_width, HDC_Base_High, HDC_COLOR[MAX_LAYER + 1]);
        Sleep(HDC_Init_Delay);
    }

    for (i = 0; i < 3; i++)
    {
        x = HDC_Start_X + i * (base_width + HDC_Underpan_Distance);
        pillar_x = x + HDC_Base_Width * 11;
        hdc_rectangle(pillar_x, pillar_y, HDC_Base_Width, pillar_high, HDC_COLOR[MAX_LAYER + 1]);
        Sleep(HDC_Init_Delay);
    }
}

/***************************************************************************
  函数名称：draw_disk / draw_disks
  功    能：绘制单个盘子，或按 tower/top 绘制某根柱上的所有盘子
***************************************************************************/
void draw_disk(int col, int high, int disk, int color)
{
    int base_width, disk_width, x, y;

    base_width = HDC_Base_Width * 23;
    disk_width = HDC_Base_Width * (disk * 2 + 1);
    x = HDC_Start_X + col * (base_width + HDC_Underpan_Distance) + (base_width - disk_width) / 2;
    y = HDC_Start_Y - HDC_Base_High * (high + 1);
    hdc_rectangle(x, y, disk_width, HDC_Base_High, color);
}

void draw_disks(int col)
{
    int i, disk;

    for (i = 0; i < top[col]; i++)
    {
        disk = tower[col][i];
        draw_disk(col, i, disk, HDC_COLOR[disk]);
        Sleep(HDC_Init_Delay);
    }
}

/***************************************************************************
  函数名称：wait_move
  功    能：图形动画每移动一个小步前的等待
  说    明：delay_time == 0 表示按一次回车移动一个像素，按住回车连续移动;
            delay_time > 0 表示延时若干毫秒;
            delay_time == -1 表示菜单 8 超过 7 步后的自动 0ms，不等待
***************************************************************************/
void wait_move()
{
    if (delay_time == 0)
        wait_for_enter();
    else if (delay_time > 0)
        Sleep(delay_time);
}

/***************************************************************************
  函数名称：restore_pillar
  功    能：盘子擦除后，如果擦到了立柱，就把立柱补回来
***************************************************************************/
void restore_pillar(int col, int x, int y, int width, int high)
{
    int base_width, pillar_x, pillar_y, pillar_w;
    int x1, x2, y1, y2;

    base_width = HDC_Base_Width * 23;
    pillar_x = HDC_Start_X + col * (base_width + HDC_Underpan_Distance) + HDC_Base_Width * 11;
    pillar_y = HDC_Start_Y - HDC_Base_High * 12;
    pillar_w = HDC_Base_Width;

    x1 = x;
    if (x1 < pillar_x)
        x1 = pillar_x;

    x2 = x + width;
    if (x2 > pillar_x + pillar_w)
        x2 = pillar_x + pillar_w;

    y1 = y;
    if (y1 < pillar_y)
        y1 = pillar_y;

    y2 = y + high;
    if (y2 > HDC_Start_Y)
        y2 = HDC_Start_Y;

    if (x1 < x2 && y1 < y2)
        hdc_rectangle(x1, y1, x2 - x1, y2 - y1, HDC_COLOR[MAX_LAYER + 1]);
}

/***************************************************************************
  函数名称：move_disk
  功    能：执行一个盘子的图形移动(上移-->平移-->下移)
  输入参数：src_top/dst_top 是移动前高度(菜单 8/9 会先更新字符数组，因此必须保存旧高度)
***************************************************************************/
void move_disk(char src, char dst, int disk, int src_top, int dst_top, int skip_first_wait)
{
    int s, d, base_width, disk_width;
    int x, y, target_x, target_y;
    int old_x, old_y, new_x, new_y, move_len;
    int erase_x, draw_x, i, step_x, step_y;

    s = src - 'A';
    d = dst - 'A';
    base_width = HDC_Base_Width * 23;
    disk_width = HDC_Base_Width * (disk * 2 + 1);

    x = HDC_Start_X + s * (base_width + HDC_Underpan_Distance) + (base_width - disk_width) / 2;
    y = HDC_Start_Y - HDC_Base_High * src_top;
    target_x = HDC_Start_X + d * (base_width + HDC_Underpan_Distance) + (base_width - disk_width) / 2;
    target_y = HDC_Start_Y - HDC_Base_High * (dst_top + 1);

    if (delay_time == 0)
    {
        step_x = 1;
        step_y = 1;
    }
    else
    {
        step_x = HDC_Step_X;
        step_y = HDC_Step_Y;
    }

    while (y > HDC_Top_Y)
    {
        if (skip_first_wait)
            skip_first_wait = 0;
        else
            wait_move();

        old_y = y;
        new_y = y - step_y;
        if (new_y < HDC_Top_Y)
            new_y = HDC_Top_Y;
        move_len = old_y - new_y;

        hdc_rectangle(x, old_y + HDC_Base_High - move_len, disk_width, move_len, HDC_COLOR[0]);
        restore_pillar(s, x, old_y + HDC_Base_High - move_len, disk_width, move_len);

        y = new_y;
        hdc_rectangle(x, y, disk_width, move_len, HDC_COLOR[disk]);
    }

    while (x != target_x)
    {
        if (skip_first_wait)
            skip_first_wait = 0;
        else
            wait_move();

        old_x = x;
        if (old_x < target_x)
        {
            new_x = x + step_x;
            if (new_x > target_x)
                new_x = target_x;
            move_len = new_x - old_x;
            erase_x = old_x;
            draw_x = old_x + disk_width;
        }
        else
        {
            new_x = x - step_x;
            if (new_x < target_x)
                new_x = target_x;
            move_len = old_x - new_x;
            erase_x = old_x + disk_width - move_len;
            draw_x = new_x;
        }

        hdc_rectangle(erase_x, y, move_len, HDC_Base_High, HDC_COLOR[0]);
        for (i = 0; i < 3; i++)
            restore_pillar(i, erase_x, y, move_len, HDC_Base_High);

        x = new_x;
        hdc_rectangle(draw_x, y, move_len, HDC_Base_High, HDC_COLOR[disk]);
    }

    while (y < target_y)
    {
        if (skip_first_wait)
            skip_first_wait = 0;
        else
            wait_move();

        old_y = y;
        new_y = y + step_y;
        if (new_y > target_y)
            new_y = target_y;
        move_len = new_y - old_y;

        hdc_rectangle(x, old_y, disk_width, move_len, HDC_COLOR[0]);
        restore_pillar(d, x, old_y, disk_width, move_len);

        y = new_y;
        hdc_rectangle(x, y + HDC_Base_High - move_len, disk_width, move_len, HDC_COLOR[disk]);
    }
}

/***************************************************************************
  函数名称：set_cursor / next_cursor
  功    能：菜单 8/9 中字符数组区的光标定位
***************************************************************************/
void set_cursor(int start_x, int start_y, int col)
{
    int x, base_y;

    x = start_x + Underpan_A_X_OFFSET;
    base_y = start_y + Underpan_A_Y_OFFSET - 1;

    if (col >= 0 && col <= 2 && top[col] > 0)
        cct_gotoxy(x + col * Underpan_Distance + 2, base_y - top[col]);
    else
        cct_gotoxy(Status_Line_X, Status_Line_Y);
}

int next_cursor(int disk)
{
    int i, total, last_step, col1, a, b;

    total = top[0] + top[1] + top[2];
    last_step = 1;
    for (i = 0; i < total; i++)
        last_step = last_step * 2;
    last_step--;

    if (step >= last_step)
        return -1;

    if (disk != 1)
    {
        for (i = 0; i < 3; i++)
            if (top[i] > 0 && tower[i][top[i] - 1] == 1)
                return i;
        return -1;
    }

    col1 = -1;
    for (i = 0; i < 3; i++)
        if (top[i] > 0 && tower[i][top[i] - 1] == 1)
            col1 = i;

    a = -1;
    b = -1;
    for (i = 0; i < 3; i++)
    {
        if (i != col1)
        {
            if (a == -1)
                a = i;
            else
                b = i;
        }
    }

    if (a == -1 || b == -1)
        return -1;
    if (top[a] == 0 && top[b] == 0)
        return -1;
    if (top[a] == 0)
        return b;
    if (top[b] == 0)
        return a;
    if (tower[a][top[a] - 1] < tower[b][top[b] - 1])
        return a;
    return b;
}

/***************************************************************************
  函数名称：move_once
  功    能：处理一次移动
***************************************************************************/
void move_once(char src, char dst, int disk, int type)
{
    int s, d, src_top, dst_top, cursor_col, skip_first_wait;
    int start_x, start_y;

    s = src - 'A';
    d = dst - 'A';

    if (type == 1)
    {
        cout << setw(2) << disk << "# " << src << "-->" << dst << endl;
        return;
    }

    if (type == 2)
    {
        step++;
        cout << "第" << setw(4) << step << " 步("
            << setw(2) << disk << "#: " << src << "-->" << dst << ")" << endl;
        return;
    }

    if (type == 4)
    {
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        if (delay_time == 0)
            cin.get();
        else
            Sleep(delay_time);
    }

    if (type == 3 || type == 4)
    {
        top[s]--;
        tower[s][top[s]] = 0;
        tower[d][top[d]] = disk;
        top[d]++;
        step++;

        if (type == 3)
        {
            cout << "第" << setw(4) << step << " 步("
                << setw(2) << disk << "#: " << src << "-->" << dst << ")  ";
            show_x();
            cout << endl;
        }
        else
        {
            show_all(MenuItem4_Start_X, MenuItem4_Start_Y, 0, disk, src, dst, 0);
            cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        }
        return;
    }

    src_top = top[s];
    dst_top = top[d];
    skip_first_wait = 0;
    start_x = (type == 8 ? MenuItem8_Start_X : MenuItem9_Start_X);
    start_y = (type == 8 ? MenuItem8_Start_Y : MenuItem9_Start_Y);

    if ((type == 8 || type == 9) && delay_time == 0)
    {
        wait_for_enter();
        skip_first_wait = 1;
    }

    top[s]--;
    tower[s][top[s]] = 0;
    tower[d][top[d]] = disk;
    top[d]++;
    step++;

    show_all(start_x, start_y, start_x, disk, src, dst, 1);

    if (type == 8 && step > 7 && delay_time > 0)
        delay_time = -1;

    if (type == 8)
        cursor_col = next_cursor(disk);
    else
        cursor_col = d;
    if (cursor_col == -1)
        cursor_col = d;

    set_cursor(start_x, start_y, cursor_col);
    move_disk(src, dst, disk, src_top, dst_top, skip_first_wait);
    set_cursor(start_x, start_y, cursor_col);
}

/***************************************************************************
  函数名称：hanoi
  功    能：汉诺塔递归函数
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int type)
{
    if (n == 1)
    {
        move_once(src, dst, n, type);
        return;
    }
    hanoi(n - 1, src, dst, tmp, type);
    move_once(src, dst, n, type);
    hanoi(n - 1, tmp, src, dst, type);
}

/***************************************************************************
  函数名称：game_cmd
  功    能：菜单 9 读入人工移动命令，同时完成命令格式检查
  返 回 值：>=0 表示合法格式，编码为 src*3+dst；-1 表示 Q 退出；-2 表示格式错误
***************************************************************************/
int game_cmd()
{
    char src2 = 0, dst2 = 0;
    int num = 0, ch, err;

    clear_line(Status_Line_Y - 1);
    cout << "请输入移动的柱号(命令形式： AC=A顶端的盘子移动到C，Q=退出) ：";

    while ((ch = cin.get()) != '\n' && ch != EOF)
    {
        if (num == 0)
            src2 = char(ch);
        else if (num == 1)
            dst2 = char(ch);
        num++;
    }

    err = 0;
    if (num == 1 && (src2 == 'q' || src2 == 'Q'))
        return -1;
    if (num == 0)
        err = 1;
    else if (num != 2)
        err = 2;
    else
    {
        if (src2 >= 'a' && src2 <= 'c')
            src2 = char(src2 - 32);
        if (dst2 >= 'a' && dst2 <= 'c')
            dst2 = char(dst2 - 32);

        if (src2 < 'A' || src2 > 'C')
            err = 3;
        else if (dst2 < 'A' || dst2 > 'C')
            err = 4;
        else if (src2 == dst2)
            err = 5;
    }

    if (err)
    {
        clear_line(Status_Line_Y - 1);
        if (err == 1)
            cout << "输入错误：没有输入命令，按任意键继续";
        else if (err == 2)
            cout << "输入错误：命令必须是两个字母，按任意键继续";
        else if (err == 3)
            cout << "输入错误：移动前的柱号必须是A-C，按任意键继续";
        else if (err == 4)
            cout << "输入错误：移动后的柱号必须是A-C，按任意键继续";
        else
            cout << "输入错误：移动前后不能是同一根柱，按任意键继续";
        _getch();
        return -2;
    }

    return (src2 - 'A') * 3 + (dst2 - 'A');
}

/***************************************************************************
  菜单1：基本解
***************************************************************************/
void hanoi1()
{
    int n = 0, delay = 0;
    char src = 0, dst = 0, tmp = 0;

    input_hanoi_params(-1, &n, &src, &dst, &delay);
    tmp = char('A' + 'B' + 'C' - src - dst);
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst, 1);
    cout << endl << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单2：基本解(步数记录)
***************************************************************************/
void hanoi2()
{
    int n = 0, delay = 0;
    char src = 0, dst = 0, tmp = 0;

    input_hanoi_params(-1, &n, &src, &dst, &delay);
    tmp = char('A' + 'B' + 'C' - src - dst);
    step = 0;
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst, 2);
    cout << endl << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单3：内部数组显示(横向)
***************************************************************************/
void hanoi3()
{
    int n = 0, delay = 0;
    char src = 0, dst = 0, tmp = 0;

    input_hanoi_params(-1, &n, &src, &dst, &delay);
    tmp = char('A' + 'B' + 'C' - src - dst);
    init_tower_state(n, src);
    step = 0;
    hanoi(n, src, tmp, dst, 3);
    cout << endl << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单4：内部数组显示(纵向+横向)
***************************************************************************/
void hanoi4()
{
    int n = 0;
    char src = 0, dst = 0, tmp = 0;

    input_hanoi_params(200, &n, &src, &dst, &delay_time);
    tmp = char('A' + 'B' + 'C' - src - dst);
    init_tower_state(n, src);
    step = 0;

    cct_cls();
    print_status_line(n, src, dst, 1, delay_time);
    show_all(MenuItem4_Start_X, MenuItem4_Start_Y, 0, 0, src, dst, 0);
    hanoi(n, src, tmp, dst, 4);

    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单5：图形解-预备-画三个圆柱
***************************************************************************/
void hanoi5()
{
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    hdc_init(HDC_COLOR[0], HDC_COLOR[MAX_LAYER + 1]);
    hdc_cls();
    Sleep(100);
    draw3();
    hdc_release();
    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单6：图形解-预备-在起始柱上画n个盘子
***************************************************************************/
void hanoi6()
{
    int n = 0, delay = 0, s;
    char src = 0, dst = 0;

    input_hanoi_params(-1, &n, &src, &dst, &delay);
    init_tower_state(n, src);
    s = src - 'A';

    cct_cls();
    print_status_line(n, src, dst, 0, 0);
    hdc_init(HDC_COLOR[0], HDC_COLOR[MAX_LAYER + 1]);
    hdc_cls();
    Sleep(100);
    draw3();
    draw_disks(s);
    hdc_release();

    cct_gotoxy(Status_Line_X, Status_Line_Y + 2);
    cout << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单7：图形解-预备-第一次移动
***************************************************************************/
void hanoi7()
{
    int n = 0, s;
    char src = 0, dst = 0, tmp = 0, first_dst = 0;

    input_hanoi_params(20, &n, &src, &dst, &delay_time);
    tmp = char('A' + 'B' + 'C' - src - dst);
    first_dst = (n % 2 == 1 ? dst : tmp);
    init_tower_state(n, src);
    s = src - 'A';
    step = 0;

    cct_cls();
    print_status_line(n, src, dst, 1, delay_time);
    hdc_init(HDC_COLOR[0], HDC_COLOR[MAX_LAYER + 1]);
    hdc_cls();
    Sleep(100);
    draw3();
    draw_disks(s);
    if (delay_time > 0)
        Sleep(1000);
    move_disk(src, first_dst, tower[s][top[s] - 1], top[s], top[first_dst - 'A'], 0);
    hdc_release();

    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单8：图形解-自动移动版本
***************************************************************************/
void hanoi8()
{
    int n = 0, old_delay, s;
    char src = 0, dst = 0, tmp = 0;

    input_hanoi_params(20, &n, &src, &dst, &delay_time);
    old_delay = delay_time;
    tmp = char('A' + 'B' + 'C' - src - dst);
    init_tower_state(n, src);
    s = src - 'A';
    step = 0;

    cct_cls();
    print_status_line(n, src, dst, 1, old_delay);
    if (old_delay > 0)
        cout << "（前7步，后面自动变为0ms）";

    hdc_init(HDC_COLOR[0], HDC_COLOR[MAX_LAYER + 1]);
    hdc_cls();
    Sleep(100);
    show_all(MenuItem8_Start_X, MenuItem8_Start_Y, MenuItem8_Start_X, 0, src, dst, 1);
    draw3();
    draw_disks(s);
    set_cursor(MenuItem8_Start_X, MenuItem8_Start_Y, s);
    if (delay_time > 0)
        Sleep(1000);
    hanoi(n, src, tmp, dst, 8);
    hdc_release();

    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    wait_for_enter();
    cct_cls();
}

/***************************************************************************
  菜单9：图形解-游戏版
***************************************************************************/
void hanoi9()
{
    int n = 0, s, d, disk, code, quit = 0;
    char src = 0, dst = 0;

    input_hanoi_params(20, &n, &src, &dst, &delay_time);
    init_tower_state(n, src);
    s = src - 'A';
    step = 0;

    cct_cls();
    print_status_line(n, src, dst, 1, delay_time);
    hdc_init(HDC_COLOR[0], HDC_COLOR[MAX_LAYER + 1]);
    hdc_cls();
    Sleep(100);
    show_all(MenuItem9_Start_X, MenuItem9_Start_Y, MenuItem9_Start_X, 0, src, dst, 1);
    draw3();
    draw_disks(s);

    while (top[dst - 'A'] != n)
    {
        code = game_cmd();
        if (code == -1)
        {
            quit = 1;
            break;
        }
        if (code == -2)
            continue;

        s = code / 3;
        d = code % 3;
        if (top[s] == 0)
        {
            clear_line(Status_Line_Y - 1);
            cout << "输入错误：源柱为空，按任意键继续";
            _getch();
            continue;
        }
        if (top[d] > 0 && tower[s][top[s] - 1] > tower[d][top[d] - 1])
        {
            clear_line(Status_Line_Y - 1);
            cout << "输入错误：大盘不能压在小盘上，按任意键继续";
            _getch();
            continue;
        }

        disk = tower[s][top[s] - 1];
        move_once(char('A' + s), char('A' + d), disk, 9);
    }

    hdc_release();
    clear_line(Status_Line_Y - 1);
    if (quit)
        cout << "游戏退出，按回车键继续";
    else
        cout << "游戏结束，按回车键继续";
    wait_for_enter();
    cct_cls();
}

