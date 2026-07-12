/* 个人信息已删除 */
#include <iostream>
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

void print_calendar(int year, int typed_months_per_row)
{
	int start_weekday[13];
	int month_days[13];

	// 计算该年1到12月的天数和起始星期
	for (int m = 1; m <= 12; m++)
	{
		start_weekday[m] = zeller(year, m, 1);
		month_days[m] = get_days(year, m);
	}

	cout << year << "年的日历:" << endl << endl;

	int COL = typed_months_per_row;
	int ROW = 12 / COL;

	for (int r = 0; r < ROW; r++)
	{
		// 月份表头
		for (int c = 0; c < COL; c++)
		{
			int month = r * COL + c + 1;
			cout << "           " << right << setw(2) << month << "月            ";// 11,2,2,12
			if (c != COL - 1)
				cout << "     "; // 5
		}
		cout << endl;

		// 星期表头
		for (int c = 0; c < COL; c++)
		{
			cout << "Sun Mon Tue Wed Thu Fri Sat"; 
			if (c != COL - 1)
				cout << "     "; // 5
		}
		cout << endl;

		// 并排的几个月中，最多需要打印多少行
		int max_weeks = 0;
		for (int c = 0; c < COL; c++)
		{
			int m = r * COL + c + 1;
			int weeks = (start_weekday[m] + month_days[m] + 6) / 7;;
			if (weeks > max_weeks)
				max_weeks = weeks;
		}

		// 日期
		int current_day[13] = { 0 };
		for (int c = 0; c < COL; c++)
		{
			int m = r * COL + c + 1;
			current_day[m] = - start_weekday[m];
		}

		for (int line = 0; line < max_weeks; line++)
		{
			for (int c = 0; c < COL; c++)
			{
				int m = r * COL + c + 1;
				current_day[m]++;
				for (;; current_day[m]++)
				{
					if (current_day[m] >= 1 && current_day[m] <= month_days[m])
					{
						cout << left << setw(4) << current_day[m];
					}
					else
					{
						cout << "    ";// 4
					}
					if ((start_weekday[m] + current_day[m]) % 7 == 0)
					{
						break;
					}
				}

				if (c != COL - 1)
					cout << "    "; // 4
			}
			cout << endl;
		}

		if (r != ROW - 1)
		{
			cout << endl;
		}
	}
}

int main()
{
	int year;

	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.fail())
		{
			cin.clear();
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		else if(year < 1900 || year > 2100)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	int typed_months_per_row;

	while (1)
	{
		cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
		cin >> typed_months_per_row;
		if (cin.fail())
		{
			cin.clear();
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		else if (typed_months_per_row != 1 && typed_months_per_row != 2 &&
			 	 typed_months_per_row != 3 && typed_months_per_row != 4 &&
				 typed_months_per_row != 6 && typed_months_per_row != 12)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	print_calendar(year, typed_months_per_row);

	cout << endl << endl;
	return 0;
}


