#include<stdio.h>
int main() {
    int num1=10,num2=20;
    int sum, carry;
    while (num2!=0)
    {
        sum = num1^num2;
        carry = num1 & num2;
        num1 = sum;
        num2 = carry<<1;
        /* code */
    }
    printf("%d",sum);
    return 0;
}