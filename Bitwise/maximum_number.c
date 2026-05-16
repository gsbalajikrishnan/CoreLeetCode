#include<stdio.h>
int main() {
    int value = 123945;
    int data,max1=-1,max2=-1,max3=-1;
    while(value!=0) {
        data=value%10;
        if(data>max1){
            max3 = max2;
            max2 = max1;
            max1 = data;
        }
        else if(data>max2 && data<max1) {
            max3 = max2; 
            max2 = data;
        }
        else if(data>max3 && data<max2) {
            max3 = data;
        }
        value = value/10;
    }
    printf("%d %d %d",max1, max2, max3);
}