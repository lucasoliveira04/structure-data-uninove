#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10];

    int length = sizeof(vetor) / sizeof(vetor[0]) - 1;

    for (int i = 0; i < length; i++){
        int numeroRandom = rand() % (999 - 5 + 1) + 5;
        vetor[i] = numeroRandom;
    }

    for (int i = 0; i < length; i++){
        printf("Numero: %d\n", vetor[i]);
    }

    return 0;
}