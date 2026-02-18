#include <stdio.h>
#include <string.h>

#define TAM_CIDADE 1000 // definir o tamanho do nome da cidade como 1000 caracteres
// Quando passmos um array como parâmetro de função em C, ele decai para um pointer, então sizeof(variavel) retorna o tamanho do pointer (8 bytes), não o tamanho passado pra Array!

int CadCartas(char *estadoCarta1, char *estadoCarta2, char nomeCidade1[1000], char nomeCidade2[1000], int tamNome, float *areaCidade1, float *areaCidade2, float *pibCidade1, float *pibCidade2, int *codCarta1, int *codCarta2, int *pontosTuristicosCidade1, int *pontosTuristicosCidade2, int *populacaoCidade1, int *populacaoCidade2)
{
    // código para cadastrar carta
    /*Dados de entrada
    carta,estado,codigo,nomeDaCidade,populacao,area,pib,numeroDePontosTuristicos
    pra cada dados, vai haver 2 variaveis iguais*/

    // perguntar os dados Cidade 1
    printf("\n-----------------------------\n");
    printf("\nBem-vindo ao cadastro de cartas do Super Trunfo Aventureiro!\n");
    printf("\n-----------------------------\n");
    printf("\nVamos começar cadastrando a Carta 1\n");
    
    printf("Digite o estado da carta 1: ");
    scanf(" %c", estadoCarta1);
    getchar();

    printf("Digite o código da carta 1: ");
    scanf("%d", codCarta1); // código com espaço
    getchar();

    printf("Digite o nome da cidade 1: ");
    fgets(nomeCidade1, tamNome, stdin);         
    // remover o caractere de nova linha do final da string
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("Digite a população da cidade 1: ");
    scanf("%d", populacaoCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite a área da cidade 1: ");
    scanf("%f", areaCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o PIB da cidade 1: ");
    scanf("%f", pibCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", pontosTuristicosCidade1);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf
   
    //
    printf("\n-----------------------------\n");
    // perguntar os dados Cidade 2
    printf("Vamos cadastrar a Carta 2\n");
    printf("\nDigite o estado da carta 2: ");
    scanf(" %c", estadoCarta2);
    getchar();

    printf("Digite o código da carta 2: ");
    scanf("%d", codCarta2); // código com espaço
    getchar();

    printf("Digite o nome da cidade 2: ");
    fgets(nomeCidade2, tamNome, stdin);
    // remover o caractere de nova linha do final da string
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população da cidade 2: ");
    scanf("%d", populacaoCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite a área da cidade 2: ");
    scanf("%f", areaCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o PIB da cidade 2: ");
    scanf("%f", pibCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf

    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", pontosTuristicosCidade2);
    getchar(); // consumir o caractere de nova linha deixado pelo scanf
}

void calcularDensidadePopulacional(int populacaoCidade1, int populacaoCidade2, float areaCidade1, float areaCidade2, float *densidadePopulacionalCidade1, float *densidadePopulacionalCidade2)
{
    // código para calcular densidade populacional
    *densidadePopulacionalCidade1 = (float)populacaoCidade1 / areaCidade1;
    *densidadePopulacionalCidade2 = (float)populacaoCidade2 / areaCidade2;
}

void calcularPibPerCapita(float pibCidade1, float pibCidade2, int populacaoCidade1, int populacaoCidade2, float *pibPerCapitaCidade1, float *pibPerCapitaCidade2)
{
    // código para calcular PIB per capita
    *pibPerCapitaCidade1 = (float)(pibCidade1 *1000000000.0) / populacaoCidade1;
    *pibPerCapitaCidade2 = (float)(pibCidade2 *1000000000.0) / populacaoCidade2;
}

void exibirCartas(char estadoCarta1, char estadoCarta2, char nomeCidade1[1000], char nomeCidade2[1000], float areaCidade1, float areaCidade2, float pibCidade1, float pibCidade2, int codCarta1, int codCarta2, int pontosTuristicosCidade1, int pontosTuristicosCidade2, int populacaoCidade1, int populacaoCidade2, float densidadePopulacionalCidade1, float densidadePopulacionalCidade2, float pibPerCapitaCidade1, float pibPerCapitaCidade2)
{
    // código para exibir cartas cadastradas
    // print todas as infos da cidade 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Código: %c%02d\n", estadoCarta1, codCarta1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacaoCidade1);
    printf("Área: %.2f\n", areaCidade1);
    printf("PIB: %.2f\n", pibCidade1);
    printf("Pontos turísticos: %d\n", pontosTuristicosCidade1);
    printf("Densidade populacional: %.2f\n", densidadePopulacionalCidade1);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade1);

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
    printf("Densidade populacional: %.2f\n", densidadePopulacionalCidade2);
    printf("PIB per capita: %.2f\n", pibPerCapitaCidade2);
    //
}

int main()
{ // Variáveis para armazenar os dados das cartas
    char estadoCarta1, estadoCarta2, nomeCidade1[1000], nomeCidade2[1000];
    float areaCidade1, areaCidade2, pibCidade1, pibCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2;
    int codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, populacaoCidade1, populacaoCidade2;

    // chamar as funções para cadastrar cartas, calcular densidade populacional, calcular PIB per capita e exibir as cartas cadastradas
    CadCartas(&estadoCarta1, &estadoCarta2, nomeCidade1, nomeCidade2, TAM_CIDADE, &areaCidade1, &areaCidade2, &pibCidade1, &pibCidade2, &codCarta1, &codCarta2, &pontosTuristicosCidade1, &pontosTuristicosCidade2, &populacaoCidade1, &populacaoCidade2);
    calcularDensidadePopulacional(populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, &densidadePopulacionalCidade1, &densidadePopulacionalCidade2);
    calcularPibPerCapita(pibCidade1, pibCidade2, populacaoCidade1, populacaoCidade2, &pibPerCapitaCidade1, &pibPerCapitaCidade2);
    exibirCartas(estadoCarta1, estadoCarta2, nomeCidade1, nomeCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, populacaoCidade1, populacaoCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2);
    return 0;
}