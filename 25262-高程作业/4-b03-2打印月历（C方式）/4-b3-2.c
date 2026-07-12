/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	int weekday = zeller(year, month, 1);

	printf("%d年%d月\n", year, month);
	
	printf("======================================================\n");
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	printf("======================================================\n");

	int days = get_days(year, month);
	for (int i = 0; i < weekday; i++) //打印第一周前面的空白
	{
		printf("        ");
	}
	for (int day = 1; day <= days; day++)
	{
		printf("%4d", day); 
		if ((weekday + day) % 7 != 0)
			printf("    "); 
		else
			printf("\n");
	}
	if ((weekday + days) % 7 != 0)
		printf("\n");

	printf("======================================================\n");
}

int main()
{
	int year, month;
	int ret;
	while (1)
	{
		printf("请输入年[1900-2100]、月\n");
		ret = scanf("%d %d", &year, &month);

		if (ret != 2)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入错误，请重新输入\n");
		}
		else if (!(year >= 1900 && year <= 2100))
		{
			printf("年份不正确，请重新输入\n");
		}
		else if (!(month >= 1 && month <= 12))
		{
			printf("月份不正确，请重新输入\n");
		}
		else
		{
			break;
		}
	}
	printf("\n");

	calendar(year, month);
	
	return 0;
}

