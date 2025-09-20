#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int buffer[SIZE];
int head, tail;

void init() {
    head = 0;
    tail = 0;
}

int insert(int x) {
    int next = (head + 1) % SIZE;
    if (next == tail) 
        return 0;   // buffer full
    buffer[head] = x;
    head = next;
    return 1;
}

int delete(int *x) {
    if (head == tail) 
        return 0;   // buffer empty
    *x = buffer[tail];
    tail = (tail + 1) % SIZE;
    return 1;
}

int main() {
    int val,j=0;
    init();
    while (j<=60)
    {
        printf("\nInserting:\n");
        for (int i = 0; i < 20; i++) {
            val = rand() % 10;
            if (insert(val))
                printf("|%d|", val);
            else
                printf("\n[Buffer Full at %d]\n", val);
        }

        printf("\n\nDeleting:\n");
        while (delete(&val)) {
            printf("%d ", val);
        }
        j++;
    }

    return 0;
}
