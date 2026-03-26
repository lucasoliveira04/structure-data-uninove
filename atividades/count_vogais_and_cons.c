#include <stdio.h>

int main(){

    char vogais[] = "aeiou";
    char texto[50] = "Ola, eu sou o Lucas";
    
    int lengthVogais = sizeof(vogais) / sizeof(vogais[0]) - 1;
    int lengthTexto = sizeof("Ola, eu sou o Lucas") - 1;
    
    int countVogais = 0;
    int countConsoantes = 0;

    for (int i = 0; i < lengthTexto; i++){

        int isVogal = 0;

        if (texto[i] >= 'A' && texto[i] <= 'Z'){
            continue;
        }

        for (int j = 0; j < lengthVogais; j++){
            if (texto[i] == vogais[j]){
                countVogais+=1;
                isVogal = 1;
                break;
            }
        }

        if (!isVogal && texto[i] != ' ' && texto[i] != ','){
            countConsoantes+=1;
        }
    }

    printf("Total de vogais: %d", countVogais);
    printf("\nTotal de consoantes: %d", countConsoantes);

    return 0;
}