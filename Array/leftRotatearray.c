#include<stdio.h>
void leftShiftArray(int arr[],int size);
int main()
{
    int arr[]={10,50,20,35,89,90,33,88};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i,rightShift,leftShift=3;
    //rightShift = size - leftShift;
    for(i=0;i<leftShift;i++)
    {
        leftShiftArray(arr,size);
    }
    for (i = 0; i <size; i++)
    {
        printf("%d ",arr[i]); /* code */
    }
    
    return 0;
}
void leftShiftArray(int arr[],int size)
{
    int i;
    int temp=arr[0];
    for(i=0;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size-1] = temp;
}