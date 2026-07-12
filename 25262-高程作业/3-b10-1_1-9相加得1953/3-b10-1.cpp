/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

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
			cout << "No." << setw(3) << cnt << " : " << i << "+" << j << "+" << k << "=" << 1953 << endl;
		}
	}
	cout << "total=" << cnt << endl;

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}


