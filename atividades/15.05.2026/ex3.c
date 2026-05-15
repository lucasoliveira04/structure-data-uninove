#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_QUEUE 100
#define MAX_SIZE_NAME 100

typedef struct {
    int codigoProcesso;
    char nomeArquivo[MAX_SIZE_NAME];
    int quantidadeBytes;
} Documento;

typedef struct {
    Documento data[MAX_SIZE_QUEUE];
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

void insertQueue(Queue *queue, Documento documento) {

    if (isFull(queue)) {
        printf("Fila cheia\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->head = 0;
    }

    queue->tail++;

    queue->data[queue->tail] = documento;
}

Documento removeQueue(Queue *queue) {

    Documento documentoVazio = {0, "", 0};

    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return documentoVazio;
    }

    Documento documentoRemovido = queue->data[queue->head];

    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    } else {
        queue->head++;
    }

    return documentoRemovido;
}

void printQueue(Queue *queue) {

    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return;
    }

    printf("===== FILA DE IMPRESSAO =====\n\n");

    for (int i = queue->head; i <= queue->tail; i++) {

        printf("Documento %d\n", i + 1);

        printf("Codigo do processo: %d\n",
               queue->data[i].codigoProcesso);

        printf("Nome do arquivo: %s\n",
               queue->data[i].nomeArquivo);

        printf("Quantidade em bytes: %d\n",
               queue->data[i].quantidadeBytes);

        printf("\n");
    }
}

int main() {

    Queue queue;

    startQueue(&queue);

    Documento d1 = {
        1001,
        "contrato.pdf",
        2048
    };

    Documento d2 = {
        1002,
        "relatorio.docx",
        4096
    };

    Documento d3 = {
        1003,
        "imagem.png",
        1024
    };

    Documento d4 = {
        1004,
        "planilha.xlsx",
        3072
    };

    Documento d5 = {
        1005,
        "curriculo.pdf",
        5120
    };

    insertQueue(&queue, d1);
    insertQueue(&queue, d2);
    insertQueue(&queue, d3);
    insertQueue(&queue, d4);
    insertQueue(&queue, d5);

    printQueue(&queue);

    printf("===== IMPRIMINDO DOCUMENTOS =====\n\n");

    while (!isEmpty(&queue)) {

        Documento documento = removeQueue(&queue);

        printf("Documento removido da fila\n");

        printf("Codigo do processo: %d\n",
               documento.codigoProcesso);

        printf("Nome do arquivo: %s\n",
               documento.nomeArquivo);

        printf("Quantidade em bytes: %d\n",
               documento.quantidadeBytes);

        printf("\n");
    }

    return 0;
}