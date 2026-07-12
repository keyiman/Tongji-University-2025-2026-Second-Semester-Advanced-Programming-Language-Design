/* 个人信息已删除 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */

public:
	int calc_days();     //计算是当年的第几天
	Days(int y, int m, int d)
	{
		this->year = y;
		this->month = m;
		this->day = d;
	}
	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
    

};

/* --- 此处给出类成员函数的体外实现 --- */

int Days::calc_days()
{
    if (month < 1 || month > 12)
    {
        return -1;
    }

    int isleap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;

    int isday;
    if (day < 1)
    {
        isday = 0;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        isday = day <= 31 ? 1 : 0;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        isday = day <= 30 ? 1 : 0;
    }
    else if (month == 2 && isleap)
    {
        isday = day <= 29 ? 1 : 0;
    }
    else {
        isday = day <= 28 ? 1 : 0;
    }

    if (!isday)
    {
        return -1;
    }

    int sum = 0;
    switch (month - 1)
    {
        case 11:
            sum += 30;
        case 10:
            sum += 31;
        case 9:
            sum += 30;
        case 8:
            sum += 31;
        case 7:
            sum += 31;
        case 6:
            sum += 30;
        case 5:
            sum += 31;
        case 4:
            sum += 30;
        case 3:
            sum += 31;
        case 2:
            sum += (isleap ? 29 : 28);
        case 1:
            sum += 31;
    }
    sum += day;

    return sum;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2026, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2026, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2026, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}


