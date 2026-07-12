/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

extern double a, b, c, delta;

void q1()
{
	cout << "不是一元二次方程" << endl;
}

void q2()
{
	double temp1 = (-b + sqrt(delta)) / (2.0 * a);
	double temp2 = (-b - sqrt(delta)) / (2.0 * a);
	double x1, x2;
	x1 = (temp1 > temp2) ? temp1 : temp2;
	x2 = (temp1 < temp2) ? temp1 : temp2;
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void q3()
{
	double x = -b / (2.0 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

void q4()
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

