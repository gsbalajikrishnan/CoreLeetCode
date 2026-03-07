#include<stdio.h>
void leftShiftArray(int arr[],int size);
void rightShiftArray(int arr[],int size);
int main()
{
    int arr[]={10,50,20,35,89,90,33,88};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i,Shift=3;
    for(i=0;i<Shift;i++)
    {
        leftShiftArray(arr,size);
        //rightShiftArray(arr,size);
    }
<<<<<<< HEAD
    for (i = 0; i<size; i++)
    {
        printf("%d ",arr[i]); /* code */
    }
    
    printf("\n");
    for(i=0;i<Shift;i++)
    {
        //leftShiftArray(arr,size);
        rightShiftArray(arr,size);
    }
    for (i = 0; i<size; i++)
=======
<<<<<<< Updated upstream
    for (i = 0; i <size; i++)
>>>>>>> feature/leetCode_C_Array
    {
        printf("%d ",arr[i]); /* code */
    }
=======
    for (i = 0; i<size; i++)
    {
        printf("%d ",arr[i]); /* code */
    }
    
    // printf("\n");
    // for(i=0;i<Shift;i++)
    // {
    //     //leftShiftArray(arr,size);
    //     rightShiftArray(arr,size);
    // }
    // for (i = 0; i<size; i++)
    // {
    //     printf("%d ",arr[i]); /* code */
    // }
>>>>>>> Stashed changes
    
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
<<<<<<< HEAD
=======
<<<<<<< Updated upstream
}
=======
>>>>>>> feature/leetCode_C_Array
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
<<<<<<< HEAD
}
=======
}
>>>>>>> Stashed changes
>>>>>>> feature/leetCode_C_Array
