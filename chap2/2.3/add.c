#include "stdio.h"
#include "stdlib.h"

int u_add_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    if (sum < x) {
        printf("overflow happened\n");
        printf("result after overflow is %u\n", sum);
        return 0;
    }
    printf("overflow not exist\n");
    return 1;
}

int main() {
    // 2^32 是42亿 10位十进制数，那么可以推断 2^64 是20位十进制数
    printf("%lli\n", INT64_MAX);
    printf("%llu\n", UINT64_MAX);// 18446744073709551615 unsigned long long 64bit

    printf("judging result is %d\n", u_add_ok(4294967295, 0));//边界值，刚好没有溢出
    printf("judging result is %d\n", u_add_ok(4294967295, 1));//溢出了。溢出后的计算结果是 4294967295 + 1 - 2^32 = 0
}