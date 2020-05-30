#include<stdio.h>

int main(){
    printf("calculation result is %d\n",arith(7,8,9));
}

int arith(int x,int y,int z){
    int v1 = x+y;
    int v2 = z*48;
    int v3 = v1 & 0xFFFF;
    int v4 = v2 * v3;
    return v4;
}
