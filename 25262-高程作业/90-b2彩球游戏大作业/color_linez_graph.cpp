/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "cmd_console_tools.h"
#include "color_linez.h"
using namespace std;

/***************************************************************************
  函数名称：graph_color
  功    能：根据彩球编号返回图形界面使用的背景色
  输入参数：const int ball：彩球编号
  返 回 值：颜色编号
  说    明：彩球编号为1-7，颜色不要求与demo完全一致，清晰可分辨即可
***************************************************************************/
int graph_color(const int ball)
{
	int color[8] =
	{
		COLOR_HWHITE,
		COLOR_HGREEN,
		COLOR_HCYAN,
		COLOR_HBLUE,
		COLOR_HRED,
		COLOR_HPINK,
		COLOR_YELLOW,
		COLOR_HBLACK
	};

	if (ball >= 1 && ball <= 7)
		return color[ball];

	return COLOR_HWHITE;
}

/***************************************************************************
  函数名称：draw_graph_title
  功    能：显示图形界面的屏幕行列提示
  输入参数：const int row：棋盘行数
			const int col：棋盘列数
  返 回 值：
  说    明：只显示图形所需行列值，不修改控制台窗口大小
***************************************************************************/
void draw_graph_title(int grid, const int row, const int col)
{
	int screen_row = grid == 0 ? row + 6 : 2 * row + 5;
	int screen_col = (grid == 0 ? 2 * col + 3 : 4 * col + 3) > 35 ? (grid == 0 ? 2 * col + 3 : 4 * col + 3) : 35;

	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "屏幕：" << screen_row << "行" << screen_col << "列";
}

/***************************************************************************
  函数名称：print_board_canvas
  功    能：画cmd伪图形界面的棋盘框架，并画球
  输入参数：const int board[][MAX_SIZE]：棋盘二维数组
			const int row              ：棋盘行数
			const int col              ：棋盘列数
			const int grid             ：是否显示分隔线，0无分隔线，1有分隔线
			const int fast             ：是否快速绘制，0带少量延时，1无延时
  返 回 值：
  说    明：从屏幕最左边开始画；棋盘紧接在“屏幕：x行x列”下方；
			先画边框，再动画填充内部，填充到有球位置时立即显示彩球
***************************************************************************/
void print_board_canvas(const int board[][MAX_SIZE], const int row, const int col, const int grid, const int fast)
{
	int delay_time;
	int x, y;

	if (fast)
		delay_time = 0;
	else
		delay_time = 20;

	cct_setcursor(CCT_CURSOR_INVISIBLE);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);

	// 情况 1：无分隔线 (grid == 0)
	if (grid == 0)
	{
		int top = 1;
		/* 画上边框 */
		cct_showstr(0, top, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 1; i < col; i++)
		{
			cct_delay(delay_time);
			cct_showstr(2 * i, top, "═", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_delay(delay_time);
		cct_showstr(2 * col, top, "═╗", COLOR_HWHITE, COLOR_BLACK, 1);

		/* 画左右边框 */
		for (int i = 1; i <= row; i++)
		{
			cct_showstr(0, top + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(2 + 2 * col, top + i, "║", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_delay(delay_time);
		}

		/* 画下边框 */
		cct_showstr(0, top + row + 1, "╚", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 1; i < col; i++)
		{
			cct_delay(delay_time);
			cct_showstr(2 * i, top + row + 1, "═", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_delay(delay_time);
		cct_showstr(2 * col, top + row + 1, "═╝", COLOR_HWHITE, COLOR_BLACK, 1);

		/* 动画填充内部区域，填到有球位置时立即画球 */
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				x = 2 + 2 * j;
				y = top + 1 + i;

				cct_delay(delay_time);
				cct_showstr(x, y, "", COLOR_HWHITE, COLOR_HWHITE, 1, 2);

				if (board[i][j] != 0)
				{
					cct_setcolor(graph_color(board[i][j]), COLOR_HWHITE);
					cct_gotoxy(x, y);
					cout << "○";
					cct_setcolor();
				}
			}
		}
	}

	// 情况 2：有分隔线 (grid == 1)
	if (grid)
	{
		int top = 1;
		/* 画上边框 */
		cct_showstr(0, top, "╔", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 1; i < col; i++)
		{
			cct_delay(delay_time);
			cct_showstr(4 * i - 2, top, "═╦", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_delay(delay_time);
		cct_showstr(4 * col - 2, top, "═╗", COLOR_HWHITE, COLOR_BLACK, 1);
		top++;

		/* 画第二行 */
		cct_showstr(0, top, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 1; i < col; i++)
		{
			cct_delay(delay_time);
			cct_showstr(4 * i - 2, top, "  ║", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_delay(delay_time);
		cct_showstr(4 * col - 2, top, "  ║", COLOR_HWHITE, COLOR_BLACK, 1);
		top++;

		/* 画中间部分 */
		while (top <= 2 * row - 1)
		{
			cct_showstr(0, top, "╠", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int i = 1; i < col; i++)
			{
				cct_delay(delay_time);
				cct_showstr(4 * i - 2, top, "═╬", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_delay(delay_time);
			cct_showstr(4 * col - 2, top, "═╣", COLOR_HWHITE, COLOR_BLACK, 1);
			top++;

			cct_showstr(0, top, "║", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int i = 1; i < col; i++)
			{
				cct_delay(delay_time);
				cct_showstr(4 * i - 2, top, "  ║", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_delay(delay_time);
			cct_showstr(4 * col - 2, top, "  ║", COLOR_HWHITE, COLOR_BLACK, 1);
			top++;
		}

		/* 画下边框 */
		cct_showstr(0, top, "╚", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 1; i < col; i++)
		{
			cct_delay(delay_time);
			cct_showstr(4 * i - 2, top, "═╩", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_delay(delay_time);
		cct_showstr(4 * col - 2, top, "═╝", COLOR_HWHITE, COLOR_BLACK, 1);

		/* 画球 */
		top = 1;

		if (fast)
			delay_time = 0;
		else
			delay_time = 5;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cct_gotoxy(2 + 4 * j, top + 1 + i * 2);
				cct_delay(delay_time);
				if (board[i][j] == 0)
					continue;

				cct_setcolor(graph_color(board[i][j]), COLOR_HWHITE);
				cout << "○";

				cct_delay(delay_time);
			}
		}
	}

	cct_setcolor();
	cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
}

/***************************************************************************
  函数名称：print_score_canvas
  功    能：打印得分框
***************************************************************************/
void print_score_canvas(int score)
{
	int top = 1;
	char score_msg[30];

	cct_showstr(40, top, "╔═════╗", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(40, top + 1, "║          ║", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(40, top + 2, "╚═════╝", COLOR_HWHITE, COLOR_BLACK, 1);
	sprintf(score_msg, "得分: %d", score);
	cct_showstr(42, top + 1, score_msg, COLOR_HWHITE, COLOR_BLACK, 1);
}

/***************************************************************************
  函数名称：print_next_3_balls_canvas
  功    能：打印下三个彩球预告框
***************************************************************************/
void print_next_3_balls_canvas(int next_balls[])
{
	int top = 5;
	cct_showstr(40, top, "╔═╦═╦═╗", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(40, top + 1, "║  ║  ║  ║", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(40, top + 2, "╚═╩═╩═╝", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0; i < 3; i++)
	{
		cct_gotoxy(42 + 4 * i, top + 1);
		cct_setcolor(graph_color(next_balls[i]), COLOR_HWHITE);
		cout << "○";
	}
	cct_setcolor();
}

/***************************************************************************
  函数名称：print_status_of_all_cells_canvas
  功    能：打印全局状态和消除统计信息
***************************************************************************/
void print_status_of_all_cells_canvas(int board[][MAX_SIZE], int row, int col, int clear_counts[])
{
	int top = 9;
	char status_of_cell[60];
	int counts[8] = { 0 };

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			counts[board[i][j]]++;

	int total_cells = row * col;

	cct_showstr(40, top, "╔══════════════╗", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0; i < 8; i++)
	{
		cct_showstr(40, top + i + 1, "║                            ║", COLOR_HWHITE, COLOR_BLACK, 1);

		double pct = (double)counts[i] / total_cells * 100.0;
		if (i == 0)
		{
			sprintf(status_of_cell, "  :%02d/(%6.2f%%) 消除-%d", counts[i], pct, clear_counts[i]);
			cct_showstr(42, top + i + 1, status_of_cell, COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else
		{
			cct_gotoxy(42, top + i + 1);
			cct_setcolor(graph_color(i), COLOR_HWHITE);
			cout << "○";
			sprintf(status_of_cell, ":%02d/(%6.2f%%) 消除-%d", counts[i], pct, clear_counts[i]);
			cct_showstr(44, top + i + 1, status_of_cell, COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}
	cct_showstr(40, top + 9, "╚══════════════╝", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();
}

/***************************************************************************
  函数名称：get_mouse_grid_click
  功    能：将鼠标屏幕坐标转换为棋盘数组下标
  输入参数：const int MX  ：鼠标X坐标
			const int MY  ：鼠标Y坐标
			const int row ：棋盘行数
			const int col ：棋盘列数
			int &r        ：转换后的行下标（引用返回）
			int &c        ：转换后的列下标（引用返回）
  返 回 值：true表示点击在合法网格内，false表示非法
  说    明：根据print_canvas绘制的带分隔线棋盘规律进行换算
***************************************************************************/
bool get_mouse_grid_click(int MX, int MY, int row, int col, int& r, int& c)
{
	if (MY >= 2 && (MY - 2) % 2 == 0)
	{
		if (MX >= 2 && (MX % 4 == 2 || MX % 4 == 3))
		{
			r = (MY - 2) / 2;
			c = MX / 4;
			if (r >= 0 && r < row && c >= 0 && c < col)
			{
				return true;
			}
		}
	}
	return false;
}

/***************************************************************************
  函数名称：animate_move
  功    能：在图形界面上演示彩球沿路径跨越分隔线的动画过程
  输入参数：int board[][MAX_SIZE]     ：棋盘二维数组
			const int row             ：棋盘行数
			const int col             ：棋盘列数
			const int start_r         ：起点行下标
			const int start_c         ：起点列下标
			const int dest_r          ：终点行下标
			const int dest_c          ：终点列下标
			const int path[][MAX_SIZE]：由find_move_path生成的路径数组
  返 回 值：
  说    明：分半步移动，擦除旧位置并在分隔线上补画中文边框线，避免留白
***************************************************************************/
void animate_move(int board[][MAX_SIZE], int row, int col, int start_r, int start_c, int dest_r, int dest_c, int path[][MAX_SIZE])
{
	int curr_r = start_r, curr_c = start_c;
	int ball_color = board[curr_r][curr_c];
	board[curr_r][curr_c] = 0;

	int anim_visited[MAX_SIZE][MAX_SIZE] = { 0 };
	anim_visited[curr_r][curr_c] = 1;
	int dir_r[4] = { -1, 1, 0, 0 };
	int dir_c[4] = { 0, 0, -1, 1 };

	while (curr_r != dest_r || curr_c != dest_c)
	{
		int next_r = -1, next_c = -1;
		for (int k = 0; k < 4; ++k)
		{
			int nr = curr_r + dir_r[k];
			int nc = curr_c + dir_c[k];
			if (nr >= 0 && nr < row && nc >= 0 && nc < col && path[nr][nc] == 1 && !anim_visited[nr][nc])
			{
				next_r = nr;
				next_c = nc;
				break;
			}
		}

		int X = 2 + curr_c * 4;
		int Y = 2 + curr_r * 2;
		int nX = 2 + next_c * 4;
		int nY = 2 + next_r * 2;
		int mX = (X + nX) / 2;
		int mY = (Y + nY) / 2;

		cct_showstr(X, Y, "", COLOR_HWHITE, COLOR_HWHITE, 1, 2);

		cct_setcolor(graph_color(ball_color), COLOR_HWHITE);
		cct_gotoxy(mX, mY);
		cout << "○";
		cct_delay(30);

		if (curr_r == next_r)
		{
			cct_showstr(mX, mY, "║", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else
		{
			cct_showstr(mX, mY, "═", COLOR_HWHITE, COLOR_BLACK, 1);
		}

		cct_setcolor(graph_color(ball_color), COLOR_HWHITE);
		cct_gotoxy(nX, nY);
		cout << "○";
		cct_delay(30);

		curr_r = next_r;
		curr_c = next_c;
		anim_visited[curr_r][curr_c] = 1;
	}
	board[dest_r][dest_c] = ball_color;
}

/***************************************************************************
  函数名称：read_mouse
  功    能：读取鼠标操作并在图形界面控制移动逻辑
  返 回 值：移动成功返回true，右键退出则返回false
***************************************************************************/
bool read_mouse(int board[][MAX_SIZE], int row, int col)
{
	int MX, MY, MAction, keycode1, keycode2 = 0;
	int status = 0; // 0: 选择起始球, 1: 选择目标空位
	int selected_r = -1, selected_c = -1;

	cct_setcursor(CCT_CURSOR_INVISIBLE);
	cct_enable_mouse();

	while (1)
	{
		int event = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (event == CCT_MOUSE_EVENT)
		{
			int r = -1, c = -1;
			bool is_valid_mouse = get_mouse_grid_click(MX, MY, row, col, r, c);

			if (is_valid_mouse)
			{
				char position_of_mouse[30];
				sprintf(position_of_mouse, "[当前光标] %c行%d列", 'A' + r, c + 1);
				cct_showstr(0, row * 2 + 2, position_of_mouse, COLOR_BLACK, COLOR_WHITE, 1, 40);
			}
			else
			{
				cct_showstr(0, row * 2 + 2, "[当前光标] 位置非法", COLOR_BLACK, COLOR_WHITE, 1, 40);
			}

			if (MAction == MOUSE_RIGHT_BUTTON_CLICK)
				return false;

			if (MAction == MOUSE_LEFT_BUTTON_CLICK && is_valid_mouse)
			{
				if (status == 0)
				{
					if (board[r][c] != 0)
					{
						selected_r = r;
						selected_c = c;
						status = 1;
						cct_gotoxy(2 + c * 4, 2 + r * 2);
						cct_setcolor(graph_color(board[selected_r][selected_c]), COLOR_HWHITE);
						cout << "◎";
					}
				}
				else if (status == 1)
				{
					if (board[r][c] != 0)
					{
						cct_setcolor(graph_color(board[selected_r][selected_c]), COLOR_HWHITE);
						cct_gotoxy(2 + selected_c * 4, 2 + selected_r * 2);
						cout << "○";

						selected_r = r;
						selected_c = c;
						cct_gotoxy(2 + c * 4, 2 + r * 2);
						cct_setcolor(graph_color(board[selected_r][selected_c]), COLOR_HWHITE);
						cout << "◎";
					}
					else
					{
						int path[MAX_SIZE][MAX_SIZE];
						clear_mark_array(path);
						if (find_move_path(board, row, col, selected_r, selected_c, r, c, path))
						{
							char hint_of_move[60];
							sprintf(hint_of_move, "[提示] 可以从[%c%d]移到[%c%d]             ", 'A' + selected_r, selected_c + 1, 'A' + r, c + 1);
							cct_showstr(0, row * 2 + 2, hint_of_move, COLOR_BLACK, COLOR_WHITE, 1, 40);

							animate_move(board, row, col, selected_r, selected_c, r, c, path);
							return true; // Successfully moved
						}
						else
						{
							char error_msg[60];
							sprintf(error_msg, "[错误] 无法从[%c%d]移动到[%c%d]                ", 'A' + selected_r, selected_c + 1, 'A' + r, c + 1);
							cct_showstr(0, row * 2 + 2, error_msg, COLOR_BLACK, COLOR_RED, 1, 40);

							cct_setcolor(graph_color(board[selected_r][selected_c]), COLOR_HWHITE);
							cct_gotoxy(2 + selected_c * 4, 2 + selected_r * 2);
							cout << "◎";

							status = 1;
						}
					}
				}
			}
		}
	}
	cct_disable_mouse();
	cct_setcolor();
	cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
	return false;
}

/***************************************************************************
  4个局部刷新UI函数
***************************************************************************/

void update_score_canvas(int score)
{
	char score_msg[30];
	sprintf(score_msg, "得分: %-4d", score);
	cct_showstr(42, 2, score_msg, COLOR_HWHITE, COLOR_BLACK, 1);
}

void update_next_3_balls_canvas(int next_balls[])
{
	for (int i = 0; i < 3; i++)
	{
		cct_gotoxy(42 + 4 * i, 6);
		cct_setcolor(graph_color(next_balls[i]), COLOR_HWHITE);
		cout << "○";
	}
	cct_setcolor();
}

void update_status_of_all_cells_canvas(int board[][MAX_SIZE], int row, int col, int clear_counts[])
{
	int counts[8] = { 0 };
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			counts[board[i][j]]++;

	int total_cells = row * col;
	char status_of_cell[60];

	for (int i = 0; i < 8; i++)
	{
		double pct = (double)counts[i] / total_cells * 100.0;
		if (i == 0)
		{
			sprintf(status_of_cell, "  :%02d/(%6.2f%%) 消除-%-4d", counts[i], pct, clear_counts[i]);
			cct_showstr(42, 10 + i, status_of_cell, COLOR_HWHITE, COLOR_BLACK, 1);
		}
		else
		{
			cct_gotoxy(42, 10 + i);
			cct_setcolor(graph_color(i), COLOR_HWHITE);
			cout << "○";
			sprintf(status_of_cell, ":%02d/(%6.2f%%) 消除-%-4d", counts[i], pct, clear_counts[i]);
			cct_showstr(44, 10 + i, status_of_cell, COLOR_HWHITE, COLOR_BLACK, 1);
		}
	}
	cct_setcolor();
}

void update_board_balls_canvas(int board[][MAX_SIZE], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int x = 2 + 4 * j;
			int y = 2 + 2 * i;
			if (board[i][j] == 0)
			{
				cct_showstr(x, y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else
			{
				cct_gotoxy(x, y);
				cct_setcolor(graph_color(board[i][j]), COLOR_HWHITE);
				cout << "○";
			}
		}
	}
	cct_setcolor();
}

/***************************************************************************
  函数名称：play_clear_animation
  功    能：播放彩球消除时的闪烁动画
***************************************************************************/
void play_clear_animation(int board[][MAX_SIZE], int old_board[][MAX_SIZE], int row, int col)
{
	// 确保在闪烁前，先把即将消除的球画出来（处理加球后立刻消除的视觉突兀问题）
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (old_board[i][j] != 0 && board[i][j] == 0)
			{
				cct_gotoxy(2 + j * 4, 2 + i * 2);
				cct_setcolor(graph_color(old_board[i][j]), COLOR_HWHITE);
				cout << "○";
			}
		}
	}

	// 闪烁 3 次
	for (int blink = 0; blink < 3; ++blink) 
	{
		// 灭
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (old_board[i][j] != 0 && board[i][j] == 0)
					cct_showstr(2 + j * 4, 2 + i * 2, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
		}
		cct_delay(150);
		// 亮
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (old_board[i][j] != 0 && board[i][j] == 0)
				{
					cct_gotoxy(2 + j * 4, 2 + i * 2);
					cct_setcolor(graph_color(old_board[i][j]), COLOR_HWHITE);
					cout << "○";
				}
			}
		}
		cct_delay(150);
	}
}

/***************************************************************************
  函数名称：process_elimination
  功    能：处理一步之后的消除逻辑、更新统计数据并播放动画
  返 回 值：本次消除获得的分数
***************************************************************************/
int process_elimination(int board[][MAX_SIZE], int row, int col, int clear_counts[])
{
	int old_board[MAX_SIZE][MAX_SIZE];
	int counts_before[8] = { 0 };

	// 1. 记录消除前的状态和各颜色数量
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
		{
			old_board[i][j] = board[i][j];
			counts_before[board[i][j]]++;
		}
	}

	// 2. 尝试消除
	int turn_score = clear_five_lines(board, row, col);

	// 3. 如果发生消除，更新数据并播放动画
	if (turn_score > 0)
	{
		int counts_after[8] = { 0 };
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				counts_after[board[i][j]]++;
			}
		}
		// 累加各个颜色的消除总数
		for (int i = 1; i <= 7; i++)
		{
			if (counts_before[i] > counts_after[i])
			{
				clear_counts[i] += (counts_before[i] - counts_after[i]);
			}
		}
		// 播放闪烁动画
		play_clear_animation(board, old_board, row, col);
	}

	return turn_score;
}

/***************************************************************************
  函数名称：color_linez_D
  功    能：菜单D，画出n*n的无分隔线框架，并随机显示初始5个彩球
***************************************************************************/
void color_linez_D()
{
	cct_setconsoletitle("D.画出n*n的框架（无分隔线），随机显示5个球");
	cct_setcolor();
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	make_random_board(board, row, col, 5);
	print_matrix(board, board, row, col, "初始数组：", 0);

	cout << endl << "按回车键显示图形...";
	while (_getch() != '\r')
		continue;

	cct_cls();

	draw_graph_title(0, row, col);
	print_board_canvas(board, row, col, 0, 0);

	cct_gotoxy(0, row + 2);
	wait_for_end();
}

/***************************************************************************
  函数名称：color_linez_E
  功    能：菜单E，画出n*n的有分隔线框架，并随机显示初始5个彩球
***************************************************************************/
void color_linez_E()
{
	cct_setconsoletitle("  E. 画出n*n的框架（有分隔线），随机显示5个球");
	cct_setcolor();
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	make_random_board(board, row, col, 5);
	print_matrix(board, board, row, col, "初始数组：", 0);

	cout << endl << "按回车键显示图形...";
	while (_getch() != '\r')
		continue;

	cct_cls();

	draw_graph_title(1, row, col);
	print_board_canvas(board, row, col, 1, 0);

	cct_gotoxy(0, row * 2 + 1);
	wait_for_end();
}

/***************************************************************************
  函数名称：color_linez_F
  功    能：菜单F，图形界面60%彩球并支持鼠标完成一次移动
***************************************************************************/
void color_linez_F()
{
	cct_setconsoletitle("  F. n*n的框架，60%的球，支持鼠标，完成一次移动");
	cct_setcolor();
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];
	int ball_count;

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	ball_count = row * col * 6 / 10;
	make_random_board(board, row, col, ball_count);

	cct_cls();
	cct_showstr(0, 0, "鼠标移动，左键单击选择，右键退出", COLOR_BLACK, COLOR_WHITE, 1);
	print_board_canvas(board, row, col, 1, 1);

	read_mouse(board, row, col);

	cct_gotoxy(0, row * 2 + 1);
	cct_setcolor();
	cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
	wait_for_end();
}

/***************************************************************************
  函数名称：color_linez_G
  功    能：菜单G，cmd图形界面完整版
  说    明：完成完整的图形化操作，包括移动、动画、得分与面板刷新
***************************************************************************/
void color_linez_G()
{
	cct_setconsoletitle("  G. cmd图形界面完整版");
	cct_setcolor();
	cct_cls();

	int row, col;
	int board[MAX_SIZE][MAX_SIZE];
	int next_balls[3];
	int clear_counts[8] = { 0 };
	int score = 0;

	srand((unsigned int)time(NULL));

	row = input_range_value("请输入行数(7-9)：     ");
	col = input_range_value("请输入列数(7-9)：     ");

	make_random_board(board, row, col, 5);
	make_next_balls(next_balls);

	cct_cls();
	cct_showstr(0, 0, "鼠标移动，左键单击选择，右键退出", COLOR_BLACK, COLOR_WHITE, 1);

	// 初始化时画边框与面板
	print_board_canvas(board, row, col, 1, 1);
	print_score_canvas(score);
	print_next_3_balls_canvas(next_balls);
	print_status_of_all_cells_canvas(board, row, col, clear_counts);

	while (1)
	{
		if (count_empty_grid(board, row, col) == 0) {
			cct_showstr(0, row * 2 + 2, "无空位可移动，游戏结束!           ", COLOR_BLACK, COLOR_GREEN, 1, 40);
			break;
		}
		bool moved = read_mouse(board, row, col);
		if (!moved) // 玩家右键退出
			break;

		// ========================== 核心游戏流程 ==========================
		
		// 阶段 1：处理玩家移动后的消除
		int turn_score = process_elimination(board, row, col, clear_counts);
		score += turn_score;
		// 阶段 2：如果玩家移动未引发消除，则系统加入新球
		if (turn_score == 0) {
			int mark[MAX_SIZE][MAX_SIZE] = { 0 };
			add_next_balls(board, mark, row, col, next_balls);
			update_board_balls_canvas(board, row, col); // 马上把新球画出来
			// 阶段 3：处理新加的球引发的消除
			turn_score = process_elimination(board, row, col, clear_counts);
			score += turn_score;
			// 生成下一轮预告球
			make_next_balls(next_balls);
		}

		// ========================== 统一刷新界面 ==========================
		update_score_canvas(score);
		update_next_3_balls_canvas(next_balls);
		update_status_of_all_cells_canvas(board, row, col, clear_counts);
		update_board_balls_canvas(board, row, col);
		cct_setcolor();
	}
	cct_setcolor();
	cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
	cct_gotoxy(0, row * 2 + 2);
	wait_for_end();
}

