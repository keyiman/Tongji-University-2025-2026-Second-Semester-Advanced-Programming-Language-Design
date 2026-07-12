/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

extern void q1();
extern void q2();
extern void q3();
extern void q4();
double a, b, c, delta;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;

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

	delta = b * b - 4.0 * a * c;

	if (fabs(delta) < 1e-6)
		delta = 0;

	if (delta > 0)
	{
		q2();
		return 0;
	}

	if (delta == 0)
	{
		q3();
		return 0;
	}

	if (delta < 0)
	{
		q4();
		return 0;
	}

	return 0;
}

