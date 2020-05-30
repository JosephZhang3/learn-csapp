#include<stdio.h>

int main(){
    printf("result is %d\n",shift_left2_rightn(8,3));
}

int shift_left2_rightn(int x,int n){
    x <<= 2;
    x >>= n;
    return x;
}
