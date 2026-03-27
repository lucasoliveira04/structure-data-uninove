#include <stdio.h>
#include <stdlib.h>

int main() {
    // Matriz with N dimensions
    int matriz[2][2] = {
        {1, 3},
        {2, 5}
    };


    // Length matriz in bytes
    size_t tamanhoMatriz = sizeof(matriz);

    // All numbers that have on matriz
    size_t quantidadeDeElementos = sizeof(matriz) / sizeof(matriz[0][0]);

    // Number rows and columns
    size_t quantidadeLinhas = sizeof(matriz) / sizeof(matriz[0]);
    size_t quantidadeColunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    // Declaring rows and columns of dynamic form
    int rows = 10;
    int columns = 10;

    int **matrizDynamic = (int **) malloc(rows * sizeof(int *));

    // O(n)
    for (int i = 0; i < rows; i++) {
        matrizDynamic[i] = (int *) calloc(columns, sizeof(int)); // calloc jsut init memory with 0 different of malloc that init memory withput nothing
    }

    // O(n*2)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrizDynamic[i][j]);
        }
        printf("\n");
    }

    // Matriz make all with 0
    int matrizAllZeros[2][5] = {0};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            printf("%d\t", matrizAllZeros[i][j]);
        }
        printf("\n");
    }

    // O(n*2)
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            if (matriz[i][j] == 5) {
                printf("Valor retornado: %d", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}