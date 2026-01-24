#include<stdio.h>
int main() {
    int value = 1576892;
    int rem;
    int num1,num2,num3;
    num1=num2=num3=-1;
    while (value!=0)
    {
        rem = value%10;
        if(rem>num1) {
            num3 = num2;
            num2= num1;
            num1 = rem;
        }
        else if (rem>num2 && num1>rem)
        {
            num3 = num2;
            num2 = rem;
            /* code */
        }
        else if(rem>num3 &&  num2>rem)
        {
            num3 = rem;
        }
        
        value = value / 10;
        /* code */
    }
    printf("%d\n",num1);
    printf("%d\n",num2);
    printf("%d",num3);
    return 0;    
}