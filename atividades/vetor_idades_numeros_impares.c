#include <stdio.h>

int main(){
    int idades[6] = {21, 20, 18, 32, 45, 64};
    int length = sizeof(idades) / sizeof(idades[0]) - 1;

    for (int i = 0; i < length; i++){
        if (idades[i] % 2 != 0){
            printf("Idade: %d\n", idades[i]);
        }
    }

    return 0;
}