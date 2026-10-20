#include<stdio.h>
int main() {
    int num=153,original,rem,result=0;
    original=num;
    while(num!=0) {
        rem=num%10;
        result+=rem*rem*rem;
        num/=10;
    }
    if(result==original) {
        printf("The number is an Armstrong number.\n");
    } else {
        printf("The number is not an Armstrong number.\n");
    }
}