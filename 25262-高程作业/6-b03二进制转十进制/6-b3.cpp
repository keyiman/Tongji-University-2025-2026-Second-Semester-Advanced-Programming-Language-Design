/* 个人信息已删除 */
#include <iostream>
#include <cstdio>
using namespace std;

#define L 35

unsigned int bin_to_dec(char* str)
{
	unsigned int dec = 0;

	while (*str != '\0')
	{
		dec = dec * 2 + (*str - '0');
		str++;
	}

	return dec;
}

int main()
{
	char str[L];

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;

	cout << bin_to_dec(str) << endl;

	return 0;
}

