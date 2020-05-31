#include "stdio.h"
#include "stdlib.h"

int main() {
    // 2^32 是42亿 10位十进制数，那么可以推断 2^64 是20位十进制数
    printf("%lli\n", INT64_MAX);
    printf("%llu\n", UINT64_MAX);// 18446744073709551615 unsigned long long 64bit


}