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

void sort_by_id_ascend(string student_id[], string student_name[], int student_score[])
{
	for (int i = 0; i < N_student; i++)
	{
		int i_cur = i;

		for (int j = i + 1; j < N_student; j++)
		{
			if (student_id[i_cur] > student_id[j])
			{
				i_cur = j;
			}
		}

		if (i_cur != i)
		{
			string tmp_id = student_id[i];
			student_id[i] = student_id[i_cur];
			student_id[i_cur] = tmp_id;

			string tmp_name = student_name[i];
			student_name[i] = student_name[i_cur];
			student_name[i_cur] = tmp_name;

			int tmp = student_score[i];
			student_score[i] = student_score[i_cur];
			student_score[i_cur] = tmp;
		}
	}
}

void output_all(string student_id[], string student_name[], int student_score[])
{
	cout << "\n";
	cout << "全部学生(学号升序):\n";
	for (int i = 0; i < N_student; i++)
	{
		cout << student_name[i] << " " << student_id[i] << " " << student_score[i] << endl;
	}
}

int main()
{
	string student_id[N_student];
	string student_name[N_student];
	int student_score[N_student];

	input_students(student_id, student_name, student_score);
	sort_by_id_ascend(student_id, student_name, student_score);
	output_all(student_id, student_name, student_score);

	return 0;
}

