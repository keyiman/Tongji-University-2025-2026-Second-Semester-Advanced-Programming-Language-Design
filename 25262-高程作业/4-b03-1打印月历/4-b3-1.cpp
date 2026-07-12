/* 个人信息已删除 */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y -= 1;
	}
	int y_2 = y % 100;
	int c = y / 100;
	int w0 = y_2 + (y_2 / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	int w = (w0 % 7 + 7) % 7;

	return w;
}

int get_days(int year, int month)
{
	int days;
	int isleap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;
	else if (month == 2 && isleap)
		days = 29;
	else
		days = 28;
	return days;
}

void calendar(int year, int month)
{
	/* 按需添加代码 */
	int weekday = zeller(year, month, 1);
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	int days = get_days(year, month);
	for (int i = 0; i < weekday; i++) //打印第一周前面的空白
	{
		cout << "        ";
	}
	for (int day = 1; day <= days; day++)
	{
		cout << setw(4) << day;
		if ((weekday + day) % 7 != 0)
			cout << "    ";
		else
			cout << endl;
	}
	if ((weekday + days) % 7 != 0)
		cout << endl;
	
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	int year, month;
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (!(year >= 1900 && year <= 2100))
		{
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (!(month >= 1 && month <= 12))
		{
			cout << "月份不正确，请重新输入" << endl;
		}
		else
		{
				break;
		}
	}
	cout << endl;

	calendar(year, month);

	return 0;
}


