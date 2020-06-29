#include<stdio.h>
#include "limits.h"

int tadd_ok(int x, int y) {
    int sum = x + y;
    printf("x + y equals %d\n", sum);
    int positive_overflow = x >= 0 && y >= 0 && sum < 0;
    int negative_overflow = x < 0 && y < 0 && sum >= 0;// 当x和y均为 -2147483648 时，溢出结果刚好等于0
    return !positive_overflow && !negative_overflow;
}

int main() {
    printf("INT_MAX is %d  (2^32 -1)\n", INT_MAX);
    printf("INT_MIN is %d  (- 2^31)\n\n", INT_MIN);
    int x, y;

    x = 2147483640, y = 7;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 边界值

    x = 2147483640, y = 8;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 正溢出

    x = -2147483640, y = -8;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 边界值

    x = -2147483640, y = -9;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 负溢出

    x = -2147483648, y = -2147483648;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 溢出结果恰好为0

    x = -2147483648, y = -2147483647;
    printf("the result of %d and %d is %d\n\n", x, y, tadd_ok(x, y)); // 溢出结果为1
}