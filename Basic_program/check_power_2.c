#include<stdio.h>
int main() {
    int num=1;
    
    if(num>0 && (num & (num-1))==0) {
        printf("%d is a power of 2\n",num);
    }
    else {
        printf("%d is not a power of 2\n",num);
    }
    return 0;
}

/* 
    while(num%2==0) {
    num/=2;
    }
    if(num==1) {
        printf("%d is a power of 2\n",num);
    }
 */