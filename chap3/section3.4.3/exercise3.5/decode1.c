#include<stdio.h>

int main(){
    
}

void decode1(int *xp,int *yp,int *zp){
    int x = (int)*xp;
    int y = (int)*yp;
    int z = (int)*zp;

    *yp = x;
    *zp = y;
    *xp = z;
}

/*
decode1:
         pushl   %ebp
         movl    %esp, %ebp
         subl    $12, %esp
         movl    %ebx, (%esp)
         movl    %esi, 4(%esp)
         movl    %edi, 8(%esp)

         movl    8(%ebp), %edi
         movl    12(%ebp), %edx
         movl    16(%ebp), %ecx
         movl    (%edx), %ebx
         movl    (%ecx), %esi
         movl    (%edi), %eax
         movl    %eax, (%edx)
         movl    %ebx, (%ecx)
         movl    %esi, (%edi)

         movl    (%esp), %ebx
         movl    4(%esp), %esi
         movl    8(%esp), %edi
         movl    %ebp, %esp
         popl    %ebp
         ret

第26到34行的汇编代码，对应第8到14行的C语言代码
代码的目的很简单，就是将*xp指针指向的内存地址变为*yp指向的内存地址，将*yp指针指向的内存地址变为*zp指向的内存地址，将*zp指针指向的内存地址变为*xp指向的内存地址。
也就是说，将3个指针的内容循环交换。
*/
