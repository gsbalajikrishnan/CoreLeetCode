#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

typedef struct {
    int stack_buf[MAX_SIZE];
    int top;
}Stack;

void initialize_stack(Stack *stack);
int ifempty(Stack *stack);
int iffull(Stack *stack);
void push(Stack *stack,int data);
int pop(Stack *stack);

int main() {
    Stack stack;
    int send_data,read_data;
    initialize_stack(&stack);
    while (!iffull(&stack))
    {
        send_data = rand()%10;
        push(&stack,send_data);
        /* code */
    }
    while (!ifempty(&stack))
    {
        read_data = pop(&stack);
        printf("%d ",read_data);
        /* code */
    }
    return 0;
}
void initialize_stack(Stack *stack) {
    stack->top = -1;
}
int ifempty(Stack *stack) {
    return stack->top == -1;
}
int iffull(Stack *stack) {
    return stack->top == MAX_SIZE-1;
}
void push(Stack *stack,int data) {
    if(iffull(stack))
    {
        printf("Stack overflow");
        /* code */
    }
    stack->top++;
    stack->stack_buf[stack->top] =  data;
}
int pop(Stack *stack) {
    int data;
    if(ifempty(stack)) {
        printf("Stack is empty");
    }
    data = stack->stack_buf[stack->top];
    stack->top--;
    return data;
}