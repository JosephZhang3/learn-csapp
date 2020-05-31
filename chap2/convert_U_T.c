#include <stdio.h>

int main() {
    int tx = -8;
    int ty;
    int tyPlus;

    unsigned ux;
    unsigned um = 2147483647;// 边界值，比它大的无符号整数在转换成有符号整数后，就会变负数
    unsigned ui = 2147483648;
    unsigned uy = 2200000000;
    unsigned uyPlus = 2500000000;//试验是否递增

    ux = (unsigned) tx;// 有符号 -> 无符号
    ty = (int) uy;// 无符号 -> 有符号
    tyPlus = (int) uyPlus;

    printf("%u\n", ux);// 套用书上公式，当 -8 < 0 ，计算 -8 + 2^32 得到4294967288
    printf("%d\n", um);// output 2147483647
    printf("%d\n", ui);// output -2147483648 突变负数(刚好越过边界值)
    printf("%d\n", ty);// 套用书上公式，当 2200000000 > 2^31 -1 ，计算 2200000000 -2^32 得到 -2094967296
    printf("%d\n", tyPlus);// -1794967296 证明是递增的

    int x = -1;
    unsigned u = 2147483648;// it just is 2^31

    printf("x = %d = %u\n", x, x);
    printf("u = %d = %u\n", u, u);
}