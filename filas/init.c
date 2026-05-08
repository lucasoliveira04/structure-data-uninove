#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int head;
  int tail;
} Fila;


void iniciarFila(Fila *q){
  q->head = -1;
  q->tail = -1;
}

int isEmpty(Fila *q) {
  
  if (q->head != NULL) return 0;
  
  return -1;
}

int isFull(Fila *1) {
  if (q->tail == MAX_SIZE - 1) return 1;
  return 0;
}

void enfileirar(Fila *q, int value) {
  if (isFull(q)) {
    printf("Queue is full"); 
    return;
  } 
  if (isEmpty(q)) q->head = 0;
  
  q->tail = (q->tail + 1) % MAX_SIZE; // Define limite of Queue
  q->data[q->tail] = value;
}

int desenfileirar(Fila *q) {
  if (isEmpty(q)) {
    printf("Queue is empty");
    return -1;
  }
  
  int value = q->data[q->head];
  if (q->head == q->tail) {
    q->head = -1;
    q->tail = -1;
  } else {
    q->head = (q->head + 1) % MAX_SIZE;
  }
}