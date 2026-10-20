#include<stdio.h>
int main() {
    int num=12321,rev=0,rem=0;
    int value = num;
    while(num!=0) {
        rem = num%10;
        rev = rev*10+rem;
        num/=10;
    }
    if(rev==value) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
}