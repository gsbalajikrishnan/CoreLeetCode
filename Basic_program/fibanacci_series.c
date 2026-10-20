#include<stdio.h>
int main() {
int num1=0,num2=1,sum,i,n=10;
for(i=1;i<n;i++) {
    printf("%d ",num1);
    sum=num1+num2;
    num1=num2;
    num2=sum;
    }
return 0;
}