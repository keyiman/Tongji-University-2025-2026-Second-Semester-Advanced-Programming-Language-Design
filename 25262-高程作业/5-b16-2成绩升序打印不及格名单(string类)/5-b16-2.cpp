/* 个人信息已删除 */
#include <iostream>
#include <string>
using namespace std;
#define N_student 10

void input_students(string student_id[], string student_name[], int student_score[])
{
	for (int i = 0; i < N_student; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩\n";
		cin >> student_id[i] >> student_name[i] >> student_score[i];
	}
}

void sort_by_score_ascend(string student_id[], string student_name[], int student_score[])
{
	for (int i = 0; i < N_student - 1; i++)
	{
		for (int j = 0; j < N_student - 1 - i; j++)
		{
			if (student_score[j] - student_score[j + 1] > 0)
			{
				string tmp_id = student_id[j];
				student_id[j] = student_id[j + 1];
				student_id[j + 1] = tmp_id;

				string tmp_name = student_name[j];
				student_name[j] = student_name[j + 1];
				student_name[j + 1] = tmp_name;

				int tmp = student_score[j];
				student_score[j] = student_score[j + 1];
				student_score[j + 1] = tmp;
			}
		}
	}
}

void output_failed(string student_id[], string student_name[], int student_score[])
{
	cout << "\n";
	cout << "不及格名单(成绩升序):\n";
	for (int i = 0; i < N_student; i++)
	{
		if (student_score[i] < 60)
		{
			cout << student_name[i] << " " << student_id[i] << " " << student_score[i] << endl;
		}
	}
}

int main()
{
	string student_id[N_student];
	string student_name[N_student];
	int student_score[N_student];

	input_students(student_id, student_name, student_score);
	sort_by_score_ascend(student_id, student_name, student_score);
	output_failed(student_id, student_name, student_score);

	return 0;
}

