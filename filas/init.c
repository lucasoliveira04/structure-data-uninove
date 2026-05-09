#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_QUEUE 100

typedef struct {
    int data[MAX_SIZE_QUEUE];
    int head;
    int tail;
} Queue;

void startQueue(Queue *queue) {
    queue->head = -1;
    queue->tail = -1;
}

int isEmpty(Queue *queue) {
    return queue->head == -1;
}

int isFull(Queue *queue) {
    return queue->tail == MAX_SIZE_QUEUE - 1;
}

void queueUp(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->head = 0;
    }

    queue->tail++;
    queue->data[queue->tail] = value;
}


int getFirstElement(Queue *queue) {
  return queue->data[queue->head];
}

int getLastElement(Queue *queue) {
  return queue->data[queue->tail];
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (int i = queue->head; i <= queue->tail; i++) {
        printf("%d ", queue->data[i]);
    }

    printf("\n");
}

int main() {
    Queue queue;

    startQueue(&queue);

    int filaNums[] = {10, 3, 4, 5, 6, 7, 8, 9, 10, 21, 23, 12, 30};

    int tamanho = sizeof(filaNums) / sizeof(filaNums[0]);

    for (int i = 0; i < tamanho; i++) {
        queueUp(&queue, filaNums[i]);
    }

    printQueue(&queue);
    
    printf("%d", getFirstElement(&queue));
    printf("\n%d", getLastElement(&queue));

    return 0;
}
