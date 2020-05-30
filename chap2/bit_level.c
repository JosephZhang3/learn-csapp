#include<stdio.h>

void inplace_swap(int *x,int *y){
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[],int count){
    int first,last;
    /* We should not swap the middle element of the array that has odd length itself
       Because the method inplace_swap() is implemented by Exclusive-OR operation,
       if we swap an element with itself,it will change to zero at last.
       so we must use < instead of <= .
     */
    //for(first=0,last = count -1;first <= last;first++,last--){
    for(first=0,last = count -1;first < last;first++,last--){
        inplace_swap(&a[first],&a[last]);
    }
}

//exercise 2.11 at page 35
int main(){
    int x = 5;
    int y = 6;
    inplace_swap(&x,&y);
    printf("The swap-both result of 5 and 6 is x=%d and y=%d.\n",x,y);
     
    inplace_swap(&x,&x);
    printf("The swap-itself result is x=%d\n",x); 
   
    /* 
    int a[] = {1,2,3,4};
    reverse_array(a,4);
    printf("The reverse result of array {1,2,3,4} is [");
    int i;
    for(i=0;i<4;i++){
        if(i != 3){
            printf("%d,",a[i]);
        }else{
            printf("%d",a[i]);
        }
    }
    printf("]\n");
    */    


    int a[] = {1,2,3,4,5};
    reverse_array(a,5);
    printf("The reverse result of array {1,2,3,4,5} is [");
    int i;
    for(i=0;i<5;i++){
        if(i != 4){
            printf("%d,",a[i]);
        }else{
            printf("%d",a[i]);
        }
    }
    printf("]\n");

}
