#include<stdio.h>
void func(int num1, int num2, int num);
int main() {
    int num=10,sum,i;
    func(0,1,num);
    //printf("%d ",num);
    return 0;
}
void func(int num1, int num2, int num) {
    int sum;
    if(num==0) {
        return;
    }
    sum = num1+num2;
    printf("%d ",sum);
    func(num2,sum,num-1);
    //printf("%d ",sum);
}