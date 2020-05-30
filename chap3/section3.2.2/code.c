#include<stdio.h>

int accnum = 0;

int sum(int x,int y){
    int t = x +y;
    accnum += t;
    return t;
}
