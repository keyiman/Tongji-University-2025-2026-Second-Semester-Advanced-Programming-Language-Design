/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double Pi = 3.14159;

int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	int a, b, angle;
	cin >> a >> b >> angle;
	float area = 0.5f * (float)a * (float)b * (float)sinf((float)angle * (float)Pi / 180.0f);
	cout << setiosflags(ios::fixed) << setprecision(3) << "三角形面积为 : " << area << endl;
	return 0;
}

