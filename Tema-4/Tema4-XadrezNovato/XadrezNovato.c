#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int torre;
    int bispo = 0;
    int rainha = 0;
    int movimento;
    // ============================================================================================================
    srand(time (NULL));
    printf("\n=========================================\n");
    printf("\nTorre: ira se mover 5 casas para a direita\n");
    printf("\n=========================================\n");

    for (torre = 1; torre <= 5; torre++)
    {
        printf("Torre: Direita\n");
    }
    // ============================================================================================================
    printf("\n=========================================\n");
    printf("\nBispo: ira se mover 5 vezes na diagonal para cima e à direita\n", bispo);
    printf("\n=========================================\n");

    while (bispo < 5)
    {
        printf("Bispo: Diagonal, cima e à direita\n");
        bispo++;
    }
    // ============================================================================================================
    printf("\n=========================================\n");
    printf("\nRainha: ira se mover 8 vezes em posições aleatorias\n");
    printf("\n=========================================\n");

    do
    {
        movimento = rand() % 5; // Gerar um número aleatório entre 0 e 4 para representar o movimento da rainha

        switch (movimento)
        {
        case 0:
            printf("Rainha: Diagonal, cima e a direita\n");
            break;
        case 1:
            printf("Rainha: Direita\n");
            break;
        case 2:
            printf("Rainha: Esquerda\n");
            break;
        case 3:
            printf("Rainha: Cima\n");
            break;
        case 4:
            printf("Rainha: Baixo\n");
            break;
        }

        rainha++;

    } while (rainha < 8);

    return 0;
}
