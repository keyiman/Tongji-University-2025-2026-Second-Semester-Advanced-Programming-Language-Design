/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
}

int get_month_days(int year, int month)
{
	int leap = is_leap(year);
	int month_days[2][13] = 
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	return month_days[leap][month];
}

int sum_days(int y, int m, int d)
{
	int sum = 0;
	for (int i = 1; i <= m - 1; i++)
	{
		sum += get_month_days(y, i);
	}
	sum += d;
	return sum;
}

int main()
{
	int y, m, d;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);

	if (m < 1 || m > 12)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}

	if (d < 1 || d > get_month_days(y, m))
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}

	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, sum_days(y, m, d));

	return 0;
}


