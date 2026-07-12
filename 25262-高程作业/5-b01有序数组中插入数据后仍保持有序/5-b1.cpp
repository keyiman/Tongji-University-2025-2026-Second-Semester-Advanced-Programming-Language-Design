/* 个人信息已删除 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	
	int arr[25];
	int cnt = 0;
	
	while (cnt < 20)
	{
		cin >> arr[cnt];
		if (arr[cnt] <= 0)
		{
			break;
		}
		cnt++;
	}

	if (cnt == 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}

	if (cnt == 20)
	{
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF)
			;
	}

	cout << "原数组为：" << endl;
	
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;

	int insert;
	cin >> insert;

	int position = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (insert < arr[i])
		{
			position = i;
			break;
		}
		else
			position = cnt;
	}

	cout << "插入后的数组为：" << endl;
	int arr_temp[25];
	for (int i = 0; i < cnt + 1; i++)
	{
		if (i < position)
			arr_temp[i] = arr[i];
		if (i == position)
			arr_temp[i] = insert;
		if (i > position)
			arr_temp[i] = arr[i - 1];
	}
	for (int i = 0; i < cnt + 1; i++)
		arr[i] = arr_temp[i];
	
	for (int i = 0; i < cnt + 1; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}


