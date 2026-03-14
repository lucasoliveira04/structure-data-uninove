#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int main() {
    int size;

    printf("Informe um tamanho do vetor: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    int *points = (int *)malloc(size * sizeof(int));

    if (points == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    // Preencher o vetor
    for (int i = 0; i < size; i++) {
        points[i] = i * 10;
    }

    // Exibir os valores
    for (int i = 0; i < size; i++) {
        printf("points[%d] = %d\n", i, points[i]);
    }

    free(points);
    return 0;
}