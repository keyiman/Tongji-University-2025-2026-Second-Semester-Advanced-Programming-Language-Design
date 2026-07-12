/* 个人信息已删除 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define board_R 10
#define board_C 26
#define sum_mine 50

int main()
{
	//初始化棋盘
	char board[board_R][board_C] = { 0 };

	srand((unsigned int)time(NULL));

	//布置雷
	int cnt_mine = 0;
	while (cnt_mine < sum_mine)
	{
		int r_mine = rand() % 10;
		int c_mine = rand() % 26; //创建随机雷坐标

		if (board[r_mine][c_mine] != '*')
		{
			board[r_mine][c_mine] = '*';
			cnt_mine++;
		}
	}

	//计算周围雷数
	for (int r = 0; r < board_R; r++)
	{
		for (int c = 0; c < board_C; c++)
		{
			if (board[r][c] == '*')
				continue;
			int cnt_planted_mine = 0;
			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					if (r + x >= 0 && r + x < board_R && c + y >= 0 && c + y < board_C) //边界判断
					{
						if (board[r + x][c + y] == '*')
							cnt_planted_mine++;
					}
				}
			}
			board[r][c] = cnt_planted_mine + '0';
		}
	}

	//打印棋盘
	for (int r = 0; r < board_R; r++)
	{
		for (int c = 0; c < board_C; c++)
		{
			if (board[r][c] == '*')
				cout << "* ";
			else
				cout << board[r][c] << " ";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}

