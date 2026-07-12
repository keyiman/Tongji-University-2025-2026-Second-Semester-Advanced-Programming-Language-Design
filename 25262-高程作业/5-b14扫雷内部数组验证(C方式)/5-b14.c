/* 个人信息已删除 */
/*255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define board_R 10
#define board_C 26
#define sum_mine 50

int main()
{
	char board[board_R][board_C];
	int cnt_mine = 0;

	// 读取输入并统计实际的雷数
	for (int r = 0; r < board_R; r++)
	{
		for (int c = 0; c < board_C; c++)
		{
			// "%c" 前面的空格会让 scanf 自动忽略所有的空格和换行符
			scanf(" %c", &board[r][c]);

			if (board[r][c] == '*')
			{
				cnt_mine++;
			}
		}
	}

	// 检查1：雷数不等于50
	if (cnt_mine != sum_mine)
	{
		printf("错误1\n");
		return 0;
	}

	// 验证非雷区域的数字是否正确
	for (int r = 0; r < board_R; r++)
	{
		for (int c = 0; c < board_C; c++)
		{
			if (board[r][c] == '*')
			{
				continue;
			}

			int expected_mine = board[r][c] - '0';
			int actual_mine = 0;

			// 统计周围8个方向的实际雷数
			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					if (r + x >= 0 && r + x < board_R && c + y >= 0 && c + y < board_C)
					{
						if (board[r + x][c + y] == '*')
						{
							actual_mine++;
						}
					}
				}
			}

			// 检查2：重新计算的雷数与读入的数字不匹配
			if (actual_mine != expected_mine)
			{
				printf("错误2\n");
				return 0;
			}
		}
	}

	printf("正确\n");

	return 0;
}

