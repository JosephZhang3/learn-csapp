#include<stdio.h>
#include "show_bytes.c"

int main(){
    short sx = -12345;
    unsigned uy = sx;

    printf("uy = %u\n",uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned));
}
