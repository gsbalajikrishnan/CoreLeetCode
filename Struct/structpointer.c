#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void updateStudent(struct Student* s) {
    s->id = 101;
    strcpy(s->name, "Balaji");
    s->marks = 95.5;
}

int main() {
    struct Student s1;  // Declare structure variable

    updateStudent(&s1);  // Pass pointer to structure (by reference)

    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
     