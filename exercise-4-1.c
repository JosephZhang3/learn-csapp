#include "stdio.h"

int str_index_most_right(const char source[], const char target[]);

int main() {
    char s[] = "Would not we shatter it to ould -- and then";
    char t[] = "ould";
    printf("%d\n", str_index_most_right(s, t));
}

/**
 * 返回字符数组（字符串）target在字符数组（字符串）source中的位置，注意是最后一次出现的位置
 */
int str_index_most_right(const char source[], const char target[]) {
    int i, j, k;

    // 设置一个变量暂存匹配到的索引位置，再次匹配到时，覆盖旧值
    int temp = -1;

    for (i = 0; source[i] != '\0'; i++) {
        for (j = i, k = 0; target[k] != '\0' && source[j] == target[k]; j++, k++) {
        }
        // 判断匹配到了
        if (k > 0 && target[k] == '\0') {
            temp = i;
        }
    }
    return temp;
}