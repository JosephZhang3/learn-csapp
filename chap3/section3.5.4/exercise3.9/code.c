#include<stdio.h>

int main(){
    
}

int arith(int x,int y,int z){
    int t1=y^x;
    int t2=t1>>3;
    int t3=~t2;//取补运算
    int t4=t3-z;
    return t4;
}
