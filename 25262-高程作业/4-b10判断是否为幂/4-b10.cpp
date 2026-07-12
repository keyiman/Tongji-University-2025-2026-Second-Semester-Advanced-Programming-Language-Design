/* 个人信息已删除 */
#include <iostream>
using namespace std;

   /***************************************************************************
     函数名称：is_power
     功    能：求num是不是base的幂
     输入参数：int num, int base
     返 回 值：0 - 不是
               1 - 是
     说    明：函数名、形参、返回类型均不准动
   ***************************************************************************/
int is_power(int num, int base)
{
    if (num == 1)
    {
        return 1;
    }
    else if (num % base != 0)
    {
        return 0;
    }
    else
    {
        return is_power(num / base, base);
    }
}

int main()
{
    int num, base;
    cout << "请输入整数num及基数base" << endl;
    cin >> num >> base;
    switch (is_power(num, base))
    {
        case 1:
            cout << num << "是" << base << "的幂" << endl;
            break;
        case 0:
            cout << num << "不是" << base << "的幂" << endl;
            break;
    }
    return 0;
}

