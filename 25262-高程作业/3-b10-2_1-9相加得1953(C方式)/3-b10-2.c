/* 个人信息已删除 */
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int cnt = 0;
	for (int i = 123; i <= 987; i++)
	{
		for (int j = ((i + 1) > (966 - i)) ? (i + 1) : (966 - i); j <= 987; j++)
		{
			int k = 1953 - i - j;
			if (k < j)
			{
				break;
			}
			long long ijk = i * 1000000 + j * 1000 + k;
			long long temp1 = ijk;
			int flag = 0;
			while (temp1)
			{
				int d = temp1 % 10;
				if (d == 0)
				{
					flag = 1;
					break;
				}
				long long temp2 = temp1 / 10;
				while (temp2)
				{
					if (temp2 % 10 == d)
					{
						flag = 1;
						break;
					}
					temp2 /= 10;
				}
				if (flag)
				{
					break;
				}
				temp1 /= 10;
			}
			if (flag)
			{
				continue;
			}
			cnt++;
			printf("No.%3d : %d+%d+%d=1953\n", cnt, i, j, k);
		}
	}
	printf("total=%d\n", cnt);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}


