/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double num;
	cin >> num;
	num += 0.001;
	double int_part = floor(num);
	double frac_part = num - int_part;
	cout << setiosflags(ios::fixed);
	cout << setprecision(0) << "十亿位 : " << floor(int_part / 1000000000) << endl;
	cout << setprecision(0) << "亿位   : " << fmod(floor(int_part / 100000000), 10.0) << endl;
	cout << setprecision(0) << "千万位 : " << fmod(floor(int_part / 10000000), 10.0) << endl;
	cout << setprecision(0) << "百万位 : " << fmod(floor(int_part / 1000000), 10.0) << endl;
	cout << setprecision(0) << "十万位 : " << fmod(floor(int_part / 100000), 10.0) << endl;
	cout << setprecision(0) << "万位   : " << fmod(floor(int_part / 10000), 10.0) << endl;
	cout << setprecision(0) << "千位   : " << fmod(floor(int_part / 1000), 10.0) << endl;
	cout << setprecision(0) << "百位   : " << fmod(floor(int_part / 100), 10.0) << endl;
	cout << setprecision(0) << "十位   : " << fmod(floor(int_part / 10), 10.0) << endl;
	cout << setprecision(0) << "圆     : " << fmod(int_part, 10.0) << endl;
	cout << setprecision(0) << "角     : " << fmod(floor(frac_part * 10), 10.0) << endl;
	cout << setprecision(0) << "分     : " << fmod(floor(frac_part * 100), 10.0) << endl;
	
	return 0;
}

