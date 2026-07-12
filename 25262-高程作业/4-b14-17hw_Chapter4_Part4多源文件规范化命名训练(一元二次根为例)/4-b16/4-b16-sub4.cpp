/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

void q4(double a, double b, double c, double delta)
{
	double re = -b / (2.0 * a);
	if (fabs(re) < 1e-6)
		re = 0;
	double im = fabs(sqrt(-delta) / (2.0 * a));
	if (fabs(im) < 1e-6)
		im = 0;
	cout << "有两个虚根：" << endl;
	if (re != 0 && fabs(im - 1.0) >= 1e-6)
	{
		cout << "x1=" << re << "+" << im << "i" << endl;
		cout << "x2=" << re << "-" << im << "i" << endl;
	}
	else if (re != 0 && fabs(im - 1.0) < 1e-6)
	{
		cout << "x1=" << re << "+" << "i" << endl;
		cout << "x2=" << re << "-" << "i" << endl;
	}
	else if (re == 0 && fabs(im - 1.0) >= 1e-6)
	{
		cout << "x1=" << im << "i" << endl;
		cout << "x2=" << "-" << im << "i" << endl;
	}
	else
	{
		cout << "x1=" << "i" << endl;
		cout << "x2=" << "-" << "i" << endl;
	}
}

