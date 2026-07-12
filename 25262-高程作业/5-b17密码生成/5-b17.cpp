/* 个人信息已删除 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	int len = 0, min_upper = 0, min_lower = 0, min_num = 0, min_other = 0;

	srand(static_cast<unsigned int>(time(NULL)));

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> min_upper >> min_lower >> min_num >> min_other;

	if (cin.fail())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	else if (len < 12 || len > 16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	else if (min_upper < 2)
	{
		cout << "大写字母个数[" << min_upper << "]不正确" << endl;
		return 0;
	}
	else if (min_lower < 2)
	{
		cout << "小写字母个数[" << min_lower << "]不正确" << endl;
		return 0;
	}
	else if (min_num < 2)
	{
		cout << "数字个数[" << min_num << "]不正确" << endl;
		return 0;
	}
	else if (min_other < 2)
	{
		cout << "其它符号个数[" << min_other << "]不正确" << endl;
		return 0;
	}
	else if (min_upper + min_lower + min_num + min_other > len)
	{
		cout << "所有字符类型之和[" << min_upper << "+" << min_lower << "+" << min_num << "+" << min_other << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	else
		cout << len << " " << min_upper << " " << min_lower << " " << min_num << " " << min_other << endl;

	char passwords[10][17] = { 0 };

	for (int r = 0; r < 10; r++)
	{
		int unclassified = len - min_upper - min_lower - min_num - min_other;
		int n[4];
		n[0] = min_upper;
		n[1] = min_lower;
		n[2] = min_num;
		n[3] = min_other;

		for (int i = 0; i < unclassified; i++)
		{
			switch (rand() % 4)
			{
				case 0:
					n[0]++;
					break;
				case 1:
					n[1]++;
					break;
				case 2:
					n[2]++;
					break;
				case 3:
					n[3]++;
					break;
			}
		}

		for (int c = 0; c < len; c++)
		{
			while (n[0] != 0 || n[1] != 0 || n[2] != 0 || n[3] != 0)
			{
				int type = rand() % 4;
				if (n[type] != 0)
				{
					n[type]--;
					switch (type)
					{
						case 0:
							passwords[r][c] = 'A' + rand() % 26;
							break;
						case 1:
							passwords[r][c] = 'a' + rand() % 26;
							break;
						case 2:
							passwords[r][c] = '0' + rand() % 10;
							break;
						case 3:
							passwords[r][c] = other[rand() % 15];
							break;
					}
					break;
				}
				else
					continue;

			}
		}
		passwords[r][len] = '\0';
		cout << passwords[r] << endl;
	}
	return 0;
}

