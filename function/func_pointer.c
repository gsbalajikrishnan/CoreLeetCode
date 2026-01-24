#include<stdio.h>
int (*ptr)(int,int);
int add(int,int);
void call_back(int (*cb)(),int, int);
int main() {
call_back(add,5,10);
return 0;
}
int add(int a, int b) {
    return a*b;
}
void call_back(int (*cb)(), int a, int b) {
    ptr = cb;
    printf("%d",ptr(a,b));
}