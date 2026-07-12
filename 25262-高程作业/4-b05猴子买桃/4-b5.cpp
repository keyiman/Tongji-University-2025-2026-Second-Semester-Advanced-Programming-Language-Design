/* 个人信息已删除 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：peachees
  功    能：计算当第days开始桃子数为1时，第一天开始的桃子数
  输入参数：days
  返 回 值：第一天开始的桃子数
  说    明：无
***************************************************************************/
int peaches(int days)
{
	if (days == 1)
		return 1;
	else
		return (peaches(days - 1) + 1) * 2 ;
}

int main()
{
	int days;

	cout << "请输入第几天的桃子数为1" << endl;
	cin >> days;		//输入[1-30]间的正整数即可，不考虑输入错误

	cout << "第1天买的桃子数量=" << peaches(days) << endl;

	return 0;
}

