/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int topA = 0, topB = 0, topC = 0;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int step = 0;

//打印单根柱子内容并补齐20字符宽度
void print_pillar(int count, int arr[], int is_last)
{
    // 1. 打印盘子，强制占用2个字符宽度
    for (int i = 0; i < count; i++)
    {
        printf("%2d", arr[i]);
    }

    // 2. 如果不是最后一根柱子，补齐剩余的预留字符宽度
    // 每个盘子占2格，所以一共打印了 count * 2 的宽度
    if (!is_last)
    {
        for (int i = 0; i < 20 - count * 2; i++)
        {
            printf(" ");
        }
    }
}

//打印一行完整状态
void print_state()
{
    printf("A:");
    print_pillar(topA, A, 0);
    printf(" B:");
    print_pillar(topB, B, 0);
    printf(" C:");
    print_pillar(topC, C, 1);
    printf("\n");
}

//出栈入栈模拟与打印
void move_disk(char src, char dst)
{
    int disk = 0;

    //出栈操作
    if (src == 'A') 
        disk = A[--topA];
    else if (src == 'B') 
        disk = B[--topB];
    else if (src == 'C') 
        disk = C[--topC];

    //入栈操作
    if (dst == 'A') 
        A[topA++] = disk;
    else if (dst == 'B')
        B[topB++] = disk;
    else if (dst == 'C') 
        C[topC++] = disk;

    step++;
    
    printf("第%4d 步(%2d): %c-->%c ", step, disk, src, dst);
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
    int ret, ch;

    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret = scanf("%d", &n);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if (ret == 1 && n >= 1 && n <= 10)
            break;
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (src >= 'a' && src <= 'c') src -= 32;
        if (ret == 1 && src >= 'A' && src <= 'C')
            break;
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (dst >= 'a' && dst <= 'c') dst -= 32;
        if (ret == 1)
        {
            if (dst == src)
            {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            }
            else if (dst >= 'A' && dst <= 'C')
            {
                break;
            }
        }
    }

    char tmp = 'A' + 'B' + 'C' - src - dst;

    
    for (int i = 0; i < n; i++)
    {
        if (src == 'A') 
            A[topA++] = n - i;
        else if (src == 'B')
            B[topB++] = n - i;
        else if (src == 'C')
            C[topC++] = n - i;
    }

    
    printf("初始:                ");
    print_state();

    hanoi(n, src, tmp, dst);

    return 0;
}

