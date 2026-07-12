/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, weekday;
	int ret;

	//输入年月并判断正确性
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d%d", &year, &month);
		if (ret != 2)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}
		if (ret == 2 && year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;

		printf("输入非法，请重新输入\n");
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
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret = scanf("%d", &weekday);
		if (ret != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}
		if (ret == 1 && weekday >= 0 && weekday <= 6)
			break;

		printf("输入非法，请重新输入\n");
	}
	printf("\n");

	//打印月历
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
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

	printf("\n");
	return 0;
}

