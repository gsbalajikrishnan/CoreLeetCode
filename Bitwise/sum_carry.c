#include<stdio.h>
int main() {

    int a=10,b=20;
    int sum, carry;
    while (b!=0)
    {
        sum = a^b;
        carry = a&b;
        b = carry<<1;
        a = sum;
        /* code */
    }
    printf("%d",a);
    return 0;

}