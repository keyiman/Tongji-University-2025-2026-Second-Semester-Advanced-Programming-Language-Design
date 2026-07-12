/* 个人信息已删除 */
#pragma once

#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"

using namespace std;

const int MAX_SIZE = 9; // 允许的最大行列数

void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);
void wait_for_end();
void show_error_and_back(const int x, const int y, const char msg[]);

/* 内部数组与图形界面共用函数 */
int input_range_value(const char prompt[]);
void make_random_board(int board[][MAX_SIZE], const int row, const int col, const int ball_count);
void clear_mark_array(int mark[][MAX_SIZE]);
int count_empty_grid(const int board[][MAX_SIZE], const int row, const int col);
void make_next_balls(int next_balls[]);
int add_next_balls(int board[][MAX_SIZE], int mark[][MAX_SIZE], const int row, const int col, const int next_balls[]);
int clear_five_lines(int board[][MAX_SIZE], const int row, const int col);
int find_move_path(const int board[][MAX_SIZE], const int row, const int col, const int sr, const int sc, const int dr, const int dc, int path[][MAX_SIZE]);
void print_matrix(const int board[][MAX_SIZE], const int path[][MAX_SIZE], const int row, const int col, const char title[], const int mode);

char color_linez_menu();
void color_linez_A();
void color_linez_B();
void color_linez_C();
void color_linez_D();
void color_linez_E();
void color_linez_F();
void color_linez_G();

