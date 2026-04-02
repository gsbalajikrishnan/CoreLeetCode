#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *top;
//Node *top;

// typedef struct 
// {
//     Node *top;
//     /* data */
// }Stack;

// Stack *stack;

// Node *create_node(int data);
void initialize();
void push(int data);
void pop();
// void peek();
//int check_empty();

int main() {
    initialize();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    // peek();
    pop();
    pop();
    pop();
}
void initialize() {
    top = NULL;
}

void push(int data) {
    struct Node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Node is NULL");
        return;
    }
    new_node->data = data;
    new_node->link = top;
    top = new_node;
}
void pop() {
    struct Node *temp;
    if(top==NULL) {
        printf("Stack is empty");
        return;
    }
    temp = top;
    printf("Read data:%d",temp->data);
    top = temp->link;
    free(temp);
}
void peek() {
    if(top!=NULL) {
        printf("Peek value:%d",top->data);
    }
}