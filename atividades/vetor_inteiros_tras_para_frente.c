#include <stdio.h>

int main(){
    int vetor[5] = {2, 4, 1, 3, 5};
    int length = sizeof(vetor) / sizeof(vetor) - 1;

    for (int i = length - 1; i >= 0; i--){
        printf("%d", vetor[i]);
    }

    return 0;
}