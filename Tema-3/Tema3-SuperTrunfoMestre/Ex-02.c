#include <stdio.h>
#include <string.h>

int main()
{

    int opcao;
    float nota1, nota2, media;

    printf("Menu de Gerenciamento de Notas dos Estudantes\n");
    printf("1.  Calcular media\n");
    printf("2. Determinar status\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Calculando a média...\n");
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        media = (nota1 + nota2) / 2;

        // testar a entrada do usuário para garantir que as notas estão dentro do intervalo válido (0 a 10)
        if ((nota1 >= 0 && nota1 <= 10) && (nota2 >= 0 && nota2 <= 10))
        {
            media = (nota1 + nota2) / 2;
        }
        else
        {
            printf("Notas inválidas! As notas devem estar entre 0 e 10.\n");
            printf("Retornando ao menu principal...\n");
            return main(); // Chama a função main novamente para permitir que o usuário insira as notas corretamente
        }
        printf("A média é: %.2f\n", media);
        break;
    case 2:
        printf("Determinar status...\n");
        printf("Digite a média do estudante: ");
        scanf("%f", &media);
        media >= 6.0 ? printf("Status: Aprovado\n") : printf("Status: Reprovado\n");

        break;

    case 3:
        printf("Saindo do programa...\n");
        break;

    default:
        printf("Opção inválida! Por favor, escolha uma opção válida.\n");
        return main(); // Chama a função main novamente para permitir que o usuário escolha uma opção válida
        break;
    }
}