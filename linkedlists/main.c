#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList *list_create() {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) {
        return NULL;
    }

    list->head = NULL;
    list->size = 0;
    return list;
}

// Prepend 0(1)
void list_prepend(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        return;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void list_print(const LinkedList *list) {
    Node *curr = list->head;

    while (curr) {
        printf("[%d] -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void list_append(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));

    if (!node) {
        return;
    }

    node->value = value;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
    } else {
        Node *curr = list->head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }

    list->size++;
}

// Destructor
void list_free(LinkedList *list) {
    Node *curr = list->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}


int main() {
    LinkedList *list = list_create();

    list_prepend(list, 10);
    list_prepend(list, 23);
    list_prepend(list, 11);
    list_prepend(list, 1);

    list_print(list);

    list_append(list, 20);

    list_print(list);
}