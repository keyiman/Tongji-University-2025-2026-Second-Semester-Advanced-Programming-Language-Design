/* 个人信息已删除 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x;
	while (1)
	{
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x >= -10 && x <= 65)
		{
			break;
		}
		else
		{
			cout << "输入非法，请重新输入" << endl;
		}
	}

	int n = 0;
	double e_x = 1.0;
	double flag = 1.0;

	while (1)
	{
		n++;
		flag = (flag * x / n);
		if (fabs(flag) < 1e-6)
		{
			break;
		}
		e_x += flag;
	}

	cout << setprecision(10);
	cout << "迭代终值 n=" << n << " |x^" << n << "/" << n << "!|=" << flag << endl;
	cout << "e^" << x << "=" << e_x << endl;
	
	return 0;
}


