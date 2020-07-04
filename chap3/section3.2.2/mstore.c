
long mult2(long, long);

void multstore(long x, long y, long *dest){
    long t = mult2(x, y);
	*dest = t;// put the value t into the memory of address *dest referenced
}

