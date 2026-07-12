/* ¸öÈËÐÅÏ¢ÒÑÉ¾³ý */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double num;
	scanf("%lf", &num);
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

	printf("´óÐ´½á¹ûÊÇ:\n");

	//ÒÚÎ»
	int has_d = 0;
	if (d10 || d9)
	{
		if (d10)
		{
			switch (d10)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Ê°");
		}
		if (d9)
		{
			switch (d9)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
		}
		printf("ÒÚ");
		has_d = 1;
	}

	//ÍòÎ»
	int need0_1 = 0;
	if (d8 || d7 || d6 || d5 )
	{
		if (d8)
		{
			switch (d8)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Çª");
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
				printf("Áã");
			}
			switch (d7)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("°Û");
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
				printf("Áã");
			}
			switch (d6)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Ê°");
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
				printf("Áã");
			}
			switch (d5)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			has_d = 1;
			need0_1 = 0;
		}
		else
		{
			need0_1 = 1;
		}

		printf("Íò");
		
	}
	
	//¸öÎ»
	int need0_2 = 0;
	if (d4 || d3|| d2 || d1)
	{
		if (d4)
		{
			switch (d4)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Çª");
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
				printf("Áã");
			}
			switch (d3)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("°Û");
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
				printf("Áã");
			}
			switch (d2)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Ê°");
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
				printf("Áã");
			}
			switch (d1)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			has_d = 1;
			need0_2 = 0;
		}
	}

	if (has_d)
	{
		printf("Ô²");
	}
	
	
	
	//½Ç·Ö
	
	if (df1 || df2)
	{
		if (df1)
		{
			switch (df1)
			{
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("½Ç");
		}
		else if(has_d && !df1)
		{
			printf("Áã");
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
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("·Ö");
		}
		else
		{
			printf("Õû");
		}
	}
	else if((df1 + df2) == 0 && has_d)
	{
		printf("Õû");
	}
	else
	{
		printf("ÁãÔ²Õû");
	}

	printf("\n");

	return 0;
}


