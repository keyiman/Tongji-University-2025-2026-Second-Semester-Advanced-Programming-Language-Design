/* 个人信息已删除 */
#include <iostream>

using namespace std;

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int sudu[9][9] = { 0 };
	int sudu_in;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			while (1)
			{
				cin >> sudu_in;
				if (sudu_in >= 1 && sudu_in <= 9)
				{
					sudu[i][j] = sudu_in;
					break;
				}
				else
				{
					cin.clear();
					int ch;
					while ((ch = getchar()) != '\n' && ch != EOF);
					
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				}
			}
		}
	}

	int row_record[9][10] = { 0 };// 出现在的行，出现次数
	int col_record[9][10] = { 0 };
	int chunk_record[9][10] = { 0 };

	int is_solution = 1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int chunk_index = (i / 3) * 3 + (j / 3);

			int num = sudu[i][j];

			if (row_record[i][num] == 1 || col_record[j][num] == 1 || chunk_record[chunk_index][num] == 1)
			{
				is_solution = 0;
				break;
			}

			row_record[i][num] = 1;
			col_record[j][num] = 1;
			chunk_record[chunk_index][num] = 1;
		}
	}

	if (is_solution)
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}

	return 0;
}

