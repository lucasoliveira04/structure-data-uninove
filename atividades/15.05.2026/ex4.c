#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_QUEUE 100
#define MAX_SIZE_NAME 80

typedef struct {
    char nome[MAX_SIZE_NAME];
    int idade;
} Pessoa;

typedef struct {
    Pessoa data[MAX_SIZE_QUEUE];
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

void insertQueue(Queue *queue, Pessoa pessoa) {

    if (isFull(queue)) {
        printf("Fila cheia\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->head = 0;
    }

    /*
        Se a pessoa for prioritária (idade > 65),
        ela entra na frente da fila.
    */

    if (pessoa.idade > 65) {

        /*
            Move todos os elementos uma posição
            para a direita.
        */

        for (int i = queue->tail; i >= queue->head; i--) {
            queue->data[i + 1] = queue->data[i];
        }

        queue->data[queue->head] = pessoa;
        queue->tail++;

    } else {

        queue->tail++;
        queue->data[queue->tail] = pessoa;
    }
}

Pessoa removeQueue(Queue *queue) {

    Pessoa pessoaVazia = {"", 0};

    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return pessoaVazia;
    }

    Pessoa pessoaRemovida = queue->data[queue->head];

    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    } else {
        queue->head++;
    }

    return pessoaRemovida;
}

void printQueue(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return;
    }

    printf("===== FILA PRIORITARIA =====\n\n");

    for (int i = queue->head; i <= queue->tail; i++) {

        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", queue->data[i].nome);
        printf("Idade: %d\n", queue->data[i].idade);

        if (queue->data[i].idade > 65) {
            printf("Atendimento: Prioritario\n");
        } else {
            printf("Atendimento: Normal\n");
        }

        printf("\n");
    }
}

int main() {

    Queue queue;

    startQueue(&queue);

    Pessoa p1 = {"Lucas", 22};
    Pessoa p2 = {"Ana", 30};
    Pessoa p3 = {"Carlos", 40};
    Pessoa p4 = {"Maria", 28};

    /*
        Essa pessoa entra por último,
        mas será movida para a frente
        por possuir prioridade.
    */

    Pessoa p5 = {"Joao", 70};

    insertQueue(&queue, p1);
    insertQueue(&queue, p2);
    insertQueue(&queue, p3);
    insertQueue(&queue, p4);
    insertQueue(&queue, p5);

    printQueue(&queue);

    printf("===== ATENDIMENTO =====\n\n");

    while (!isEmpty(&queue)) {

        Pessoa pessoa = removeQueue(&queue);

        printf("Atendendo: %s (%d anos)\n",
               pessoa.nome,
               pessoa.idade);
    }

    return 0;
}