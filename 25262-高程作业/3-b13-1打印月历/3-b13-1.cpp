/* 个人信息已删除 */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
	int year, month, weekday;
	
	//输入年月并判断正确性
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		
		cout << "输入非法，请重新输入" << endl;
	}

	//获取对应年月的天数
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

	//输入星期并判断正确性
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> weekday;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (weekday >= 0 && weekday <= 6)
			break;

		cout << "输入非法，请重新输入" << endl;
	}
	cout << endl;

	//打印月历
	cout << year << "年" << month << "月" << "的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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

	cout << endl;
	return 0;
}

