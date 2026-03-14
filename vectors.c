#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

// Colocando dados no vetor de forma dinamica. 
int main() {
    int size;

    printf("Informe um tamanho do vetor: ");
    scanf("%d", &size);
    // alocando memoria para vetores de inteiros
    if (size > MAX_SIZE) return;

    int *points = (int *)malloc(size * sizeof(int));

    if (points == NULL) {
        printf("Erro ao alocar memoria, memoria NULL\n");
        return;
    }

    // preencher dados e exibir 
    // Libera memoria alocada para o vetor
    free(points);

    return 0;
}