#include <stdio.h>
#include <string.h>

int CadCartas()
{
    // código para cadastrar carta
    /*Dados de entrada
    carta,estado,codigo,nomeDaCidade,populacao,area,pib,numeroDePontosTuristicos
    pra cada dados, vai haver 2 variaveis iguais*/

    char estadoCarta1, estadoCarta2, nomeCidade1[20], nomeCidade2[20];
    float areaCidade1, areaCidade2, pibCidade1, pibCidade2;
    int codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, populacaoCidade1, populacaoCidade2;

    // perguntar os dados Cidade 1
    printf("Digite o estado da carta 1: ");
    scanf(" %c", &estadoCarta1);

    printf("Digite o código da carta 1: ");
    scanf("%d", &codCarta1); // código com espaço
    getchar();

    printf("Digite o nome da cidade 1: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    // remover o caractere de nova linha do final da string
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("Digite a população da cidade 1: ");
    scanf("%d", &populacaoCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite a área da cidade 1: ");
    scanf("%f", &areaCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o PIB da cidade 1: ");
    scanf("%f", &pibCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &pontosTuristicosCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    // perguntar os dados Cidade 2
    //
    printf("Digite o estado da carta 2: ");
    scanf(" %c", &estadoCarta2);

    printf("Digite o código da carta 2: ");
    scanf("%d", &codCarta2); // código com espaço
    getchar();

    printf("Digite o nome da cidade 2: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    // remover o caractere de nova linha do final da string
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população da cidade 2: ");
    scanf("%d", &populacaoCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite a área da cidade 2: ");
    scanf("%f", &areaCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o PIB da cidade 2: ");
    scanf("%f", &pibCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &pontosTuristicosCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf


    // exibir os dados cadastrados
     // print todas as infos da cidade 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Código: %c%02d\n", estadoCarta1, codCarta1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacaoCidade1);
    printf("Área: %.2f\n", areaCidade1);
    printf("PIB: %.2f\n", pibCidade1);
    printf("Pontos turísticos: %d\n", pontosTuristicosCidade1);
    
    printf("\n-----------------------------\n");

    // print todas as infos da cidade 2
     printf("\nCarta 2:\n");
    printf("Estado: %c\n", estadoCarta2);
    printf("Código: %c%02d\n", estadoCarta2, codCarta2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacaoCidade2);
    printf("Área: %.2f\n", areaCidade2);
    printf("PIB: %.2f\n", pibCidade2);
    printf("Pontos turísticos: %d\n", pontosTuristicosCidade2);
    //
}

int main()
{
    CadCartas();
    return 0;
}