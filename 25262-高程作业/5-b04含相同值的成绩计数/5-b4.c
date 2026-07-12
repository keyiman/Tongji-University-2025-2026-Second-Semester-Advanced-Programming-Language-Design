/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1010

int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int score[N] = { 0 };
	int cnt = 0;

	while (cnt < 1000)
	{
		int in_score;
		if (scanf("%d", &in_score) == EOF || in_score < 0)
		{
			break;
		}
		score[cnt] = in_score;
		cnt++;
	}

	if (cnt == 0)
	{
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (int i = 0; i < cnt; i++)
	{
		if (i % 10 == 0 && i != 0)
			printf("\n");

		printf("%d ", score[i]);
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");

	int n[101] = { 0 };
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (score[j] == i)
			{
				n[i]++;
			}
		}
	}

	for (int i = 100; i >= 0; i--)
	{
		if (n[i] > 0)
		{
			printf("%d %d\n", i, n[i]);
		}
	}

	return 0;
}


