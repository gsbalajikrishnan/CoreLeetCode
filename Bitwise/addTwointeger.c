#include<stdio.h>
int addTwointeger(int num1,int num2) {
    int sum, carry;
    while (num2!=0)
    {
        carry = num1 & num2;
        sum = num1 ^ num2;
        num1 = sum;
        num2 = carry<<1;    
    }
    return num1;
}
int main() {
    int num1=10,num2=3;
    int value;
    value = addTwointeger(num1,num2);
    printf("%d",value);
    return 0;
}