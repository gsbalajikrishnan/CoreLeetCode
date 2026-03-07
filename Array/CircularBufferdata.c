#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct
{
    int data_buffer[SIZE];
    int head;
    int tail;
    /* data */
}CirBufdata;

void circular_buff_init(CirBufdata *cb) {
    cb->head = 0;
    cb->tail = 0;
}
int write_data(CirBufdata *cb, int data) {
    int next = ((cb->head+1)%SIZE);
    if(next == cb->tail){
        return 0;
    }
    cb->data_buffer[cb->head] = data;
    cb->head = next;
    return 1;
}

int read_data(CirBufdata *cb, int *data_read) {
    if(cb->tail==cb->head) {
        return 0;
    }
    *data_read = cb->data_buffer[cb->tail];
    cb->tail = ((cb->tail+1)%SIZE);
    return 1;
}
int main() {
    CirBufdata cb;
    int sensor_data;
    int data_write;
    circular_buff_init(&cb);
    int j=0;
    while (j<=20)
    {   
        for(int i=0;i<SIZE;i++) {
            data_write = rand()%10;
            if(write_data(&cb, data_write)) {
                printf("Data:%d ",data_write);
            }
        }
        printf("\n");
        while (read_data(&cb, &sensor_data))
        {
            printf("Read:%d ",sensor_data);
            /* code */
        }
        j++;
        /* code */
    }
    return 0;
}