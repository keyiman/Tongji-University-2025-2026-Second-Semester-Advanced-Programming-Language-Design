/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
const double Pi = 3.14159;

int main()
{
	printf("请输入三角形的两边及其夹角(角度)\n");
	int a, b, angle;
	scanf("%d %d %d", &a, &b, &angle);
	float area = 0.5f * (float)a * (float)b * (float)sinf((float)angle * (float)Pi / 180.0f);
	printf("三角形面积为 : %.3f\n", area);
	return 0;
}

