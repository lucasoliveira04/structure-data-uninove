#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    char sobrenome[] = "Oliveira";
    int length = sizeof(sobrenome) / sizeof(sobrenome[0]) - 1;

    for (int i = 0; i < length; i++){
        int numeroRandom = rand() % (10 - 0 + 1) + 5;

        if (numeroRandom % 2 == 0) {
            printf("%c", sobrenome[i]);
        }
    }

    return 0;
}