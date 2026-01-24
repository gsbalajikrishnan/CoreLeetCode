#include<stdio.h>
int main() {
    int arr[] = {10,25,33,56,89,20};
    int max1,max2,max3,i;
    int size;
    size = sizeof(arr)/sizeof(arr[0]);
    max1=max2=max3=-1;
    for(i=0;i<size;i++) {
        if(arr[i]>max1) {
            max3 = max2;
            max2 =  max1;
            max1 = arr[i];
        }
        else if (arr[i]>max2 && max1>arr[i])
        {
            max3 = max2;
            max2 = arr[i];
            /* code */
        }
        else if (arr[i]>max3 && max2>arr[i])
        {
            max3 = arr[i];
            /* code */
        }
    }
    printf("%d %d %d", max1,max2,max3);
    return 0;
}