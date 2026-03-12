#include <stdio.h>

int main()
{

    printf("Números pares de 0 a 10 usando While\n");
    int i = 0;

    while (i <= 10)
    {
        if (i % 2 == 0)
        {

            printf("O numeor %d é pár \n", i);
        }
        i++;
    }
    // ============================================
    printf("\n=========================================\n");
    printf("\nNúmeros pares de 0 a 10 usando do-While\n");

    int j = 0;

    do
    {
        printf("O número %d é par \n", j);
        j += 2;

    } while (j <= 10);

printf("\n=========================================\n");
    printf("Taboada usando For\n");

    printf("\nDigite um número para ver sua tabuada:\n");

    int num;
    scanf("%d", &num);

    printf("\nTabuada de %d:\n", num);
    for (int t = 0; t <=10; t++)
    {
        printf("%d x %d = %d\n", num, t, num * t);
    }

    printf("\n=========================================\n");
    printf("Sair do programa\n");

    int numero;

    do{
        printf("Digite um numero par para sair: \n");
        scanf("%d", &numero);

        if(numero % 2 == 0){
            printf("Número par digitado, saindo do programa...\n");
        } else {
            printf("Número ímpar digitado, tente novamente.\n");
        }

    } while (numero % 2 != 0);

    return 0;
    
}