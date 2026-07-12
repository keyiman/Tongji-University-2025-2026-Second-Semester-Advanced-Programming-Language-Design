/* 个人信息已删除 */
/* 加入必要的头文件、命名空间、你觉得应该属于工具类的其它函数 */
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "cmd_console_tools.h"
#include "color_linez.h"

using namespace std;
/***************************************************************************
  函数名称：to_be_continued
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;
	cout << endl;
	//cct_cls();

	return;
}

/***************************************************************************
  函数名称：is_end_word
  功    能：判断输入的字符串是否为结束标志（END/end）
  输入参数：字符串（不区分大小写）
  返 回 值：1：是；0：不是
***************************************************************************/
int is_end_word(const char word[])
{
	if ((word[0] == 'E' || word[0] == 'e') &&
		(word[1] == 'N' || word[1] == 'n') &&
		(word[2] == 'D' || word[2] == 'd') &&
		word[3] == '\0')
		return 1;
	return 0;
}

/***************************************************************************
  函数名称：show_error_and_back
  功    能：显示错误提示，并将光标重新定位到原输入位置
  输入参数：const int x     ：原输入位置的X坐标
			const int y     ：原输入位置的Y坐标
			const char msg[]：错误提示信息
  说    明：错误处理统一按“下一行显示错误，清除原输入，光标回到输入位置”的形式
***************************************************************************/
void show_error_and_back(const int x, const int y, const char msg[])
{
	cct_showstr(0, y + 1, "", COLOR_BLACK, COLOR_WHITE, 1, 80);
	cct_gotoxy(0, y + 1);
	cout << msg;

	cct_showstr(x, y, "", COLOR_BLACK, COLOR_WHITE, 1, 80 - x);
	cct_gotoxy(x, y);
}

/***************************************************************************
  函数名称：input_range_value
  功    能：输入一个指定范围内的整数值
  输入参数：const char prompt[]：输入提示信息
  返 回 值：输入的整数值
  说    明：本题中用于输入 7-9 范围内的行数或列数
***************************************************************************/
int input_range_value(const char prompt[])
{
	char input[100];
	int value;
	int ch;
	int x, y;

	cout << prompt << endl;
	cct_getxy(x, y);

	while (1)
	{
		input[0] = '\0';
		cin.getline(input, 100);

		if (cin.fail())
		{
			cin.clear();
			while ((ch = cin.get()) != '\n' && ch != EOF)
				continue;
			input[0] = '\0';
		}

		if (input[0] >= '7' && input[0] <= '9' && input[1] == '\0')
		{
			value = input[0] - '0';

			cct_showstr(0, y + 1, "", COLOR_BLACK, COLOR_WHITE, 1, 80);
			cct_gotoxy(0, y + 1);

			return value;
		}

		show_error_and_back(x, y, "输入错误，请重新输入.                  ");
	}
}

/***************************************************************************
  函数名称：make_random_board
  功    能：初始化棋盘并随机生成指定数量的彩球
  输入参数：int board[][MAX_SIZE]：棋盘二维数组
			const int row        ：棋盘的行数
			const int col        ：棋盘的列数
			const int ball_count ：需要生成的彩球数量
  说    明：先将棋盘清零，再随机生成彩球；如果随机位置已有彩球，则重新随机
***************************************************************************/
void make_random_board(int board[][MAX_SIZE], const int row, const int col, const int ball_count)
{
	int cnt = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			board[i][j] = 0;

	while (cnt < ball_count)
	{
		int r = rand() % row;
		int c = rand() % col;

		if (board[r][c] == 0)
		{
			board[r][c] = rand() % 7 + 1;
			cnt++;
		}
	}
}

/***************************************************************************
  函数名称：find_move_path
  功    能：寻找从起点到终点的可移动路径
  输入参数：const int board[][MAX_SIZE]：棋盘二维数组
			const int row              ：棋盘的行数
			const int col              ：棋盘的列数
			const int sr               ：起点行下标
			const int sc               ：起点列下标
			const int dr               ：终点行下标
			const int dc               ：终点列下标
			int path[][MAX_SIZE]       ：路径标记数组
  返 回 值：1表示找到路径，0表示没有路径
  说    明：使用数组模拟队列进行广度优先搜索，路径不要求最短但本实现可找到较短路径
***************************************************************************/
int find_move_path(const int board[][MAX_SIZE], const int row, const int col,
	const int sr, const int sc, const int dr, const int dc,
	int path[][MAX_SIZE])
{
	int visited[MAX_SIZE][MAX_SIZE];
	int pre_r[MAX_SIZE][MAX_SIZE];
	int pre_c[MAX_SIZE][MAX_SIZE];
	int q_r[MAX_SIZE * MAX_SIZE];
	int q_c[MAX_SIZE * MAX_SIZE];
	int front = 0, rear = 0;
	int dir_r[4] = { -1, 1, 0, 0 };
	int dir_c[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			visited[i][j] = 0;
			pre_r[i][j] = -1;
			pre_c[i][j] = -1;
			path[i][j] = 0;
		}
	}

	visited[sr][sc] = 1;
	q_r[rear] = sr;
	q_c[rear] = sc;
	rear++;

	while (front < rear)
	{
		int cr = q_r[front];
		int cc = q_c[front];
		front++;

		if (cr == dr && cc == dc)
			break;

		for (int k = 0; k < 4; k++)
		{
			int nr = cr + dir_r[k];
			int nc = cc + dir_c[k];

			if (nr < 0 || nr >= row || nc < 0 || nc >= col)
				continue;

			if (visited[nr][nc])
				continue;

			if (board[nr][nc] != 0)
				continue;

			visited[nr][nc] = 1;
			pre_r[nr][nc] = cr;
			pre_c[nr][nc] = cc;
			q_r[rear] = nr;
			q_c[rear] = nc;
			rear++;
		}
	}

	if (!visited[dr][dc])
		return 0;

	int tr = dr;
	int tc = dc;

	while (!(tr == sr && tc == sc))
	{
		path[tr][tc] = 1;

		int pr = pre_r[tr][tc];
		int pc = pre_c[tr][tc];

		tr = pr;
		tc = pc;
	}

	path[sr][sc] = 1;

	return 1;
}

/***************************************************************************
  函数名称：clear_mark_array
  功    能：清空标记数组
  输入参数：int mark[][MAX_SIZE]：标记数组
  说    明：用于记录移动位置、新生成球位置、查找结果等
***************************************************************************/
void clear_mark_array(int mark[][MAX_SIZE])
{
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			mark[i][j] = 0;
}

/***************************************************************************
  函数名称：count_empty_grid
  功    能：统计棋盘中的空位置数量
  输入参数：const int board[][MAX_SIZE]：棋盘二维数组
			const int row              ：棋盘的行数
			const int col              ：棋盘的列数
  返 回 值：空位置数量
  说    明：空位置用0表示
***************************************************************************/
int count_empty_grid(const int board[][MAX_SIZE], const int row, const int col)
{
	int cnt = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (board[i][j] == 0)
				cnt++;

	return cnt;
}

/***************************************************************************
  函数名称：make_next_balls
  功    能：随机生成下3个彩球的颜色编号
  输入参数：int next_balls[]：保存下3个彩球颜色编号的数组
  说    明：颜色编号范围为1-7
***************************************************************************/
void make_next_balls(int next_balls[])
{
	for (int i = 0; i < 3; i++)
		next_balls[i] = rand() % 7 + 1;
}

/***************************************************************************
  函数名称：add_next_balls
  功    能：将下3个彩球随机加入棋盘空位置
  输入参数：int board[][MAX_SIZE]：棋盘二维数组
			int mark[][MAX_SIZE] ：新生成彩球位置标记数组
			const int row        ：棋盘的行数
			const int col        ：棋盘的列数
			const int next_balls[]：下3个彩球颜色编号
  返 回 值：实际加入的彩球数量
  说    明：如果空位不足3个，则有几个空位加几个球
***************************************************************************/
int add_next_balls(int board[][MAX_SIZE], int mark[][MAX_SIZE],
	const int row, const int col, const int next_balls[])
{
	int empty_cnt = count_empty_grid(board, row, col);
	int add_cnt = 3;

	if (empty_cnt < 3)
		add_cnt = empty_cnt;

	for (int k = 0; k < add_cnt; k++)
	{
		while (1)
		{
			int r = rand() % row;
			int c = rand() % col;

			if (board[r][c] == 0)
			{
				board[r][c] = next_balls[k];
				mark[r][c] = 1;
				break;
			}
		}
	}

	return add_cnt;
}

/***************************************************************************
  函数名称：clear_five_lines
  功    能：查找并消除连续5个及以上同色彩球
  输入参数：int board[][MAX_SIZE]：棋盘二维数组
			const int row        ：棋盘的行数
			const int col        ：棋盘的列数
  返 回 值：本次消除得到的分数
  说    明：横向、纵向、两条斜向均检查；长度为n时得分为(n-1)*(n-2)
***************************************************************************/
int clear_five_lines(int board[][MAX_SIZE], const int row, const int col)
{
	int remove_mark[MAX_SIZE][MAX_SIZE];
	int dir_r[4] = { 0, 1, 1, 1 };
	int dir_c[4] = { 1, 0, 1, -1 };
	int score = 0;

	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			remove_mark[i][j] = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 0)
				continue;

			for (int d = 0; d < 4; d++)
			{
				int pr = i - dir_r[d];
				int pc = j - dir_c[d];

				if (pr >= 0 && pr < row && pc >= 0 && pc < col &&
					board[pr][pc] == board[i][j])
					continue;

				int len = 0;
				int r = i;
				int c = j;

				while (r >= 0 && r < row && c >= 0 && c < col &&
					board[r][c] == board[i][j])
				{
					len++;
					r += dir_r[d];
					c += dir_c[d];
				}

				if (len >= 5)
				{
					score += (len - 1) * (len - 2);

					r = i;
					c = j;

					for (int k = 0; k < len; k++)
					{
						remove_mark[r][c] = 1;
						r += dir_r[d];
						c += dir_c[d];
					}
				}
			}
		}
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (remove_mark[i][j])
				board[i][j] = 0;

	return score;
}

/***************************************************************************
  函数名称：wait_for_end
  功    能：等待用户输入结束标志（End），用于每小题结束后的提示
***************************************************************************/
void wait_for_end()
{
	char word[4];
	char ch;
	int len;
	int too_long;
	int x, y;

	cout << endl << "本小题结束，请输入End继续...";
	cct_getxy(x, y);

	while (1)
	{
		len = 0;
		too_long = 0;
		word[0] = '\0';

		while (1)
		{
			if (!cin.get(ch))
			{
				cin.clear();
				too_long = 1;
				break;
			}
			if (ch == '\n')
				break;
			if (len < 3)
			{
				word[len] = ch;
				len++;
				word[len] = '\0';
			}
			else
			{
				too_long = 1;
			}
		}

		if (too_long == 0 && is_end_word(word))
			break;

		show_error_and_back(x, y, "输入错误，请重新输入.");
	}
}

/***************************************************************************
  函数名称：print_matrix
  功    能：统一打印普通数组、查找结果数组和带路径标记的数组
  输入参数：const int board[][MAX_SIZE]：棋盘二维数组
			const int path[][MAX_SIZE] ：路径标记数组
			const int row              ：棋盘的行数
			const int col              ：棋盘的列数
			const char title[]         ：打印标题
			const int mode             ：打印模式，0普通数组，1查找结果，2带路径数组
  说    明：mode为0时按彩球颜色打印；mode为1时路径用*表示；mode为2时路径用不同颜色标识；mode为3时只给有球的标记位置标色
***************************************************************************/
void print_matrix(const int board[][MAX_SIZE], const int path[][MAX_SIZE],
	const int row, const int col, const char title[], const int mode)
{
	int colors[8] =
	{
		COLOR_WHITE,
		COLOR_HRED,
		COLOR_HGREEN,
		COLOR_HBLUE,
		COLOR_HCYAN,
		COLOR_YELLOW,
		COLOR_HPINK,
		COLOR_WHITE
	};

	cout << endl << title << endl;

	cout << "  |";
	for (int j = 1; j <= col; j++)
		cout << "  " << j;
	cout << endl;

	cout << "--+";
	for (int j = 1; j <= col; j++)
		cout << "---";
	cout << endl;

	for (int i = 0; i < row; i++)
	{
		cout << char('A' + i) << " |";

		for (int j = 0; j < col; j++)
		{
			cout << "  ";

			if (mode == 1)
			{
				if (path[i][j] == 1)
					cout << '*';
				else
					cout << 0;
			}
			else if (mode == 2)
			{
				if (path[i][j] == 1)
				{
					cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
					cout << board[i][j];
					cct_setcolor();
				}
				else
					cout << board[i][j];
			}
			else if (mode == 3)
			{
				if (path[i][j] == 1 && board[i][j] != 0)
				{
					cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
					cout << board[i][j];
					cct_setcolor();
				}
				else
				{
					cout << board[i][j];
				}
			}
			else
			{
				if (board[i][j] == 0)
					cout << 0;
				else
				{
					cct_setcolor(COLOR_HYELLOW, colors[board[i][j]]);
					cout << board[i][j];
					cct_setcolor();
				}
			}
		}
		cout << endl;
	}
}



