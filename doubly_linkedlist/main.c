#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

DoublyLinkedList *list_create() {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    if (!list) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_append(DoublyLinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));

    if (!node) {
        return;
    }

    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    } 
    list->size++;
}

void list_print(const DoublyLinkedList *list) {
    Node *curr = list->head;
    
    while (curr) {
        printf("[%d] <-> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void list_reverse_print(const DoublyLinkedList *list) {
    Node* curr = list->tail;

    while (curr) {
        printf("[%d] <-> ", curr->value);
        curr = curr->prev;
    }
    printf("NULL\n");
}

// Destructor
void list_free(DoublyLinkedList *list) {
    Node *curr = list->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}


int main() {
    DoublyLinkedList *list = list_create();

    list_append(list, 10);
    list_append(list, 32);
    list_append(list, 1);

    list_print(list);
    list_reverse_print(list);

    list_free(list);

    return 0;
}
