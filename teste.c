#include <stdio.h>
 
int main() {
    int matriz[3][3] = {0}; // Inicializa a matriz com 0s
 
    //apresentar o valor 1 em cada posição da matriz diagnalmente
    for (int i = 1; i <= 3; i++) {
        matriz[i-1][i-1] = 1; // Atribui o valor 1 à posição diagonal
    }

    // Impressão da matriz
    for (int i = 0; i < 3; i++) {      // Loop para imprimir cada linha
        for (int j = 0; j < 3; j++) {  // Loop para imprimir cada coluna
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}