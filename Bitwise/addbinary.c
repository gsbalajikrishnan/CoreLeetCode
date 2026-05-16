#include <stdio.h>

int main()
{
    char num1 = '0';
    char num2 = '1';
    char sum = num1+num2;
    printf("%d\n",sum);
    int bit1 = num1-'0';
    int bit2 = num2-'0';
    
    sum = bit1 + bit2;
    printf("%d\n",sum);
    int result = sum%2;
    int carry = sum/2;
    printf("Sum=%d\n",result);
    printf("Carry=%d\n",carry);
    
    return 0;
}