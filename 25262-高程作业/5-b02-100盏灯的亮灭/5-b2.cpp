/* 个人信息已删除 */
#include <iostream>
using namespace std;

const int N = 110;

int main()
{
	int light[N] = { 0 };
	for (int i = 1; i <= 100; i++)
	{
		for (int j = i; j <= 100; j += i)
		{
			light[j] = !light[j];
		}
	}

	int isfirst = 1;

	for (int i = 1; i <= 100; i++)
	{
		if (light[i] == 1 && isfirst)
		{
			cout << i;
			isfirst = 0;
		}
		else if(light[i] == 1 && !isfirst)
		{
			cout << " " << i;
		}
	}
	cout << endl;
	
	return 0;
}


