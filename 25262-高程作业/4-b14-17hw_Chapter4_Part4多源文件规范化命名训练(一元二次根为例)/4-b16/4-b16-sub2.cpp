/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

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

