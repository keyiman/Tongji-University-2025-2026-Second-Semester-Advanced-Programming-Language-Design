/* 个人信息已删除 */
/*255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚 255xxxx 沈坚*/
#include <iostream>
using namespace std;

int main()
{
	char line[256];

	cin.getline(line, 256);

	int expected_len = 0, min_upper = 0, min_lower = 0, min_num = 0, min_other = 0;

	if (!(cin >> expected_len >> min_upper >> min_lower >> min_num >> min_other))
	{
		cout << "错误" << endl;
		return 0;
	}

	if (expected_len < 12 || expected_len > 16 ||
		min_upper < 2 || min_lower < 2 || min_num < 2 || min_other < 2 ||
		(min_upper + min_lower + min_num + min_other) > expected_len)
	{
		cout << "错误" << endl;
		return 0;
	}

	char passwords[128];
	for (int i = 0; i < 10; i++)
	{
		if (!(cin >> passwords))
		{
			cout << "错误" << endl;
			return 0;
		}

		int upper = 0, lower = 0, num = 0, other = 0;

		for (int j = 0; passwords[j] != '\0'; j++)
		{
			if (passwords[j] >= 'A' && passwords[j] <= 'Z')
			{
				upper++;
			}
			else if (passwords[j] >= 'a' && passwords[j] <= 'z')
			{
				lower++;
			}
			else if (passwords[j] >= '0' && passwords[j] <= '9')
			{
				num++;
			}
			else
			{
				bool is_valid_other = 0;
				char valid_others[] = "!@#$%^&*-_=+,.?";

				for (int k = 0; valid_others[k] != '\0'; k++)
				{
					if (passwords[j] == valid_others[k])
					{
						is_valid_other = 1;
						break;
					}
				}

				if (is_valid_other)
				{
					other++;
				}
				else
				{
					cout << "错误" << endl;
					return 0;
				}
			}
		}

		if (upper < min_upper || lower < min_lower || num < min_num || other < min_other)
		{
			cout << "错误" << endl;
			return 0;
		}

		if (upper + lower + num + other != expected_len)
		{
			cout << "错误" << endl;
			return 0;
		}
	}

	cout << "正确" << endl;

	return 0;
}

