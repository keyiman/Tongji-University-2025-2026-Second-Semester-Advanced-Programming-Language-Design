/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

void add_digit(int num) 
{
	int clen = strlen(chnstr) / 10;
	int len = strlen(result);
	for (int i = 0; i < clen; i++) 
	{
		result[len + i] = chnstr[num * clen + i];
	}
	result[len + clen] = '\0';
}

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double num;
	scanf("%lf", &num);
	num += 0.001;
	double int_part = floor(num);
	double frac_part = num - floor(num);
	int d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, df1, df2;
	d10 = (int)floor(int_part / 1000000000);
	d9 = (int)fmod(floor(int_part / 100000000), 10.0);
	d8 = (int)fmod(floor(int_part / 10000000), 10.0);
	d7 = (int)fmod(floor(int_part / 1000000), 10.0);
	d6 = (int)fmod(floor(int_part / 100000), 10.0);
	d5 = (int)fmod(floor(int_part / 10000), 10.0);
	d4 = (int)fmod(floor(int_part / 1000), 10.0);
	d3 = (int)fmod(floor(int_part / 100), 10.0);
	d2 = (int)fmod(floor(int_part / 10), 10.0);
	d1 = (int)fmod(int_part, 10.0);
	df1 = (int)fmod(floor(frac_part * 10), 10.0);
	df2 = (int)fmod(floor(frac_part * 100), 10.0);

	printf("大写结果是:\n");
	result[0] = '\0';

	//亿位
	int has_d = 0;
	if (d10 || d9)
	{
		if (d10)
		{
			add_digit(d10);
			strcat(result, "拾");
		}
		if (d9)
		{
			add_digit(d9);
		}
		strcat(result, "亿");
		has_d = 1;
	}

	//万位
	int need0_1 = 0;
	if (d8 || d7 || d6 || d5)
	{
		if (d8)
		{
			add_digit(d8);
			strcat(result, "仟");
			has_d = 1;
		}
		else
		{
			need0_1 = 1;
		}

		if (d7)
		{
			if (need0_1 && has_d)
			{
				add_digit(0); 
			}
			add_digit(d7);
			strcat(result, "佰");
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		if (d6)
		{
			if (need0_1 && has_d)
			{
				add_digit(0);
			}
			add_digit(d6);
			strcat(result, "拾");
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		if (d5)
		{
			if (need0_1 && has_d)
			{
				add_digit(0);
			}
			add_digit(d5);
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		strcat(result, "万");
	}

	//个位
	int need0_2 = 0;
	if (d4 || d3 || d2 || d1)
	{
		if (d4)
		{
			add_digit(d4);
			strcat(result, "仟");
			has_d = 1;
		}
		else
		{
			need0_2 = 1;
		}

		if (d3)
		{
			if (need0_2 && has_d)
			{
				add_digit(0);
			}
			add_digit(d3);
			strcat(result, "佰");
			has_d = 1;
			need0_2 = 0;
		}
		else
		{
			need0_2 = 1;
		}

		if (d2)
		{
			if (need0_2 && has_d)
			{
				add_digit(0);
			}
			add_digit(d2);
			strcat(result, "拾");
			has_d = 1;
			need0_2 = 0;
		}
		else
		{
			need0_2 = 1;
		}

		if (d1)
		{
			if (need0_2 && has_d)
			{
				add_digit(0);
			}
			add_digit(d1);
			has_d = 1;
			need0_2 = 0;
		}
	}

	if (has_d)
	{
		strcat(result, "圆");
	}

	//角分
	if (df1 || df2)
	{
		if (df1)
		{
			add_digit(df1);
			strcat(result, "角");
		}
		else if (has_d && !df1)
		{
			add_digit(0);
		}

		if (df2)
		{
			add_digit(df2);
			strcat(result, "分");
		}
		else
		{
			strcat(result, "整");
		}
	}
	else if ((df1 + df2) == 0 && has_d)
	{
		strcat(result, "整");
	}
	else
	{
		add_digit(0);
		strcat(result, "圆整");
	}

	printf("%s\n", result); /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}

