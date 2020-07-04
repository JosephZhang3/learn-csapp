#include <stdio.h>

void multstore(long, long, long *);

int main(){
    long d;
	multstore(2, 4, &d);// transfer the address of d
	printf("2 * 3 --> %ld\n", d);
	return 0;
}

long mult2(long a, long b){
     long s = a *b;
	 return s;
}
