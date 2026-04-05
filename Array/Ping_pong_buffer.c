#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int bufferA[MAX_SIZE];
int bufferB[MAX_SIZE];

int *buf_array[2];
int current = 0;  // 0 -> Buffer A, 1-> Buffer B
int write_index=0;
int data_ready=0;

void buffer_initialize() {
    buf_array[0] = bufferA;
    buf_array[1] = bufferB;
}
void data_producer(int data) {
    int *write_active = buf_array[current];
    write_active[write_index++] = data;
    if(write_index==MAX_SIZE) {
        write_index = 0;
        data_ready = 1;
        current = current^1;
    }
}

void process_data(int *buffer) {
    int i;
    for(i=0;i<MAX_SIZE;i++) {
        printf("%d ",buffer[i]);
    }
}
void consume() {
        int *read_inactive = buf_array[current^1];
        process_data(read_inactive);
        data_ready=0;
}
int main() {
    
    int i=0;
    buffer_initialize();
    while (i<10)
    {
        int data = rand()%10;
        data_producer(data);
        if(data_ready) {
            consume();
        }
        i++;
        /* code */
    }   
}