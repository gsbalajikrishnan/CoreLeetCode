#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front =-1,rear=-1;
void enqueue(int data) {
    if(front ==-1) {
        front = 0;
    }
    if (rear==SIZE-1) {
        printf("Buffer is overflow\n");
        return;
    }
    else {
        rear++;
        queue[rear]=data;
        printf("%d ",queue[rear]);
    }
}
void dequeue() {
    if(front==-1 || front>rear) {
        printf("Buffer is underflow");
        return;
    }
    front++;
    //printf();
    if(front>rear) {
        front=rear=-1;
    }
}
int main () {
    enqueue(10);
    enqueue(20);
    dequeue();
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    enqueue(60);
    return 0;
}