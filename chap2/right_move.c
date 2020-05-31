#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("%x\n",fun1(20));
    printf("%x\n",fun1(0x00000076));
    printf("%x\n",fun1(0x87654321));
    printf("%x\n",fun1(0x000000c9));
    printf("%x\n",fun1(0xEDCBA987));

    printf("因为0x87654321左移24位（相当于16进制左移6位）后的值是0x21，右移之后"位扩展"会在左边加6个十六进制0，但是加的0不会打印出来\n");
    printf("因为0x000000c9左移24位后的值是0xc9是负数，右移之后"位扩展"会在左边加6个十六进制f，加的f会打印出来\n");

    printf("%x\n",fun2(20));
    printf("%x\n",fun2(0x00000076));
    printf("%x\n",fun2(0x87654321));
    printf("%x\n",fun2(0x000000c9));
    printf("%x\n",fun2(0xEDCBA987));
}

int fun1(unsigned x){
    printf("%x\n",x<<24);

    printf("%x\n",(x<<24)>>24);

    return (int)((x << 24) >> 24);         
}

int fun2(unsigned x){
    printf("%x\n",(int)x<<24);
    printf("%x\n",((int)x<<24)>>24);

    return ((int)x<<24)>>24;
}
