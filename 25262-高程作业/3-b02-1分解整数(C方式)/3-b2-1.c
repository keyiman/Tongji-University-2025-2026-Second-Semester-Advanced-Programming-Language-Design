/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int a;
	scanf("%d", &a);
	printf("万位 : %d\n", a / 10000);
	printf("千位 : %d\n", (a / 1000) % 10);
	printf("百位 : %d\n", (a / 100) % 10);
	printf("十位 : %d\n", (a / 10) % 10);
	printf("个位 : %d\n", a % 10);
	return 0;
}

