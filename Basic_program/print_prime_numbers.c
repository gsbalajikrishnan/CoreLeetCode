#include<stdio.h>
int main() {
    int num, i, count;
    for(num=2;num<=100;num++) {
        count=0;
        for(i=1;i<=num;i++) {
            if(num%i==0) {
                count++;
            }
        }
        if(count==2) {
            printf("%d is a prime number.\n", num);
        }
    }
    return 0;
}