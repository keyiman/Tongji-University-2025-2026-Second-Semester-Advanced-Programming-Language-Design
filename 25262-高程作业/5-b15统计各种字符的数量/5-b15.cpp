/* 个人信息已删除 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[3][128] = { 0 };
	int upper = 0, lower = 0, num = 0, space = 0, other = 0;

	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		cin.getline(str[i], 128);
		for (int j = 0; j < (int)strlen(str[i]); j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				upper++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				lower++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else if (str[i][j] == ' ')
				space++;
			else
				other++;
		}
	}

	cout << "大写 : " << upper << endl;
	cout << "小写 : " << lower << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;

	return 0;
}

