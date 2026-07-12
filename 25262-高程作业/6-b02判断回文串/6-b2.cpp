/* 个人信息已删除 */
#include <iostream>
#include <cstdio>
using namespace std;

#define L 85

bool is_huiwen(char* str)
{
	char* left = str, * right = str;

	while (*right != '\0')
		right++;

	// 处理空串的特殊情况
	if (left == right)
		return true;

	right--; // right 退回一步，使其指向字符串的最后一个有效字符

	while (left < right)
	{
		if (*left != *right)
		{
			return false;
		}
		left++;
		right--;
	}

	return true;
}

int main()
{
	char str[L], * p = str;

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(p, L, stdin);
	
	//处理尾部的换行符
	char* p2 = str;
	while (*p2 != '\0')
	{
		if (*p2 == '\n')
		{
			*p2 = '\0';
			break;
		}
		p2++;
	}

	if (is_huiwen(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	return 0;
}

