/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
using namespace std;
const double Pi = 3.14159;

int main()
{
	cout << "请输入半径和高度" << endl;
	double r, h;
	cin >> r >> h;
	cout << setiosflags(ios::fixed);
	cout << "圆周长     : " << setprecision(2) << 2 * Pi * r << endl;
	cout << "圆面积     : " << setprecision(2) << Pi * r * r << endl;
	cout << "圆球表面积 : " << setprecision(2) << 4 * Pi * r * r << endl;
	cout << "圆球体积   : " << setprecision(2) << 4.0 / 3 * Pi * r * r * r << endl;
	cout << "圆柱体积   : " << setprecision(2) << Pi * r * r * h << endl;
	return 0;
}

