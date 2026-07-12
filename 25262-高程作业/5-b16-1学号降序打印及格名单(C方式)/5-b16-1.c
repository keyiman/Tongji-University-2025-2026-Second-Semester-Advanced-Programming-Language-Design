/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N_student 10
#define Len_student_id 7
#define Len_student_name 8

void input_students(char student_id[][Len_student_id + 1], char student_name[][Len_student_name + 1], int student_score[])
{
	for (int i = 0; i < N_student; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", student_id[i], student_name[i], &student_score[i]);
	}
}

void sort_by_id_decend(char student_id[][Len_student_id + 1], char student_name[][Len_student_name + 1], int student_score[])
{
	for (int i = 0; i < N_student; i++)
	{
		int i_cur = i;

		for (int j = i + 1; j < N_student; j++)
		{
			if (strcmp(student_id[i_cur], student_id[j]) < 0)
			{
				i_cur = j;
			}
		}

		if (i_cur != i)
		{
			for (int j = 0; j < Len_student_id + 1; j++)
			{
				char tmp = student_id[i][j];
				student_id[i][j] = student_id[i_cur][j];
				student_id[i_cur][j] = tmp;
			}

			for (int j = 0; j < Len_student_name + 1; j++)
			{
				char tmp = student_name[i][j];
				student_name[i][j] = student_name[i_cur][j];
				student_name[i_cur][j] = tmp;
			}

			int tmp = student_score[i];
			student_score[i] = student_score[i_cur];
			student_score[i_cur] = tmp;
		}
	}
}

void output_passed(char student_id[][Len_student_id + 1], char student_name[][Len_student_name + 1], int student_score[])
{
	printf("\n");
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < N_student; i++)
	{
		if (student_score[i] >= 60)
		{
			printf("%s %s %d\n", student_name[i], student_id[i], student_score[i]);
		}
	}
}

int main()
{
	char student_id[N_student][Len_student_id + 1];
	char student_name[N_student][Len_student_name + 1];
	int student_score[N_student];

	input_students(student_id, student_name, student_score);
	sort_by_id_decend(student_id, student_name, student_score);
	output_passed(student_id, student_name, student_score);

	return 0;
}

