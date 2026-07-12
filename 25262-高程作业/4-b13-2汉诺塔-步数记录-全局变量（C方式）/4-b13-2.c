/* 个人信息已删除 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */
int step = 1;

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
            3、本题采用全局变量记录步数
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        printf("%5d: %2d# %c-->%c\n", step++, n, src, dst);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d: %2d# %c-->%c\n", step++, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
***************************************************************************/
int main()
{
    int n = 0;
    char src = 0, dst = 0;
    int ret, ch; 

    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret = scanf("%d", &n);
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (ret == 1 && n >= 1 && n <= 16)
        {
            break;
        }
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
       
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (src >= 'a' && src <= 'c')
            src -= 32;

        if (ret == 1)
        {
            if (src >= 'a' && src <= 'c')
                src -= 32;

            if (src >= 'A' && src <= 'C')
            {
                break;
            }
        }
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (dst >= 'a' && dst <= 'c')
            dst -= 32;

        if (ret == 1)
        {
            if (dst >= 'a' && dst <= 'c')
                dst -= 32;

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

    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}

