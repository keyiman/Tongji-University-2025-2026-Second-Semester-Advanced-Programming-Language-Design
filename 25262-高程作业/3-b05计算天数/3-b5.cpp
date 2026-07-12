/* 个人信息已删除 */
#include <iostream>
using namespace std;

int main()
{
	int y, m, d;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d; 

	if (m < 1 || m > 12)
	{
		cout << "输入错误-月份不正确" << endl;
		return 0;
	}

	int isleap = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;

	int isday;
	if (d < 1)
	{
		isday = 0;
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		isday = d <= 31 ? 1 : 0;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		isday = d <= 30 ? 1 : 0;
	}
	else if (m == 2 && isleap)
	{
		isday = d <= 29 ? 1 : 0;
	}
	else
	{
		isday = d <= 28 ? 1 : 0;
	}

	int sum = 0;
	switch (m - 1) 
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
	sum += d;

	if (!isday)
	{
		cout << "输入错误-日与月的关系非法" << endl;
	}
	else
	{
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << sum << "天" << endl;
	}
	
	return 0;
}


