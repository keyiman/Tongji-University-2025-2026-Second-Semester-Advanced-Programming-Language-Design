/* 个人信息已删除 */
#include <iostream>
#include <cmath>

using namespace std;

void q3(double a, double b, double c, double delta)
{
	double x = -b / (2.0 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

