#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
    /* data */
} Node;

Node *create_new_node(int new_data) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node==NULL) {
        return NULL;
    }
    else {
        new_node->data = new_data;
        new_node->link = NULL;
    }
    return new_node;
}
void append(int data, Node **head) {
    Node *temp=NULL;
    Node *new_node = create_new_node(data);
    if(*head==NULL) {
        *head = new_node;
    }
    else {
        temp = *head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
            /* code */
        }
        temp->link = new_node;
    }
}
void add_at_begin(int data, Node **head) {
    Node *new_node = create_new_node(data);
    new_node->link = *head;
    *head = new_node;
}
void add_at_pos(int data, Node **head, int pos) {
    int i=0;
    Node *current = NULL, *new_node = create_new_node(data);

    if(pos==0) {
        add_at_begin(data,head);
    }
    else {
        current = *head;
        for(i=1;i<pos-1 && current!=NULL;i++) {
            current = current->link;
        }
        new_node->link = current->link;
        current->link = new_node;
    }
}
Node* reverse_nodes(Node **head) {

    Node *prev=NULL, *next=NULL, *current=NULL;

    current = *head;
    while (current!=NULL)
    {
        next =  current->link;
        current->link = prev;
        prev = current;
        current = next;
        /* code */
    }
    return prev;
}
void delete_node_at_begin(Node **head) {
    Node *current = NULL;
    current = *head;
    *head = current->link;
}
void delete_node_at_end(Node **head) {
    Node *current = NULL,*prev=NULL;
    current = *head;
    while (current->link!=NULL)
    {
        prev = current;
        current = current->link;
        /* code */
    }
    prev->link = NULL;
}
void delete_node_at_pos(Node **head, int pos) {
    Node *current = NULL,*prev=NULL;
    int i=0;
    if((pos-1)==0) {
        delete_node_at_begin(head);
    }
    else {
        current = *head;
        
        for(i=0;i<pos-1&&current!=NULL;i++) {
            prev=current;
            current = current->link;
        }
        prev->link = current->link;
    }
}
void print_list(Node **head) {
    Node *current = NULL;
    current = *head;
    while (current!=NULL)
    {
        printf("|Address:%p:%d|\n",current->link, current->data);
        current = current->link;
        /* code */
    }
}
int main() {
    Node *head = NULL, *current=NULL;
    printf("Append the nodes\n");
    append(10, &head);
    append(20, &head);
    append(30, &head);
    append(40, &head);
    append(50, &head);
    append(60, &head);
    printf("Print the list\n");
    print_list(&head);
    add_at_begin(5, &head);
    printf("Print the list after adding node at begin\n");
    print_list(&head);
    // head = reverse_nodes(&head);
    add_at_pos(90, &head, 3);
    printf("Print the list after adding specific node\n");
    print_list(&head);
    // delete_node_at_end(&head);
    // printf("Print the after delete\n");
    //print_list(&head);
    printf("Print the list after deleting last node\n");
    delete_node_at_end(&head);
    print_list(&head);
    delete_node_at_begin(&head);
    printf("Print the list after deleting first node\n");
    print_list(&head);
    delete_node_at_pos(&head,2);
    printf("Print the list after deleting specific node\n");
    print_list(&head);
    add_at_pos(20,&head,2);
    printf("Print the list after adding specific node\n");
    print_list(&head);
    return 0;
}