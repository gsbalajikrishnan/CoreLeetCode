#include<stdio.h>
void rightShiftArray(int arr[],int size);
int main()
{
    int arr[]={10,50,20,35,89,90,33,88};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i,rightShift=3;
    for(i=0;i<rightShift;i++)
    {
        rightShiftArray(arr,size);
    }
    for (i = 0; i <size; i++)
    {
        printf("%d ",arr[i]); /* code */
    }
    
    return 0;
}
void rightShiftArray(int arr[],int size)
{
    int i;
    int temp=arr[size-1];
    for(i=size-1;i>=0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0] = temp;
}