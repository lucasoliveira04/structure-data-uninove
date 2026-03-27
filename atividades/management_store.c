#include <stdio.h>
#include <stdlib.h>

int main() {
    int estoque[2][12] = {
        {10, 20, 15, 30, 25, 18, 22, 14, 19, 27, 31, 16},  // categoria 0
        {5,  12, 8,  20, 17, 9,  14, 11, 6,  23, 18, 10}   // categoria 1
    };

    int total = 0;

    for (int i = 0; i < 2; i++) {
        int soma_categoria = 0;

        printf("Categoria %d: ", i);

        for (int j = 0; j < 12; j++) {
            printf("%d\t", estoque[i][j]);
            soma_categoria += estoque[i][j];
        }

        total += soma_categoria;
        printf("\nSoma categoria %d: %d\n\n", i, soma_categoria);
    }

    printf("Total geral: %d\n", total);

    return 0;
}