#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Equivalent 'record' of Java/TS
typedef struct {
    char name[100];
    int age;
    float height;
} Person;

// This method is equals a 'constructor'
Person *person_create(const char *name, int age, float height) {
    Person *p = malloc(sizeof(Person));
    if (!p) {
        return NULL;
    }

    strncpy(
        p->name,
        name,
        sizeof(p->name) - 1
    );

    p->name[sizeof(p->name) - 1] = '\0';
    p->age = age;
    p->height = height;

    return p;
}

// Free memory that it was allocated with malloc, thus avoiding memory leak
void person_free(Person *p) {
    free(p);
}

void person_print(const Person *p) {
    printf("Name:   %s\n", p->name);
    printf("Age:    %d\n", p->age);
    printf("Height: %.2fm\n", p->height);
}

int main() {
    Person *p = person_create("Lucas", 21, 1.85f);
    if (!p) {
        return 1;
    }

    person_print(p);

    person_free(p);

    return 9;
}