
/*
Digits (0–9): Values 48 to 57 ('0' = 48, '9' = 57). 
 */

#include <stdio.h>
int main()
{
    char num1 = '0';
    char num2 = '1';
    char sum = num1+num2;
    printf("%d\n",sum);
    /*
    Why subtract '0'?
    Because we want to convert the character '0' into the integer 0, and the character '1' into the integer 1. 
    */
    int bit1 = num1-'0';
    int bit2 = num2-'0';
    
    sum = bit1 + bit2;
    printf("%d\n",sum);
    int result = sum%2;
    int carry = sum/2;
    printf("Sum=%d\n",result);
    printf("Carry=%d\n",carry);

    /*
    Remember: sum % 2 gives the bit to write, and sum / 2 gives the carry for adding two binary digits. 
    */
    
    return 0;
}