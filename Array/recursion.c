#include<stdio.h>
int recursion(int a) {
    if(a==1)
        return 1;
    else {
        return a * recursion(a-1);
    }
}
int main()
{
    int a=5;
    int value = recursion(a);
    printf("%d",value);
}