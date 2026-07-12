/* 个人信息已删除 */
#include <iostream>
#include <limits>
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

int main()
{
	int year, month, day, days, weekday;
	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;
		
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
			days = get_days(year, month);
			if (!(day >= 1 && day <= days))
			{
				cout << "日不正确，请重新输入" << endl;
			}
			else
				break;
				
		}
	}
	
	weekday = zeller(year, month, day);
	switch (weekday)
	{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
	}
	
	
	return 0;
}

