/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double num;
	scanf("%lf", &num);
	num += 0.001;
	double int_part = floor(num);
	double frac_part = num - floor(num);
    printf("十亿位 : %.0f\n", floor(int_part / 1000000000));
    printf("亿位   : %.0f\n", fmod(floor(int_part / 100000000), 10.0));
    printf("千万位 : %.0f\n", fmod(floor(int_part / 10000000), 10.0));
    printf("百万位 : %.0f\n", fmod(floor(int_part / 1000000), 10.0));
    printf("十万位 : %.0f\n", fmod(floor(int_part / 100000), 10.0));
    printf("万位   : %.0f\n", fmod(floor(int_part / 10000), 10.0));
    printf("千位   : %.0f\n", fmod(floor(int_part / 1000), 10.0));
    printf("百位   : %.0f\n", fmod(floor(int_part / 100), 10.0));
    printf("十位   : %.0f\n", fmod(floor(int_part / 10), 10.0));
    printf("圆     : %.0f\n", fmod(int_part, 10.0));
    printf("角     : %.0f\n", fmod(floor(frac_part * 10), 10.0));
    printf("分     : %.0f\n", fmod(floor(frac_part * 100), 10.0));
	return 0;
}

