/* 个人信息已删除 */
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "cmd_console_tools.h"
#include "color_linez.h"
using namespace std;

/***************************************************************************
  函数名称：parse_coord
  功    能：将字母+数字形式的坐标转换为数组下标
  输入参数：const char coord[]：用户输入的坐标字符串
			const int row     ：棋盘的行数
			const int col     ：棋盘的列数
			int& r            ：转换后的行下标
			int& c            ：转换后的列下标
  返 回 值：1表示转换成功，0表示坐标格式错误或越界
  说    明：支持大小写字母，例如 a7、A7 均可识别
***************************************************************************/
int parse_coord(const char coord[], const int row, const int col, int& r, int& c)
{
	char row_ch = coord[0];
	char col_ch = coord[1];

	if (row_ch >= 'a' && row_ch <= 'z')
		row_ch = row_ch - 32;

	if (coord[2] != '\0')
		return 0;

	if (row_ch < 'A' || row_ch > 'I')
		return 0;

	if (col_ch < '1' || col_ch > '9')
		return 0;

	r = row_ch - 'A';
	c = col_ch - '1';

	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;

	return 1;
}

/***************************************************************************
  函数名称：input_move_coord
  功    能：输入并检查彩球移动坐标
  输入参数：const int board[][MAX_SIZE]：棋盘二维数组
			const int row              ：棋盘的行数
			const int col              ：棋盘的列数
			const int is_start         ：是否为起始坐标，1为起点，0为终点
			int& r                     ：转换后的行下标
			int& c                     ：转换后的列下标
  说    明：起点必须有球，终点必须为空；输入格式为字母+数字，例如 c2
***************************************************************************/
void input_move_coord(const int board[][MAX_SIZE], const int row, const int col,
	const int is_start, int& r, int& c)
{
	char coord[100];
	int ch;
	int x, y;

	if (is_start)
		cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
	else
		cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";

	cct_getxy(x, y);

	while (1)
	{
		cin.getline(coord, 100);

		if (cin.fail())
		{
			cin.clear();
			while ((ch = cin.get()) != '\n' && ch != EOF)
				continue;
			coord[0] = '\0';
		}

		if (!parse_coord(coord, row, col, r, c))
		{
			show_error_and_back(x, y, "输入错误，请重新输入.");
			continue;
		}

		if (is_start && board[r][c] == 0)
		{
			show_error_and_back(x, y, "起始位置为空，请重新输入.");
			continue;
		}

		if (!is_start && board[r][c] != 0)
		{
			show_error_and_back(x, y, "目标位置非空，请重新输入.");
			continue;
		}

		cct_showstr(0, y + 1, "", COLOR_BLACK, COLOR_WHITE, 1, 80);
		cct_gotoxy(0, y + 1);
		cout << "输入为" << char('A' + r) << "行" << c + 1 << "列" << endl;

		break;
	}
}

/***************************************************************************
  函数名称：color_linez_A
  功    能：菜单A，随机生成初始5个彩球并打印内部数组
  说    明：输入行列后，在指定范围内随机生成5个球的位置
***************************************************************************/
void color_linez_A()
{
	cct_setconsoletitle("  A. 内部数组，随机生成初始5个球");
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	make_random_board(board, row, col, 5);
	print_matrix(board, board, row, col, "初始数组：", 0);

	wait_for_end();
}

/***************************************************************************
  函数名称：color_linez_B
  功    能：菜单B，随机生成60%的彩球并寻找移动路径
  说    明：起始位置必须有球，目的位置必须为空，若有通路则输出查找结果和路径
***************************************************************************/
void color_linez_B()
{
	cct_setconsoletitle("  B. 内部数组，随机生成60%的球，寻找移动路径");
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];
	int path[MAX_SIZE][MAX_SIZE];
	int start_r, start_c;
	int dest_r, dest_c;
	int ball_count;
	int found;
	int b1, b2, b3;

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	ball_count = row * col * 6 / 10;
	make_random_board(board, row, col, ball_count);

	print_matrix(board, path, row, col, "当前数组：", 0);

	b1 = rand() % 7 + 1;
	b2 = rand() % 7 + 1;
	b3 = rand() % 7 + 1;
	cout << endl << "下3个彩球的颜色分别是： " << b1 << " " << b2 << " " << b3 << endl;

	input_move_coord(board, row, col, 1, start_r, start_c);
	input_move_coord(board, row, col, 0, dest_r, dest_c);

	found = find_move_path(board, row, col, start_r, start_c, dest_r, dest_c, path);

	if (found)
	{
		print_matrix(board, path, row, col, "查找结果数组：", 1);
		print_matrix(board, path, row, col, "移动路径(不同色标识)：", 2);
	}
	else
	{
		cout << endl << "无法找到移动路径." << endl;
	}

	wait_for_end();
}

/***************************************************************************
  函数名称：color_linez_C
  功    能：菜单C，内部数组完整版彩球游戏
  说    明：完成移动、生成新球、五连消除、得分统计和游戏结束判断
***************************************************************************/
void color_linez_C()
{
	cct_setconsoletitle("  C. 内部数组，完整版");
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];
	int path[MAX_SIZE][MAX_SIZE];
	int show_mark[MAX_SIZE][MAX_SIZE];
	int next_balls[3];
	int start_r, start_c;
	int dest_r, dest_c;
	int found;
	int turn_score;
	int total_score = 0;

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	make_random_board(board, row, col, 5);

	while (1)
	{
		clear_mark_array(show_mark);
		print_matrix(board, show_mark, row, col, "当前数组：", 0);
		make_next_balls(next_balls);
		cout << endl << "下3个彩球的颜色分别是： " << next_balls[0] << " " << next_balls[1] << " " << next_balls[2] << endl;

		if (count_empty_grid(board, row, col) == 0)
		{
			cout << "无空位可移动，游戏结束!" << endl;
			break;
		}

		while (1)
		{
			input_move_coord(board, row, col, 1, start_r, start_c);
			input_move_coord(board, row, col, 0, dest_r, dest_c);

			clear_mark_array(path);
			found = find_move_path(board, row, col, start_r, start_c, dest_r, dest_c, path);

			if (found)
				break;

			cout << endl << "无法找到移动路径." << endl;
		}

		clear_mark_array(show_mark);

		board[dest_r][dest_c] = board[start_r][start_c];
		board[start_r][start_c] = 0;

		show_mark[dest_r][dest_c] = 1;
		turn_score = clear_five_lines(board, row, col);

		if (turn_score == 0)
		{
			add_next_balls(board, show_mark, row, col, next_balls);
			turn_score = clear_five_lines(board, row, col);
		}

		total_score += turn_score;

		print_matrix(board, show_mark, row, col, "移动后的数组：", 0);

		cout << endl << "本次得分：" << turn_score << " 总得分：" << total_score << endl << endl;
	}

	wait_for_end();
}

