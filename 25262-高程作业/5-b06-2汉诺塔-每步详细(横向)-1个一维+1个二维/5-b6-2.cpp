/* 个人信息已删除 */
#include <iostream>
#include <iomanip>

using namespace std;

int tops[3] = { 0 };
int pillars[3][10] = { 0 };
int step_count = 0;

void print_pillar(int count, int arr[], bool is_last)
{
    for (int i = 0; i < count; i++)
    {
        cout << setw(2) << arr[i];
    }
    if (!is_last)
    {
        for (int i = 0; i < 20 - count * 2; i++)
        {
            cout << " ";
        }
    }
}

void print_state()
{
    cout << "A:";
    print_pillar(tops[0], pillars[0], false);
    cout << " B:";
    print_pillar(tops[1], pillars[1], false);
    cout << " C:";
    print_pillar(tops[2], pillars[2], true);
    cout << endl;
}

void move_disk(char src, char dst)
{
    int disk = 0;
    if (src == 'A')
        disk = pillars[0][--tops[0]];
    else if (src == 'B')
        disk = pillars[1][--tops[1]];
    else if (src == 'C')
        disk = pillars[2][--tops[2]];

    if (dst == 'A')
        pillars[0][tops[0]++] = disk;
    else if (dst == 'B')
        pillars[1][tops[1]++] = disk;
    else if (dst == 'C')
        pillars[2][tops[2]++] = disk;

    step_count++;
    cout << "第" << setw(4) << step_count << " 步(" << setw(2) << disk << "): " << src << "-->" << dst << " ";
    print_state();
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        move_disk(src, dst);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        move_disk(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n = 0;
    char src = 0, dst = 0;

    while (true)
    {
        cout << "请输入汉诺塔的层数(1-10)\n";
        if (cin >> n && n >= 1 && n <= 10)
        {
            cin.ignore(256, '\n');
            break;
        }
        cin.clear();
        cin.ignore(256, '\n');
    }

    while (true)
    {
        cout << "请输入起始柱(A-C)\n";
        if (cin >> src)
        {
            cin.ignore(256, '\n');
            if (src >= 'a' && src <= 'c')
                src -= 32;
            if (src >= 'A' && src <= 'C')
                break;
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    while (true)
    {
        cout << "请输入目标柱(A-C)\n";
        if (cin >> dst)
        {
            cin.ignore(256, '\n');
            if (dst >= 'a' && dst <= 'c')
                dst -= 32;
            if (dst == src)
            {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同\n";
            }
            else if (dst >= 'A' && dst <= 'C')
            {
                break;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    char tmp = 'A' + 'B' + 'C' - src - dst;

    for (int i = 0; i < n; i++)
    {
        if (src == 'A')
            pillars[0][tops[0]++] = n - i;
        else if (src == 'B')
            pillars[1][tops[1]++] = n - i;
        else if (src == 'C')
            pillars[2][tops[2]++] = n - i;
    }

    cout << "初始: ";
    print_state();
    hanoi(n, src, tmp, dst);

    return 0;
}

