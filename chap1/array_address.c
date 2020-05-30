#include<stdio.h>

int main(){
    int arr[] = {1,2,3};
    
    int j;
    for(j=0;j<sizeof(arr)/sizeof(int);j++){
    //for(j=0;j<3;j++){    
        printf("arr[%d] = %d\n",j,arr[j]);

        printf("arr[%d] memory address is %p\n",j,&arr[j]);
    }
}
