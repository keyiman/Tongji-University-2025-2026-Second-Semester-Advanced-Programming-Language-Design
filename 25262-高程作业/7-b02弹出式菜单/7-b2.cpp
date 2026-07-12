/* 个人信息已删除 */
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"

#define POPMENU_MAX_DRAW_WIDTH 1000
#define POPMENU_TMP_LEN        (POPMENU_MAX_DRAW_WIDTH + 16)

/* 判断是否为合法的 GBK 汉字字节 (0xA1 ~ 0xFE) */
static int is_gbk_byte(const unsigned char ch)
{
    return (ch >= 0xA1 && ch <= 0xFE);
}

/* 判断当前位置是否是一个完整的 GBK 汉字（由两个连续的 GBK 字节组成） */
static int is_gbk_pair(const char* s, const int pos)
{
    if (s == NULL || s[pos] == '\0' || s[pos + 1] == '\0')
        return 0;

    return is_gbk_byte((unsigned char)s[pos]) && is_gbk_byte((unsigned char)s[pos + 1]);
}

static int str_display_len(const char* s)
{
    int i;
    int len;

    if (s == NULL)
        return 0;

    for (i = 0, len = 0; s[i] != '\0'; ) {
        if (is_gbk_pair(s, i)) {
            len += 2; // 汉字视觉长度为 2
            i += 2;   // 汉字占用 2 个字节
        }
        else {
            len++;
            i++;
        }
    }

    return len;
}

static void make_fit_string(const char* src, const int width, char dest[], const int dest_size)
{
    int i;
    int pos;
    int used;
    int max_width;

    if (dest_size <= 0)
        return;

    dest[0] = '\0';
    if (width <= 0)
        return;

    max_width = width;
    if (max_width > dest_size - 1)
        max_width = dest_size - 1;

    i = 0;
    pos = 0;
    used = 0; // 记录当前已经使用的视觉宽度

    while (src != NULL && src[i] != '\0' && used < max_width && pos < dest_size - 1) {
        if (is_gbk_pair(src, i)) {
            // 如果剩余的宽度不足以容纳一个完整的汉字（需要2个宽度），则跳出循环，交由后面的代码补空格
            if (used + 2 > max_width || pos + 2 >= dest_size)
                break;

            dest[pos++] = src[i++];
            dest[pos++] = src[i++];
            used += 2;
        }
        else {
            dest[pos++] = src[i++];
            used++;
        }
    }

    // 如果原字符串长度不足 width，或者因为半个汉字退出了循环，用空格将剩余宽度填满
    while (used < max_width && pos < dest_size - 1) {
        dest[pos++] = ' ';
        used++;
    }

    dest[pos] = '\0';
}

/* 构造单个边框字符 (GBK: 0xA8 + code) */
static void make_line_char(char dest[], const char code)
{
    dest[0] = (char)0xA8;
    dest[1] = code;
    dest[2] = '\0';
}

/* 向已有字符串追加单个边框字符 */
static void append_line_char(char dest[], int* pos, const char code)
{
    dest[*pos] = (char)0xA8;
    (*pos)++;
    dest[*pos] = code;
    (*pos)++;
    dest[*pos] = '\0';
}

/* 构造水平边框行（例如菜单的顶部和底部边框）。
   左上角/左下角 (left) + 横线 (mid) + 右上角/右下角 (right)
*/
static void make_border_row(char dest[], const int width, const char left, const char mid, const char right)
{
    int i;
    int pos;
    int n;

    pos = 0;
    append_line_char(dest, &pos, left);

    n = width / 2; // width 是偶数，每个制表符占 2 个宽度，所以循环 width / 2 次
    for (i = 0; i < n; i++)
        append_line_char(dest, &pos, mid);

    append_line_char(dest, &pos, right);
    dest[pos] = '\0';
}

/* 构造菜单中间的空白行（包含左右两条竖线）。
*/
static void make_middle_row(char dest[], const int width)
{
    int i;
    int pos;

    pos = 0;
    append_line_char(dest, &pos, 'U');      /* 竖双线 ║ */

    for (i = 0; i < width; i++)
        dest[pos++] = ' ';

    append_line_char(dest, &pos, 'U');      /* 竖双线 ║ */
    dest[pos] = '\0';
}

/* 统计二维数组中菜单项的数量（直到遇到全零或首字符为 \0 的项） */
static int count_menu_items(const char menu[][MAX_ITEM_LEN])
{
    int n;

    if (menu == NULL)
        return 0;

    for (n = 0; menu[n][0] != '\0'; n++)
        ;

    return n;
}

/* 寻找字符串中第一个可见的 ASCII 字符（跳过前面的空格） */
static int first_visible_ascii(const char s[])
{
    int i;

    if (s == NULL)
        return 0;

    for (i = 0; s[i] == ' '; i++)
        ;

    return (unsigned char)s[i];
}

/* 将大写字母转换为小写字母 */
static int to_lower_ascii(const int ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';

    return ch;
}

/* 匹配键盘按下的快捷键是否对应某个菜单项的首字母 */
static int find_hotkey_item(const char menu[][MAX_ITEM_LEN], const int item_num, const int key)
{
    int i;
    int first;
    int low_key;

    low_key = to_lower_ascii(key);

    for (i = 0; i < item_num; i++) {
        first = first_visible_ascii(menu[i]);
        if (first != 0 && to_lower_ascii(first) == low_key)
            return i;
    }

    return -1;
}

static int get_row_span(const int start_x, const int draw_width, int* buffer_cols)
{
    int cols;
    int lines;
    int bcols;
    int blines;
    int span;

    cct_getconsoleborder(cols, lines, bcols, blines);
    if (buffer_cols != NULL)
        *buffer_cols = bcols;

    if (bcols <= 0)
        return 1;

    span = (draw_width + bcols - 1) / bcols;
    if (span < 1)
        span = 1;

    return span;
}

/* 绘制整个菜单的外层框架（包含顶部、中间背景、底部以及标题） */
static void draw_frame(const struct PopMenu* para, const int width, const int high, const int row_span)
{
    int i;
    int title_len;
    int title_width;
    int title_x;
    int offset;
    char row[POPMENU_TMP_LEN];
    char title[POPMENU_TMP_LEN];

    make_border_row(row, width, 'X', 'T', '[');     /* 顶部：角，横线，角 */
    cct_showstr(para->start_x, para->start_y, row, para->bg_color, para->fg_color, 1);

    make_middle_row(row, width);
    for (i = 0; i < high; i++)
        cct_showstr(para->start_x, para->start_y + (i + 1) * row_span, row, para->bg_color, para->fg_color, 1);

    make_border_row(row, width, '^', 'T', 'a');     /* 底部：角，横线，角 */
    cct_showstr(para->start_x, para->start_y + (high + 1) * row_span, row, para->bg_color, para->fg_color, 1);

    // 绘制标题并居中，如果是奇数长度，会补一个空格凑成偶数
    title_len = str_display_len(para->title);
    if (title_len > 0) {
        title_width = title_len;
        if (title_width % 2 != 0)
            title_width++;

        make_fit_string(para->title, title_width, title, POPMENU_TMP_LEN);

        offset = (width - title_width) / 2;
        if (offset % 2 != 0) {
            offset--;
        }

        title_x = para->start_x + 2 + offset;
        cct_showstr(title_x, para->start_y, title, para->bg_color, para->fg_color, 1);
    }
}

/* 绘制所有的菜单项字符串，选中项 (current_item) 的颜色反转 */
static void draw_items(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para,
    const int width, const int high, const int top_item,
    const int current_item, const int row_span)
{
    int i;
    int index;
    int bg;
    int fg;
    char item[POPMENU_TMP_LEN];

    for (i = 0; i < high; i++) {
        index = top_item + i;
        if (index == current_item) { // 选中项反色
            bg = para->fg_color;
            fg = para->bg_color;
        }
        else { // 正常项
            bg = para->bg_color;
            fg = para->fg_color;
        }

        make_fit_string(menu[index], width, item, POPMENU_TMP_LEN);
        cct_showstr(para->start_x + 2, para->start_y + (i + 1) * row_span, item, bg, fg, 1);
    }
}

/* 对传入的参数进行合法性检查和归一化处理 */
static void normalize_parameter(struct PopMenu* para)
{
    int title_len;

    if (para->width < 0)
        para->width = 0;

    if (para->width % 2 != 0)
        para->width++;

    title_len = str_display_len(para->title);
    if (title_len % 2 != 0)
        title_len++;

    if (para->width < title_len)
        para->width = title_len;

    if (para->width < 2)
        para->width = 2;

    if (para->width > POPMENU_MAX_DRAW_WIDTH)
        para->width = POPMENU_MAX_DRAW_WIDTH;

    if (para->width % 2 != 0)
        para->width++;

    if (para->high < 0)
        para->high = 0;
}

/* 上下滚动菜单时，保持高亮选中的菜单项在可见区域内 */
static void keep_current_visible(const int item_num, const int high, int* top_item, int* current_item)
{
    if (*current_item < 0)
        *current_item = 0;
    if (*current_item >= item_num)
        *current_item = item_num - 1;

    if (*top_item < 0)
        *top_item = 0;
    if (*top_item > item_num - high)
        *top_item = item_num - high;
    if (*top_item < 0)
        *top_item = 0;

    if (*current_item < *top_item)
        *top_item = *current_item;
    else if (*current_item >= *top_item + high)
        *top_item = *current_item - high + 1;
}

/* 向上移动选中光标，若到顶则循环回底部 */
static void move_up(const int item_num, const int high, int* top_item, int* current_item)
{
    if (item_num <= 0)
        return;

    if (*current_item > 0)
        (*current_item)--;
    else
        *current_item = item_num - 1;

    keep_current_visible(item_num, high, top_item, current_item);
}

/* 向下移动选中光标，若到底则循环回顶部 */
static void move_down(const int item_num, const int high, int* top_item, int* current_item)
{
    if (item_num <= 0)
        return;

    if (*current_item < item_num - 1)
        (*current_item)++;
    else
        *current_item = 0;

    keep_current_visible(item_num, high, top_item, current_item);
}

/***************************************************************************
  函数名称: pop_menu
  返回值  : 选中的菜单项编号，从 1 开始计数；返回 0 表示未选择(如按ESC取消)。
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    struct PopMenu para;
    int item_num;
    int high;
    int current_item;
    int top_item;
    int row_span;
    int buffer_cols;
    int mx, my, maction; // 仅为填补底层 API 参数占位使用
    int key1;
    int key2;
    int event_type;
    int ret;
    int hot_item;

    if (original_para == NULL || menu == NULL)
        return 0;

    para = *original_para;
    normalize_parameter(&para); // 参数归一化（纠正奇偶与宽度限制）

    item_num = count_menu_items(menu);
    high = para.high;
    if (high > item_num)
        high = item_num; // 实际项数小于指定高度时，缩小边框

    // 获取单行菜单在控制台中的逻辑跨距（解决折行排版问题的关键）
    row_span = get_row_span(para.start_x, para.width + 4, &buffer_cols);

    cct_setcursor(CCT_CURSOR_INVISIBLE); // 隐藏闪烁光标
    draw_frame(&para, para.width, high, row_span); // 画框

    current_item = 0; // 当前选中项索引
    top_item = 0;     // 顶部可见项索引
    draw_items(menu, &para, para.width, high, top_item, current_item, row_span); // 渲染内容

    ret = 0;

    // 主事件循环
    while (1) {
        mx = my = maction = key1 = key2 = 0;
        event_type = cct_read_keyboard_and_mouse(mx, my, maction, key1, key2);

        // 仅处理键盘事件
        if (event_type == CCT_KEYBOARD_EVENT) {
            if (key1 == 0xE0 && key2 == KB_ARROW_UP) { // 上方向键
                move_up(item_num, high, &top_item, &current_item);
                draw_items(menu, &para, para.width, high, top_item, current_item, row_span);
            }
            else if (key1 == 0xE0 && key2 == KB_ARROW_DOWN) { // 下方向键
                move_down(item_num, high, &top_item, &current_item);
                draw_items(menu, &para, para.width, high, top_item, current_item, row_span);
            }
            else if (key1 == '\r') { // 回车键确认选择
                if (item_num > 0)
                    ret = current_item + 1;
                else
                    ret = 0;
                break;
            }
            else if (key1 == 27) { // ESC键退出
                ret = 0;
                break;
            }
            else if (key1 > 0) { // 其它按键匹配首字母快捷键
                hot_item = find_hotkey_item(menu, item_num, key1);
                if (hot_item >= 0) {
                    ret = hot_item + 1;
                    break;
                }
            }
        }
    }

    cct_setcursor(CCT_CURSOR_VISIBLE_NORMAL);
    cct_setcolor();
    return ret;
}

