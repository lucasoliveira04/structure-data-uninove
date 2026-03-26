#include <stdio.h>

int main(){
    int musicas[6] = {120, 201, 800, 200, 30, 20};

    int length = sizeof(musicas) / sizeof(musicas[0]);

    int maior = musicas[0];
    int segundoDoMaior = musicas[0];

    for (int i = 1; i < length; i++) {
        if (musicas[i] > maior) {
            maior = musicas[i];
        }
    }

    for (int i = 1; i < length; i++){
        int tempSegundoMaior = musicas[i-1];
        int nextSegundoMaior = musicas[i+1];
        if (tempSegundoMaior > nextSegundoMaior) {
            segundoDoMaior = tempSegundoMaior;
        } else {
            segundoDoMaior = nextSegundoMaior;
        }
        if (musicas[i] == maior){
            break;
        }
    }

    printf("Maior valor: %d", maior);
    printf("\nSegundo: %d", segundoDoMaior);
    
    return 0;
}