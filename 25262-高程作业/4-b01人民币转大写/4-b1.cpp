/* 个人信息已删除 */
#include <iostream>
#include <cmath>
using namespace std;

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：num (数字0-9), flag_of_zero (是否输出零的标记)
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	cout << "请输入[0-100亿)之间的数字:\n";
	double num;
	cin >> num;
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

	cout << "大写结果是:\n";

	//亿位
	int has_d = 0;
	if (d10 || d9)
	{
		if (d10)
		{
			daxie(d10, 0); // 替换掉原来的 switch
			cout << "拾";
		}
		if (d9)
		{
			daxie(d9, 0); // 替换掉原来的 switch
		}
		cout << "亿";
		has_d = 1;
	}

	//万位
	int need0_1 = 0;
	if (d8 || d7 || d6 || d5)
	{
		if (d8)
		{
			daxie(d8, 0);
			cout << "仟";
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
				daxie(0, 1); // 替换 cout << "零";
			}
			daxie(d7, 0);
			cout << "佰";
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
				daxie(0, 1);
			}
			daxie(d6, 0);
			cout << "拾";
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
				daxie(0, 1);
			}
			daxie(d5, 0);
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		cout << "万";
	}

	//个位
	int need0_2 = 0;
	if (d4 || d3 || d2 || d1)
	{
		if (d4)
		{
			daxie(d4, 0);
			cout << "仟";
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
				daxie(0, 1);
			}
			daxie(d3, 0);
			cout << "佰";
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
				daxie(0, 1);
			}
			daxie(d2, 0);
			cout << "拾";
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
				daxie(0, 1);
			}
			daxie(d1, 0);
			has_d = 1;
			need0_2 = 0;
		}
	}

	if (has_d)
	{
		cout << "圆";
	}

	//角分
	if (df1 || df2)
	{
		if (df1)
		{
			daxie(df1, 0);
			cout << "角";
		}
		else if (has_d && !df1)
		{
			daxie(0, 1); 
		}

		if (df2)
		{
			daxie(df2, 0);
			cout << "分";
		}
		else
		{
			cout << "整";
		}
	}
	else if ((df1 + df2) == 0 && has_d)
	{
		cout << "整";
	}
	else
	{
		daxie(0, 1); 
		cout << "圆整";
	}

	cout << "\n";

	return 0;
}

