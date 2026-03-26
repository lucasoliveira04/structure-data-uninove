#include <stdio.h>

int main(){
    int target = 30;
    int produtos[4] = {10, 20, 35, 50, 75};

    int length = sizeof(produtos) / sizeof(produtos[0]);

    int flag = -1;

    for (int i = 0; i < length; i++){
        for (int j = i + 1; j < length; j++) {
            int sum = produtos[i] + produtos[j];
            if (sum == target) {
                printf("Inidices: [%d, %d]", i, j);
                printf("\n%d + %d = %d", produtos[i], produtos[j], sum);
                return flag;
            }
            flag = 1;
        }
    }

    if (flag){
        printf("Não foi encontrado o valor.");
    }

    return 0;
}