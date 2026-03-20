#include <stdio.h>

int main() {
    // 0 representa agua, 3 representa parte das formas (navio/habilidade)
    int tabuleiro[10][10] = {0};
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Pontos de origem no tabuleiro para cada forma
    int origemConeLinha = 1, origemConeColuna = 2;
    int origemCruzLinha = 4, origemCruzColuna = 6;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 3;

    // Monta o cone (apontando para baixo) em uma matriz 5x5.
    // Linha 0: 1 bloco central, linha 1: 3 blocos, linha 2: 5 blocos.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i <= 2 && j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 3;
            }
        }
    }

    // Monta a cruz (linha e coluna centrais).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 3;
            }
        }
    }

    // Monta o octaedro (losango) usando distancia de Manhattan.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int distLinha = i - 2;
            if (distLinha < 0) {
                distLinha = -distLinha;
            }

            int distColuna = j - 2;
            if (distColuna < 0) {
                distColuna = -distColuna;
            }

            if (distLinha + distColuna <= 2) {
                octaedro[i][j] = 3;
            }
        }
    }

    // Sobrepoe o cone no tabuleiro (topo do cone no ponto de origem).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 3) {
                int linhaTabuleiro = origemConeLinha + i;
                int colunaTabuleiro = origemConeColuna + (j - 2);

                if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 3;
                }
            }
        }
    }

    // Sobrepoe a cruz no tabuleiro (centro da matriz no ponto de origem).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 3) {
                int linhaTabuleiro = origemCruzLinha + (i - 2);
                int colunaTabuleiro = origemCruzColuna + (j - 2);

                if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 3;
                }
            }
        }
    }

    // Sobrepoe o octaedro no tabuleiro (centro da matriz no ponto de origem).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 3) {
                int linhaTabuleiro = origemOctaedroLinha + (i - 2);
                int colunaTabuleiro = origemOctaedroColuna + (j - 2);

                if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 3;
                }
            }
        }
    }

    // Exibindo o tabuleiro com coordenadas para melhor visualizacao
    printf("Tabuleiro do Batalha Naval:\n");
    printf("  ");

    // Imprime as letras das colunas (A a J)
    for (char j = 'A'; j < 'K'; j++) {
        printf("%c ", j);
    }
    printf("\n");

    // Imprime as linhas do tabuleiro com os números das linhas
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}