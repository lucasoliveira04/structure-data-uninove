#include <stdio.h>

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

    // Primeiro elemento
    if (isEmpty(queue)) {
        queue->head = 0;
    }

    queue->tail++;
    queue->data[queue->tail] = value;
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

    queueUp(&queue, 10);
    queueUp(&queue, 20);
    queueUp(&queue, 30);

    printQueue(&queue);

    return 0;
}
