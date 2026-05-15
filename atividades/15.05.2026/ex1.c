#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_QUEUE 100
#define MAX_SIZE_NAME 80

typedef enum {
    RECLAMAR,
    ELOGIAR
} MotivoVisita;

typedef struct {
    char nome[MAX_SIZE_NAME];
    char cpf[20];
    char dataNascimento[20];
    MotivoVisita motivoVisita;
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

int isNameValid(Pessoa *pessoa) {
    return strlen(pessoa->nome) < MAX_SIZE_NAME;
}

void insertQueue(Queue *queue, Pessoa pessoa) {

    if (!isNameValid(&pessoa)) {
        printf("Nome invalido\n");
        return;
    }

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

    Pessoa pessoaVazia = {"", "", "", RECLAMAR};

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

char *motivoToString(MotivoVisita motivo) {

    switch (motivo) {
        case RECLAMAR:
            return "Reclamar";

        case ELOGIAR:
            return "Elogiar";

        default:
            return "Desconhecido";
    }
}

void printQueue(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return;
    }

    printf("===== FILA =====\n\n");

    for (int i = queue->head; i <= queue->tail; i++) {

        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", queue->data[i].nome);
        printf("CPF: %s\n", queue->data[i].cpf);
        printf("Data nascimento: %s\n", queue->data[i].dataNascimento);
        printf("Motivo visita: %s\n",
               motivoToString(queue->data[i].motivoVisita));

        printf("\n");
    }
}

int main() {

    Queue queue;

    startQueue(&queue);

    Pessoa p1 = {
        "Lucas",
        "123.456.789-00",
        "10/05/2004",
        RECLAMAR
    };

    Pessoa p2 = {
        "Ana",
        "987.654.321-00",
        "22/08/2000",
        ELOGIAR
    };

    Pessoa p3 = {
        "Carlos",
        "111.222.333-44",
        "15/01/1998",
        RECLAMAR
    };

    Pessoa p4 = {
        "Maria",
        "555.666.777-88",
        "03/11/1995",
        ELOGIAR
    };

    Pessoa p5 = {
        "Joao",
        "999.888.777-66",
        "27/09/1990",
        RECLAMAR
    };

    insertQueue(&queue, p1);
    insertQueue(&queue, p2);
    insertQueue(&queue, p3);
    insertQueue(&queue, p4);
    insertQueue(&queue, p5);

    printQueue(&queue);

    int totalReclamacoes = 0;
    int totalElogios = 0;

    while (!isEmpty(&queue)) {

        Pessoa pessoa = removeQueue(&queue);

        if (pessoa.motivoVisita == RECLAMAR) {
            totalReclamacoes++;
        } else {
            totalElogios++;
        }
    }

    printf("===== RESULTADO =====\n\n");

    if (totalElogios < totalReclamacoes) {
        printf("Na fila de hoje tivemos %d pessoas que vieram elogiar e %d pessoas que vieram reclamar.\n",
               totalElogios,
               totalReclamacoes);
    } else {
        printf("Na fila de hoje tivemos %d pessoas que vieram reclamar e %d pessoas que vieram elogiar.\n",
               totalReclamacoes,
               totalElogios);
    }

    return 0;
}