#include "ctype.h"
#include "stdio.h"

double atof(char s[]);

int main() {
    char s[] = "-3223.66";
    printf("%f\n", atof(s));
}

/**
 * TODO 查看并仔细分析标准库中 atof 的实现，应该是很经典的，细节值得反复推敲的代码
 * 将代表数值的字符串转换成其真实数值
 *
 * @param s 代表数值的字符串
 * @return 真实数值
 */
double atof(char s[]) {
    // 跳过空格
    int i;
    for (i = 0; isspace(s[i]); i++) {
    }

    // 确定符号位
    int sign;
    sign = (s[i] == '-') ? -1 : 1;
    // 跳过 + 或 - 字符，因为上一行代码已经判定过了
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    // 确定整数部分
    double val = 0.0, power = 1.0;
    while (isdigit(s[i])) {
        // 2      2的权重为1
        // 28     2的权重为10，8的权重为1
        // 285    2的权重为100，8的权重为10，5的权重为1
        // 2853   2的权重为1000，8的权重为100，5的权重为10，3的权重为1
        // 总结：每增加一位，其前面的若干位的权重都要乘以10，然后加上最新的一位（个位）
        val = val * 10.0 + (s[i] - '0');
        i++;
    }

    // val是double类型，跳过小数点
    if (s[i] == '.') {
        i++;
    }

    // 上一个 if 已经判定是否为小数点。分两种可能
    // 1. 是小数点，之后出现n个数字，最后组合返回时就要除以10的n次幂
    // 2. 不是小数点，那就必然也不是数字了，直接去执行return语句吧。因为前面“确定整数部分”这段代码就已经把所有数字遍历完了
    while (isdigit(s[i])) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
        i++;
    }

    return sign * val / power;
}