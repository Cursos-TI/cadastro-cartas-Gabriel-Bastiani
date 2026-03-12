#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// recursividade
void torre_movimento(int torre)
{

    if (torre > 0)
    {
        printf("Torre: Direita\n");
        torre--;
        torre_movimento(torre);
    }
}
// ============================================================================================================

// recursivo com loop aninhado. Sendo o loop mais externo o vertical, e o mais interno o horizontal.
void bispo_movimento(int bispo)
{

    if (bispo > 0)
    {
        if(bispo % 2 == 0)
        {
            printf("Bispo: Diagonal, cima e à direita\n");
        }
        else
        {
            printf("Bispo: Diagonal, cima e à esquerda\n");
        }
        bispo--;
        bispo_movimento(bispo);
    }
}

// ============================================================================================================

void rainha_movimento(int rainha)
{

    if (rainha > 0)
    {
        int movimento = rand() % 5; // Gera um número aleatório entre 0 e 4
        switch (movimento)
        {
        case 0:
            printf("Rainha: Direita\n");
            break;
        case 1:
            printf("Rainha: Esquerda\n");
            break;
        case 2:
            printf("Rainha: Cima\n");
            break;
        case 3:
            printf("Rainha: Baixo\n");
            break;
        case 4:
            printf("Rainha: Diagonal para cima e à direita\n");
            break;
        }
        rainha--;
        rainha_movimento(rainha);
    }
}

int main()
{
    int torre = 5, bispo = 5, rainha = 8;

    srand(time(NULL));

    printf("\n=========================================\n");
    printf("\nTorre: ira se mover 5 casas para a direita\n");
    printf("\n=========================================\n");
    torre_movimento(torre);
    printf("\n=========================================\n");
    printf("\nBispo: ira se mover 5 vezes na diagonal para cima e à direita\n", bispo);
    printf("\n=========================================\n");
    bispo_movimento(bispo);
    printf("\n=========================================\n");
    printf("\nRainha: ira se mover 8 vezes em posições aleatorias\n");
    printf("\n=========================================\n");
    rainha_movimento(rainha);

    // ============================================================================================================
    printf("\n=========================================\n");
    printf("\nCavalo: ira se mover 2 casas para cima e 1 para direita\n");
    printf("\n=========================================\n");

    //loops aninhados. Loop complexo com mais de uma variavel.
    for (int cavalo = 1, i = 0; i <= 2 && cavalo <= 3; i++)
    {
        while (cavalo <=2)
        {
            printf("Cavalo: Cima\n");
            cavalo++;
            i++;
        }
        if (i == 2)
        {
            printf("Cavalo: Direita\n");
        }
        
    }

    return 0;
}
