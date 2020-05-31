//
// Created by mac on 2020/5/31.
//

#include "stdio.h"
#include "string.h"

int main(){
    int l1 = strlen("abc");
    int l2 = strlen("abcdef");
    printf("%d\n",l1 > l2);// 0 false
}