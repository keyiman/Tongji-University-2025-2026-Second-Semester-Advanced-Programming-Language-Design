/* 2553765 计算机 陈楷鑫 */

#include <iostream>
#include <iomanip>
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：hanoi
  功    能：递归输出汉诺塔移动步骤
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		cout << " 1# " << src << "-->" << dst << endl;
		return;
	}

	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n << "# " << src << "-->" << dst << endl;
	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：hanoi1
  功    能：菜单1，基本解
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi1()
{
	int n;
	char src, dst, tmp;
	int ch;

	while (1)
	{
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> n;

		if (cin.fail())
			cin.clear();

		while ((ch = cin.get()) != '\n' && ch != EOF)
			continue;

		if (n >= 1 && n <= 16)
			break;
	}

	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;

		if (cin.fail())
			cin.clear();

		while ((ch = cin.get()) != '\n' && ch != EOF)
			continue;

		if (src >= 'a' && src <= 'c')
			src = char(src - 32);

		if (src >= 'A' && src <= 'C')
			break;
	}

	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;

		if (cin.fail())
			cin.clear();

		while ((ch = cin.get()) != '\n' && ch != EOF)
			continue;

		if (dst >= 'a' && dst <= 'c')
			dst = char(dst - 32);

		if (dst == src)
		{
			cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
		}
		else if (dst >= 'A' && dst <= 'C')
		{
			break;
		}
	}

	tmp = char('A' + 'B' + 'C' - src - dst);

	cout << "移动步骤为:" << endl;
	hanoi(n, src, tmp, dst);
}