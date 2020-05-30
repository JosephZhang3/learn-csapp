#include<stdio.h>

int main(){
     
    printf("%u\n", -1);
    printf("%d\n", -1 < 0);
    printf("%d\n", -1 < 0u);

    printf("%u\n", -2147483647);
    printf("%d\n", 2147483647U > -2147483647 - 1);

    printf("%d\n", (int)2147483648U);
    printf("%d\n", 2147483647 > (int)2147483648U);

    printf("%d\n",-2147483648);// -2147483648 has type 'unsigned long int'
    printf("%d\n",-2147483647 - 1);;

    return 0;
}
