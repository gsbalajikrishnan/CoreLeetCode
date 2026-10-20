#include<stdio.h>
void func(int num);
int main() {
    int num=10,sum,i;
    func(num);
    //printf("%d ",num);
    return 0;
}
void func(int num) {
    int sum,num1=0,num2=1;
    if(num==0) {
        return;
    }
    sum = num1+num2;
    num1=num2;
    num2=sum;
    //printf("%d ",num);
    func(sum-1);
    printf("%d ",sum);
}