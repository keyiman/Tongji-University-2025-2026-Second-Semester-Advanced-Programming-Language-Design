/* 个人信息已删除 */
#include <iostream>
using namespace std;

#define N 1010

int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int score[N] = { 0 };
	int cnt = 0;

	while (cnt < 1000)
	{
		int in_score;
		if (!(cin >> in_score) || in_score < 0)
		{
			break;
		}
		score[cnt] = in_score;
		cnt++;
	}

	if (cnt == 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (i % 10 == 0 && i != 0)
			cout << endl;

		cout << score[i] << " ";
	}
	cout << endl;

	cout << "分数与名次的对应关系为:" << endl;

	int n[101] = { 0 };
	int rank = 1;
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
			for(int x = n[i]; x >= 1; x--)
				cout << i << " " << rank << endl;

			rank += n[i];
		}
	}

	return 0;
}

