/* ¸öÈËÐÅÏ¢ÒÑÉ¾³ý */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n";
	double num;
	cin >> num;
	num += 0.001;
	double int_part = floor(num);
	double frac_part = num - floor(num);
	int d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, df1, df2;
	d10 = (int)floor(int_part / 1000000000);
	d9 = (int)fmod(floor(int_part / 100000000), 10.0);
	d8 = (int)fmod(floor(int_part / 10000000), 10.0); 
	d7 = (int)fmod(floor(int_part / 1000000), 10.0);
	d6 = (int)fmod(floor(int_part / 100000), 10.0);
	d5 = (int)fmod(floor(int_part / 10000), 10.0);
	d4 = (int)fmod(floor(int_part / 1000), 10.0);
	d3 = (int)fmod(floor(int_part / 100), 10.0);
	d2 = (int)fmod(floor(int_part / 10), 10.0);
	d1 = (int)fmod(int_part, 10.0);
	df1 = (int)fmod(floor(frac_part * 10), 10.0);
	df2 = (int)fmod(floor(frac_part * 100), 10.0);

	cout << "´óÐ´½á¹ûÊÇ:\n";

	//ÒÚÎ»
	int has_d = 0;
	if (d10 || d9)
	{
		if (d10)
		{
			switch (d10)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Ê°";
		}
		if (d9)
		{
			switch (d9)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
		}
		cout << "ÒÚ";
		has_d = 1;
	}

	//ÍòÎ»
	int need0_1 = 0;
	if (d8 || d7 || d6 || d5)
	{
		if (d8)
		{
			switch (d8)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Çª";
			has_d = 1;
		}
		else
		{
			need0_1 = 1;
		}

		if (d7)
		{
			if (need0_1 && has_d)
			{
				cout << "Áã";
			}
			switch (d7)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "°Û";
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		if (d6)
		{
			if (need0_1 && has_d)
			{
				cout << "Áã";
			}
			switch (d6)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Ê°";
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		if (d5)
		{
			if (need0_1 && has_d)
			{
				cout << "Áã";
			}
			switch (d5)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		cout << "Íò";

	}

	//¸öÎ»
	int need0_2 = 0;
	if (d4 || d3 || d2 || d1)
	{
		if (d4)
		{
			switch (d4)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Çª";
			has_d = 1;
		}
		else
		{
			need0_2 = 1;
		}

		if (d3)
		{
			if (need0_2 && has_d)
			{
				cout << "Áã";
			}
			switch (d3)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "°Û";
			has_d = 1;
			need0_2 = 0;
		}
		else
		{
			need0_2 = 1;
		}

		if (d2)
		{
			if (need0_2 && has_d)
			{
				cout << "Áã";
			}
			switch (d2)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Ê°";
			has_d = 1;
			need0_2 = 0;
		}
		else
		{
			need0_2 = 1;
		}

		if (d1)
		{
			if (need0_2 && has_d)
			{
				cout << "Áã";
			}
			switch (d1)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			has_d = 1;
			need0_2 = 0;
		}
	}

	if (has_d)
	{
		cout << "Ô²";
	}

	//½Ç·Ö
	if (df1 || df2)
	{
		if (df1)
		{
			switch (df1)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "½Ç";
		}
		else if (has_d && !df1)
		{
			cout << "Áã";
		}
		else
		{
			;
		}
		if (df2)
		{
			switch (df2)
			{
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èþ";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "·Ö";
		}
		else
		{
			cout << "Õû";
		}
	}
	else if ((df1 + df2) == 0 && has_d)
	{
		cout << "Õû";
	}
	else
	{
		cout << "ÁãÔ²Õû";
	}

	cout << "\n";

	return 0;
}


