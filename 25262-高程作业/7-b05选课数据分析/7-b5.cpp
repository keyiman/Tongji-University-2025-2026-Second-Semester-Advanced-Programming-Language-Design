/* 个人信息已删除 */
/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN        512 //定义文件名的最大长度

/* stu_merge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
    int  stu_no;                  //学号
    char stu_name[MAX_NAME_LEN];  //姓名

    /* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
    int round_status;             // 1: 仅第一轮, 2: 仅第二轮, 3: 一二轮都有
    friend class stu_list;
public:
    //本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
    student list_round_1[MAX_STU_NUM];  //第一轮选课的学生名单（不排序、不去重）
    int list_num_1;                     //第一轮选课的学生人数

    student list_round_2[MAX_STU_NUM];  //第二轮选课的学生名单（不排序、不去重）
    int list_num_2;                     //第二轮选课的学生人数

    stu_merge list_merge[MAX_STU_NUM];  //合并后的学生名单（去重，按升序排列）
    int list_merge_num;                 //合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

    /* 允许按需加入private数据成员和成员函数
       注意，不允许加入array / set / map / vector等STL容器 */

public:
    stu_list();                                       //构造函数，按需完成初始化功能，如果不需要，保留空函数即可
    int read(const char* filename, const int round);  //从文件中读入选课信息，round为1/2，表示选课轮次
    int print(const char* prompt = NULL);             //打印最终的选课名单

    /* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
       不允许定义公有的数据成员
       不允许在成员函数中使用array / set / map / vector等STL容器 */
    void process();
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
stu_list::stu_list()
{
    list_num_1 = 0;
    list_num_2 = 0;
    list_merge_num = 0;
}

/***************************************************************************
  函数名称： process
  功    能： 合并两轮选课名单、去重，并按学号升序排序
  输入参数： 无
  返 回 值： 无
  说    明： 独立统计两轮出现状态，彻底解决两轮文件中各自去重与交叉重复问题
***************************************************************************/
void stu_list::process()
{
    this->list_merge_num = 0;

    // 1. 扫描第一轮选课名单
    for (int i = 0; i < this->list_num_1; i++)
    {
        int current_no = this->list_round_1[i].no;
        bool found = false;

        // 检查是否已经在合并列表中
        for (int j = 0; j < this->list_merge_num; j++)
        {
            if (this->list_merge[j].stu_no == current_no)
            {
                found = true;
                break;
            }
        }

        // 如果是新学生，加入合并列表
        if (!found)
        {
            this->list_merge[this->list_merge_num].stu_no = current_no;
            strcpy(this->list_merge[this->list_merge_num].stu_name, this->list_round_1[i].name);
            // 先初始化状态：只在第一轮出现
            this->list_merge[this->list_merge_num].round_status = 1;
            this->list_merge_num++;
        }
    }

    // 2. 扫描第二轮选课名单
    for (int i = 0; i < this->list_num_2; i++)
    {
        int current_no = this->list_round_2[i].no;
        bool found = false;

        // 检查是否已经在合并列表中
        for (int j = 0; j < this->list_merge_num; j++)
        {
            if (this->list_merge[j].stu_no == current_no)
            {
                // 如果在第一轮中出现过（当前状态为1），或者之前已经更新过（当前状态为3）
                if (this->list_merge[j].round_status == 1 || this->list_merge[j].round_status == 3)
                {
                    this->list_merge[j].round_status = 3; // 判定为两轮均有
                }
                found = true;
                break;
            }
        }

        // 如果第一轮没出现过，且第二轮里是第一次遇到他
        if (!found)
        {
            this->list_merge[this->list_merge_num].stu_no = current_no;
            strcpy(this->list_merge[this->list_merge_num].stu_name, this->list_round_2[i].name);
            this->list_merge[this->list_merge_num].round_status = 2; // 判定为仅在第二轮（补选）
            this->list_merge_num++;
        }
    }

    // 3. 按学号进行升序排序 (标准冒泡排序)
    for (int i = 0; i < this->list_merge_num - 1; i++)
    {
        for (int j = 0; j < this->list_merge_num - 1 - i; j++)
        {
            if (this->list_merge[j].stu_no > this->list_merge[j + 1].stu_no)
            {
                stu_merge temp = this->list_merge[j];
                this->list_merge[j] = this->list_merge[j + 1];
                this->list_merge[j + 1] = temp;
            }
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
    int ret = 0;
    /* 读取第1/2轮的选课名单并打印 */
    switch (round) {
        case 1:
            this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
            if (this->list_num_1 > 0)
                print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
            else
                ret = -1;
            break;
        case 2:
            this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
            if (this->list_num_2 > 0)
                print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
            else
                ret = -1;
            break;
        default:
            ret = -1;
            break;
    }

    return ret;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
    if (prompt != NULL) 
    {
        cout << prompt << endl;
    }

    // 动态计算姓名列的最大宽度，以最长的姓名为准或"姓名"本身长度
    int max_name_len = (int)strlen("姓名");
    for (int i = 0; i < this->list_merge_num; i++)
    {
        int len = (int)strlen(this->list_merge[i].stu_name);
        if (len > max_name_len)
        {
            max_name_len = len;
        }
    }

    // 计算总宽度：首尾各1个空格(2) + 序号(4) + 学号(7) + 姓名(max_name_len) + 第一轮(6) + 第二轮(6) + 4个间隔的两个空格(8)
    int total_width = 1 + 4 + 2 + 7 + 2 + max_name_len + 2 + 6 + 2 + 6 + 1;

    // 打印表头顶部分隔线
    for (int i = 0; i < total_width; i++) cout << "=";
    cout << endl;

    // 打印表头
    cout << " " << left << setw(4) << "序号"
        << "  " << left << setw(7) << "学号"
        << "  " << left << setw(max_name_len) << "姓名"
        << "  " << left << setw(6) << "第一轮"
        << "  " << left << setw(6) << "第二轮" << " " << endl;

    // 打印表头底部分隔线
    for (int i = 0; i < total_width; i++) cout << "=";
    cout << endl;

    // 打印列表明细
    for (int i = 0; i < this->list_merge_num; i++)
    {
        const char* round1_str = "";
        const char* round2_str = "";

        if (this->list_merge[i].round_status == 1)
        {
            round1_str = "Y";
            round2_str = "退课";
        }
        else if (this->list_merge[i].round_status == 2)
        {
            round1_str = "/";
            round2_str = "补选";
        }
        else if (this->list_merge[i].round_status == 3)
        {
            round1_str = "Y";
            round2_str = "Y";
        }

        cout << " " << left << setw(4) << (i + 1)
            << "  " << left << setw(7) << this->list_merge[i].stu_no
            << "  " << left << setw(max_name_len) << this->list_merge[i].stu_name
            << "  " << left << setw(6) << round1_str
            << "  " << left << setw(6) << round2_str << " " << endl;
    }

    // 打印表尾分隔线
    for (int i = 0; i < total_width; i++) cout << "=";
    cout << endl;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
    char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

    cout << "请输入前一轮选课的数据文件 : ";
    cin >> file1;

    cout << "请输入后一轮选课的数据文件 : ";
    cin >> file2;

    stu_list list;

    /* 读入数据 */
    if (list.read(file1, 1) < 0)
        return -1;
    if (list.read(file2, 2) < 0)
        return -1;

    /* 处理数据 */
    list.process();

    /* 打印 */
    list.print("最终选课名单");

    return 0;
}

