#include <stdio.h>

#define MAX_LINE 1000 /* 一行最多输入字符数 */

// 先声明，后使用
int my_get_line(char s[], int limit);

int str_index(const char source[], const char target[]);

int grep();

char pattern[] = "ould"; // 待查找的“模式”（一种匹配规则）

/**
 * 程序运行时需要使用管道从文件 grep_like 重定向输入
 * @return
 */
int main() {
    grep();
}

/**
 * 查找并打印包含指定模式的行，记录行数并返回
 */
int grep() {
    char line[MAX_LINE];
    int found = 0;
    int i = -1;

    // 循环每次读取一行
    while (my_get_line(line, MAX_LINE)) {
        // 判断是否包含指定模式
        i = str_index(line, pattern);
        if (i >= 0) {
            // 打印这一行
            printf("%s", line);
            // 打印“模式”在这一行出现的索引位置
            printf("模式%s在索引位置%d处出现\n", pattern, i);
            // 记录行数
            found++;
        }
    }
    printf("\n");
    printf("%d\n", line[0]);
    printf("%c\n", line[1]);
    printf("%c\n", line[2]);
    printf("%c\n", line[3]);
    printf("%c\n", line[4]);
    printf("%c\n", line[5]);
    return found;
}

/**
 * 读取一行，返回一行的字符总数（包含换行符）
 * 不新开字符串数组，而是在传入字符数组（容量限制为 MAX_LINE ）的基础上覆写
 */
int my_get_line(char s[], int limit) {
    int i = 0, c;
    // limit先自减然后作为表达式的值（每读入一个字符就减去1），扫描console读入的字符既不是文件结束符也不是换行符
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n') {
        // i从0开始，先作为表达式的值然后自增
        s[i++] = (char) c;
    }
    // 如果遇到的是换行符
    if (c == '\n') {
        // 把换行符作为字符数组倒数第二个字符（字符数组并未填满）
        s[i++] = (char) c;
    }
    // 字符数组最后一个字符设定为字符串结束标识（字符数组并未填满）
    s[i] = '\0';
    return i;
}

/**
 * 返回字符数组（字符串）target在字符数组（字符串）source中的位置
 */
int str_index(const char source[], const char target[]) {
    int i, j, k;

    // 遍历source数组直到其结尾
    for (i = 0; source[i] != '\0'; i++) {
        // 从索引i处开始尝试匹配，循环结束只有两种情况
        // 1、target[]被遍历完毕（隐含意思：target[]字符序列跟source[]中从索引i处开始的一段字符序列完全匹配）
        // 2、当target[]还没被遍历完毕时，就发现target[k]跟source[]中的从索引i处开始的第k+1个字符不匹配
        for (j = i, k = 0; target[k] != '\0' && source[j] == target[k]; j++, k++) {
        }
        // 匹配到了不止一个字符，并且最后发现整个字符数组都完全匹配
        if (k > 0 && target[k] == '\0') {
            return i;
        }
    }
    return -1;
}