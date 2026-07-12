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

void sort_by_score_decend(char student_id[][Len_student_id + 1], char student_name[][Len_student_name + 1], int student_score[])
{
	for (int i = 0; i < N_student - 1; i++)
	{
		for (int j = 0; j < N_student - 1 - i; j++)
		{
			if (student_score[j] - student_score[j + 1] < 0)
			{
				for (int k = 0; k < Len_student_id + 1; k++)
				{
					char tmp = student_id[j][k];
					student_id[j][k] = student_id[j + 1][k];
					student_id[j + 1][k] = tmp;
				}

				for (int k = 0; k < Len_student_name + 1; k++)
				{
					char tmp = student_name[j][k];
					student_name[j][k] = student_name[j + 1][k];
					student_name[j + 1][k] = tmp;
				}

				int tmp = student_score[j];
				student_score[j] = student_score[j + 1];
				student_score[j + 1] = tmp;
			}
		}
	}
}

void output_all(char student_id[][Len_student_id + 1], char student_name[][Len_student_name + 1], int student_score[])
{
	printf("\n");
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < N_student; i++)
	{
		printf("%s %s %d\n", student_name[i], student_id[i], student_score[i]);
	}
}

int main()
{
	char student_id[N_student][Len_student_id + 1];
	char student_name[N_student][Len_student_name + 1];
	int student_score[N_student];

	input_students(student_id, student_name, student_score);
	sort_by_score_decend(student_id, student_name, student_score);
	output_all(student_id, student_name, student_score);

	return 0;
}

