/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

#include "4-b16.h"

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

