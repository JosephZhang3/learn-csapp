#include<stdio.h>

int main(){
    int x = 53191;
    short sx = (short)x;// 强制转换为 short int
    int y = sx;

    printf("%d\n",sx);
    printf("%d\n",y);
    
    printf("%x\n",sx);
    printf("%x\n",y);
}