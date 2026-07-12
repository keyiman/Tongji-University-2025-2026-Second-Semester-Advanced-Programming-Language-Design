/* 个人信息已删除 */
#include <iostream>

using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int m1 = ((a < b) ? a : b);
	int m2 = ((c < d) ? c : d);
	return ((m1 < m2) ? m1 : m2);
}

int main()
{
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		int num;
		cin >> num;

		if (cin.fail())
		{
			cin.clear();
			int ch;
			while ((ch = cin.get()) != '\n' && ch != EOF);
			continue;
		}

		if (num < 2 || num > 4)
		{
			cout << "个数输入错误" << endl;
			break;
		}
		else
		{
			int a = 0, b = 0, c = 0, d = 0, temp_false = 0;
			for (int i = 0; i < num; i++)
			{
				int temp;
				cin >> temp;

				if (cin.fail() || temp <= 0)
				{
					temp_false = 1;
					cin.clear();
					int ch;
					while ((ch = cin.get()) != '\n' && ch != EOF);
					break;
				}


				if (i == 0)
					a = temp;
				else if (i == 1)
					b = temp;
				else if (i == 2)
					c = temp;
				else if (i == 3)
					d = temp;
			}

			if (temp_false)
				continue;

			int ch;
			while ((ch = cin.get()) != '\n' && ch != EOF);

			if (num == 2)
			{
				cout << "min=" << min(a, b) << endl;
			}
			else if (num == 3)
			{
				cout << "min=" << min(a, b, c) << endl;
			}
			else if (num == 4)
			{
				cout << "min=" << min(a, b, c, d) << endl;
			}
		}
		break;
	}
	
	return 0;
}

