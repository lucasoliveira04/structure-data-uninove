#include <stdio.h>

int main(){
    int cqtegoriasFuncionarioA[4] = {5, 10, 3, 10};
    int cqtegoriasFuncionarioB[4] = {3, 90, 4, 3};

    int pontosFuncionarioA = 0;
    int pontosFuncionarioB = 0;

    int lengthFuncionarioA = sizeof(cqtegoriasFuncionarioA) / sizeof(cqtegoriasFuncionarioA[0]);
    int lengthFuncionarioB = sizeof(cqtegoriasFuncionarioB) / sizeof(cqtegoriasFuncionarioB[0]);

    for (int i = 0; i < lengthFuncionarioA; i++){
        if (cqtegoriasFuncionarioA[i] > cqtegoriasFuncionarioB[i]){
            pontosFuncionarioA+=1;
        } else if (cqtegoriasFuncionarioA[i] < cqtegoriasFuncionarioB[i]) {
            pontosFuncionarioB+=1;
        }
    }

    printf("Pontos funcionario A: %d\n", pontosFuncionarioA);
    printf("Pontos funcionario B: %d", pontosFuncionarioB);

    return 0;
}