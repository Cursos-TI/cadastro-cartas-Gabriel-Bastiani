#include <stdio.h>

int main() {
/*
 

Criar um Tabuleiro 10x10: Declare uma matriz (array bidimensional) de tamanho 10x10 para representar o tabuleiro do Batalha Naval. Inicialize todas as posições com o valor 0, representando água.
 
Posicionar Quatro Navios: Posicione quatro navios no tabuleiro.
 
Dois navios devem estar posicionados horizontalmente ou verticalmente (como no nível anterior).
 
Os outros dois navios devem ser posicionados na diagonal. Considere que um navio diagonal ocupa posições onde a linha e a coluna aumentam ou diminuem simultaneamente (ex: tabuleiro[i][i] ou tabuleiro[i][9-i] para um tabuleiro 10x10).
 
Represente as posições ocupadas pelos navios com o valor 3.
 
Escolha as coordenadas iniciais.
 
Valide que as posições dos navios estejam dentro dos limites do tabuleiro e que eles não se sobreponham.
 
Exibir o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro completo no console. A saída deve mostrar a matriz 10x10, com 0s representando água e 3s representando as partes dos navios. Utilize espaços para alinhar a saída e facilitar a visualização do tabuleiro.

*/
    //0 representa água, 3 representa navio
    
    int tabuleiro[10][10] = {0}; // 0 representa água
    int navioHorizontal1[3] = {3,3,3}; // Navio horizontal de tamanho 3
    int navioHorizontal2[3] = {3,3,3}; // Navio horizontal de tamanho 3
    int navioVertical1[3] = {3,3,3}; // Navio vertical de tamanho 3
    int navioVertical2[3] = {3,3,3}; // Navio vertical de tamanho 3

    // Posicionando o navio horizontal (exemplo: na linha 2, colunas 3 a 5)
    int linhaHorizontal = 2;
    for (int i = 0; i < 3; i++) {
        //verificar se a posição está dentro dos limites do tabuleiro e se não há sobreposição
        if (1 + i < 10 && tabuleiro[linhaHorizontal][3 + i] == 0) {
            tabuleiro[linhaHorizontal][3 + i] = navioHorizontal1[i];
        }
    }
    // Posicionando o navio horizontal (exemplo: na linha 5, colunas 1 a 3)
    linhaHorizontal = 5;
    for (int i = 0; i < 3; i++) {
        //verificar se a posição está dentro dos limites do tabuleiro e se não há sobreposição
        if (1 + i < 10 && tabuleiro[linhaHorizontal][1 + i] == 0) {
            tabuleiro[linhaHorizontal][1 + i] = navioHorizontal2[i];
        }
    }

    // Posicionando o navio vertical (exemplo: na coluna 7, linhas 1 a 3)
    int colunaVertical = 7;
    for (int i = 0; i < 3; i++) {
        //verificar se a posição está dentro dos limites do tabuleiro e se não há sobreposição
        if (1 + i < 10 && tabuleiro[1 + i][colunaVertical] == 0) {
            tabuleiro[1 + i][colunaVertical] = navioVertical1[i];
        }
    }

    // Posicionando o navio vertical (exemplo: na coluna 2, linhas 4 a 6)
    int colunaVertical2 = 2;
    for (int i = 0; i < 3; i++) {
        //verificar se a posição está dentro dos limites do tabuleiro e se não há sobreposição
        if (4 + i < 10 && tabuleiro[4 + i][colunaVertical2] == 0) {
            tabuleiro[4 + i][colunaVertical2] = navioVertical2[i];
        }
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