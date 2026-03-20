#include <stdio.h>

int main() {
/*
Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.
 
Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
 
Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.

*/
    //0 representa água, 3 representa navio
    
    int tabuleiro[10][10] = {0}; // 0 representa água
    int navioHorizontal[3] = {3,3,3}; // Navio horizontal de tamanho 3
    int navioVertical[3] = {3,3,3}; // Navio vertical de tamanho 3

    // Posicionando o navio horizontal (exemplo: na linha 2, colunas 3 a 5)
    int linhaHorizontal = 2;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][3 + i] = navioHorizontal[i];
    }

    // Posicionando o navio vertical (exemplo: na coluna 7, linhas 1 a 3)
    int colunaVertical = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[1 + i][colunaVertical] = navioVertical[i];
    }

    // Exibindo o tabuleiro com coordenadas para melhor visualização
    printf("Tabuleiro do Batalha Naval:\n");
    printf("  "); // Espaço para alinhar com as coordenadas das colunas

    // Imprime as letras das colunas (A a J)
    for (char j = 'A'; j < 'K'; j++) {
        printf("%c ", j); // Imprime as letras das colunas
    }
    printf("\n");

    // Imprime as linhas do tabuleiro com os números das linhas
    for (int i = 0; i < 10; i++) {
        printf("%d ", i); // Imprime os números das linhas
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }





    return 0;
}