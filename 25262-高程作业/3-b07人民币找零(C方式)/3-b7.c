/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入找零值：\n");
	double q;
	scanf("%lf", &q);

	int fen = (int)(q * 100 + 0.5);
	
	int cnt50, cnt20, cnt10, cnt5, cnt1, cnt_5, cnt_1, cnt_05, cnt_02, cnt_01;
	int cnt;


	cnt50 = fen / 5000;
	fen %= 5000;
	cnt20 = fen / 2000;
	fen %= 2000;
	cnt10 = fen / 1000;
	fen %= 1000;
	cnt5 = fen / 500;
	fen %= 500;
	cnt1 = fen / 100;
	fen %= 100;
	cnt_5 = fen / 50;
	fen %= 50;
	cnt_1 = fen / 10;
	fen %= 10;
	cnt_05 = fen / 5;
	fen %= 5;
	cnt_02 = fen / 2;
	fen %= 2;
	cnt_01 = fen;

	cnt = cnt50 + cnt20 + cnt10 + cnt5 + cnt1 + cnt_5 + cnt_1 + cnt_05 + cnt_02 + cnt_01;

	printf("共%d张找零，具体如下：\n", cnt);
	if(cnt50)
		printf("50元 : %d张\n", cnt50);
	if(cnt20)
		printf("20元 : %d张\n", cnt20);
	if(cnt10)
		printf("10元 : %d张\n", cnt10);
	if(cnt5)
		printf("5元  : %d张\n", cnt5);
	if(cnt1)
		printf("1元  : %d张\n", cnt1);
	if(cnt_5)
		printf("5角  : %d张\n", cnt_5);
	if(cnt_1)
		printf("1角  : %d张\n", cnt_1);
	if(cnt_05)
		printf("5分  : %d张\n", cnt_05);
	if(cnt_02)
		printf("2分  : %d张\n", cnt_02);
	if(cnt_01)
		printf("1分  : %d张\n", cnt_01);
	return 0;
}


