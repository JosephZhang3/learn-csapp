/**
 * 练习题2.26 solution
 * A.当字符串s比字符串t的长度短时，会产生不正确的结果
 * B.
 *   在 macos 64位机器上的结果是 2^64 - x ，其中x为两个字符串相差的位数
     因为darwin内核中对size_t的定义是 unsigned long，即8个字节64bit，具体定义如下：

     typedef unsigned long           __darwin_size_t;

     做减法时，当计算结果为负数时，转换成 unsigned long 就会非常巨大。（有符号数转无符号数的特性，bit模式不变，只是对bit的解释方式改变）
   C.修改方案：用关系运算，而不要用算术运算
 */

#include "stdio.h"
#include <string.h>

/**
 * 比较字符串s和字符串t的长度
 * @param s length of s
 * @param t length of t
 * @return the result of comparison
 */
int str_longer(char *s, char *t) {
    printf("length of s is %lu\n", strlen(s));
    printf("length of t is %lu\n", strlen(t));
    printf("两个 unsigned long 相减的结果 %lu\n", strlen(s) - strlen(t));

    //超复杂的代码，不要这么整
//    unsigned long lenOfS = strlen(s);
//    unsigned long lenOfT = strlen(t);
//    int r = 0;
//    if (lenOfS > lenOfT)
//        r = (int) (lenOfS - lenOfT);
//    if (lenOfS < lenOfT)
//        r = -(int) (lenOfT - lenOfS);
//    printf("长度比较结果是%d\n", r);

    //一行代码搞定，so easy
    return strlen(s) > strlen(t);
}

int main() {
    char *s = "abc的";//一个汉字占3个字节 unicode 编码
    char *t = "abc";

    printf("finally %d\n", str_longer(s, t));
}