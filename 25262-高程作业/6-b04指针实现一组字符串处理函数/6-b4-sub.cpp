/* 个人信息已删除 */
#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    if (str == NULL)
        return 0;

    int len = 0;
    const char* p = str;

    while (*p != '\0')
    {
        len++;
        p++;
    }

    return len;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    if (s1 == NULL || s2 == NULL)
        return s1 ? s1 : NULL;

    char* p1 = s1;
    const char* p2 = s2;

    while (*p1 != '\0')
        p1++;

    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }

    *p1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    if (s1 == NULL || s2 == NULL)
        return s1 ? s1 : NULL;

    char* p1 = s1;
    const char* p2 = s2;
    int count = 0;

    while (*p1 != '\0')
        p1++;

    while (count < len && *p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
        count++;
    }

    *p1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    if (s1 == NULL)
        return NULL;

    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }

    char* p1 = s1;
    const char* p2 = s2;

    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }

    *p1 = '\0';

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL || s2 == NULL)
        return s1 ? s1 : NULL;

    char* p1 = s1;
    const char* p2 = s2;
    int count = 0;

    while (count < len && *p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
        count++;
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    const char* p1 = s1;
    const char* p2 = s2;

    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
            return (*p1 - *p2);

        p1++;
        p2++;
    }

    return (*p1 - *p2);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    const char* p1 = s1;
    const char* p2 = s2;

    while (*p1 != '\0' && *p2 != '\0')
    {
        char c1 = *p1;
        char c2 = *p2;

        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 32;

        if (c1 != c2)
            return (c1 - c2);

        p1++;
        p2++;
    }

    char c1 = *p1;
    char c2 = *p2;

    if (c1 >= 'A' && c1 <= 'Z')
        c1 += 32;
    if (c2 >= 'A' && c2 <= 'Z')
        c2 += 32;

    return (c1 - c2);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    if (len <= 0)
        return 0;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;

    while (count < len && *p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
            return (*p1 - *p2);

        p1++;
        p2++;
        count++;
    }

    if (count == len)
        return 0;

    return (*p1 - *p2);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    if (len <= 0)
        return 0;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;

    while (count < len && *p1 != '\0' && *p2 != '\0')
    {
        char c1 = *p1;
        char c2 = *p2;

        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 32;

        if (c1 != c2)
            return (c1 - c2);

        p1++;
        p2++;
        count++;
    }

    if (count == len)
        return 0;

    char c1 = *p1;
    char c2 = *p2;

    if (c1 >= 'A' && c1 <= 'Z')
        c1 += 32;
    if (c2 >= 'A' && c2 <= 'Z')
        c2 += 32;

    return (c1 - c2);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    if (str == NULL)
        return NULL;

    char* p = str;

    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;

        p++;
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    if (str == NULL)
        return NULL;

    char* p = str;

    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;

        p++;
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;

    const char* p = str;
    int pos = 1;

    while (*p != '\0')
    {
        if (*p == ch)
            return pos;

        p++;
        pos++;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    if (*substr == '\0')
        return 1;

    const char* p1 = str;
    int pos = 1;

    while (*p1 != '\0')
    {
        const char* temp_p1 = p1;
        const char* temp_sub = substr;

        while (*temp_p1 != '\0' && *temp_sub != '\0' && *temp_p1 == *temp_sub)
        {
            temp_p1++;
            temp_sub++;
        }

        if (*temp_sub == '\0')
            return pos;

        p1++;
        pos++;
    }

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;

    const char* p = str;
    int pos = 1;
    int last_pos = 0;

    while (*p != '\0')
    {
        if (*p == ch)
            last_pos = pos;

        p++;
        pos++;
    }

    return last_pos;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    if (*substr == '\0')
        return tj_strlen(str);

    const char* p1 = str;
    int pos = 1;
    int last_pos = 0;

    while (*p1 != '\0')
    {
        const char* temp_p1 = p1;
        const char* temp_sub = substr;

        while (*temp_p1 != '\0' && *temp_sub != '\0' && *temp_p1 == *temp_sub)
        {
            temp_p1++;
            temp_sub++;
        }

        if (*temp_sub == '\0')
            last_pos = pos;

        p1++;
        pos++;
    }

    return last_pos;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    if (str == NULL)
        return NULL;

    char* left = str;
    char* right = str;

    while (*right != '\0')
        right++;

    if (left == right)
        return str;

    right--;

    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    return str;
}


