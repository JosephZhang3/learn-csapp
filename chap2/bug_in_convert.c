#include <stdio.h>

/**
* 练习题2.25 solution
*/
float sum_elem(float a[],unsigned length){
    int i = 0;
    float result = 0;

    printf("%u\n", length);// 输出 0
    printf("%u\n", length -1);// 输出 4294967295 ，分析： (unsigned)0 + (signed int)-1 => 需要先把有符号整型值 -1 转换成无符号型，
    //转换后的结果是 (unsigned)2^32 -1 即 4294967295，加上 (unsigned)0，结果仍然是 4294967295

    for(; i <= length-1; i++) 
        result += a[i];// a[4] a[5] ... a[4294967295 -1] 全都是不存在的，必然运行时报错
    return result;
}

int main(){
    float fi[] = {3.14,9.99,3234.12,88};
    printf("%f\n", sum_elem(fi, 0));
}