/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

void q1()
{
	cout << "不是一元二次方程" << endl;
}

void q2(double a, double b, double c, double delta)
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

void q3(double a, double b, double c, double delta)
{
	double x = -b / (2.0 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

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

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	if (a == 0)
	{
		q1();
		return 0;
	}

	double delta = b * b - 4.0 * a * c;

	if (fabs(delta) < 1e-6)
		delta = 0;

	if (delta > 0)
	{
		q2(a, b, c, delta);
		return 0;
	}
		
	if (delta == 0)
	{
		q3(a, b, c, delta);
		return 0;
	}
		
	if (delta < 0)
	{
		q4(a, b, c, delta);
		return 0;
	}

	return 0;
}

