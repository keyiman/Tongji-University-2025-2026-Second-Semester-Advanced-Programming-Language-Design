/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

   /***************************************************************************
	 函数名称：convert
	 功    能：将整数n分解后输出
	 输入参数：int n整数
	 返 回 值：空
	 说    明：1、函数名、形参、返回类型均不准动
			   2、不允许使用64位整数
   ***************************************************************************/
void convert(int n)
{
	if (n < 0)
	{
		printf("%c ", '0' - n % 10);
		if (n / 10 != 0)
		{
			convert(n / 10);
		}
		else
			printf("-");
	}
	else
	{
		printf("%c ", '0' + n % 10);
		if (n / 10 != 0)
		{
			convert(n / 10);
		}
	}
}

int main()
{
	int n;
	printf("请输入一个整数\n");
	scanf("%d", &n);

	convert(n);
	printf("\n");

	return 0;
}

