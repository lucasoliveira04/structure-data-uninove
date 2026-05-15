#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE_QUEUE 100
#define MAX_SIZE_NAME 80

typedef struct {
    char nome[MAX_SIZE_NAME];
    int tempoAtendimento;
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

    queue->tail++;

    queue->data[queue->tail] = pessoa;
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

    printf("===== FILA DO BANCO =====\n\n");

    for (int i = queue->head; i <= queue->tail; i++) {

        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", queue->data[i].nome);
        printf("Tempo de atendimento: %d minutos\n",
               queue->data[i].tempoAtendimento);

        printf("\n");
    }
}

int main() {

    srand(time(NULL));

    Queue queue;

    startQueue(&queue);

    Pessoa p1 = {"Lucas", rand() % 15 + 1};
    Pessoa p2 = {"Ana", rand() % 15 + 1};
    Pessoa p3 = {"Carlos", rand() % 15 + 1};
    Pessoa p4 = {"Maria", rand() % 15 + 1};
    Pessoa p5 = {"Joao", rand() % 15 + 1};

    insertQueue(&queue, p1);
    insertQueue(&queue, p2);
    insertQueue(&queue, p3);
    insertQueue(&queue, p4);
    insertQueue(&queue, p5);

    printQueue(&queue);

    int somaTempo = 0;
    int totalPessoas = 0;

    printf("===== ATENDIMENTOS =====\n\n");

    while (!isEmpty(&queue)) {

        Pessoa pessoa = removeQueue(&queue);

        printf("%s foi atendido em %d minutos\n",
               pessoa.nome,
               pessoa.tempoAtendimento);

        somaTempo += pessoa.tempoAtendimento;
        totalPessoas++;
    }

    float media = (float) somaTempo / totalPessoas;

    printf("\n===== RESULTADO =====\n\n");

    printf("Tempo medio de atendimento: %.2f minutos\n", media);

    if (media > 8) {
        printf("Recomenda-se a abertura de um novo caixa.\n");
    } else {
        printf("Nao e necessario abrir um novo caixa.\n");
    }

    return 0;
}