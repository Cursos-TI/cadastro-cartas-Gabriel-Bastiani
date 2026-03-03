#include <stdio.h>
#include <string.h>

#define TAM_CIDADE 1000 // definir o tamanho do nome da cidade como 1000 caracteres
// Quando passmos um array como parâmetro de função em C, ele decai para um pointer, então sizeof(variavel) retorna o tamanho do pointer (8 bytes), não o tamanho passado pra Array!

int CadCartas(char *estadoCarta1, char *estadoCarta2, char nomeCidade1[1000], char nomeCidade2[1000], int tamNome, float *areaCidade1, float *areaCidade2, float *pibCidade1, float *pibCidade2, int *codCarta1, int *codCarta2, int *pontosTuristicosCidade1, int *pontosTuristicosCidade2, unsigned long int *populacaoCidade1, unsigned long int *populacaoCidade2)
{
    // código para cadastrar carta
    /*Dados de entrada
    carta,estado,codigo,nomeDaCidade,populacao,area,pib,numeroDePontosTuristicos
    pra cada dados, vai haver 2 variaveis iguais*/

    // perguntar os dados Cidade 1
    printf("\n====================================================\n");
    printf(" Bem-vindo ao cadastro de cartas do Super Trunfo Aventureiro!\n");
    printf("====================================================\n");
    printf("\n>>> Vamos começar cadastrando a Carta 1 <<<\n");
    printf("----------------------------------------------------\n");

    printf("Estado da carta 1 (UF, ex: S): ");
    scanf(" %c", estadoCarta1);
    getchar();

    printf("Código da carta 1 (número inteiro, ex: 12): ");
    scanf("%d", codCarta1);
    getchar();

    printf("Nome da cidade 1: ");
    fgets(nomeCidade1, tamNome, stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("População da cidade 1 (habitantes, ex: 500000): ");
    scanf("%lu", populacaoCidade1);
    getchar();

    printf("Área da cidade 1 (km², ex: 1234.56): ");
    scanf("%f", areaCidade1);
    getchar();

    printf("PIB da cidade 1 (em bilhões de R$, ex: 2.5): ");
    scanf("%f", pibCidade1);
    getchar();

    printf("Número de pontos turísticos da cidade 1 (ex: 5): ");
    scanf("%d", pontosTuristicosCidade1);
    getchar();

    printf("----------------------------------------------------\n");
    printf(">>> Agora vamos cadastrar a Carta 2 <<<\n");
    printf("----------------------------------------------------\n");

    printf("Estado da carta 2 (UF, ex: S): ");
    scanf(" %c", estadoCarta2);
    getchar();

    printf("Código da carta 2 (número inteiro, ex: 12): ");
    scanf("%d", codCarta2);
    getchar();

    printf("Nome da cidade 2: ");
    fgets(nomeCidade2, tamNome, stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("População da cidade 2 (habitantes, ex: 500000): ");
    scanf("%lu", populacaoCidade2);
    getchar();

    printf("Área da cidade 2 (km², ex: 1234.56): ");
    scanf("%f", areaCidade2);
    getchar();

    printf("PIB da cidade 2 (em bilhões de R$, ex: 2.5): ");
    scanf("%f", pibCidade2);
    getchar();

    printf("Número de pontos turísticos da cidade 2 (ex: 5): ");
    scanf("%d", pontosTuristicosCidade2);
    getchar();
    printf("----------------------------------------------------\n");
}

void calcularDensidadePopulacional(unsigned long int populacaoCidade1, unsigned long int populacaoCidade2, float areaCidade1, float areaCidade2, float *densidadePopulacionalCidade1, float *densidadePopulacionalCidade2)
{
    // código para calcular densidade populacional
    *densidadePopulacionalCidade1 = (float)populacaoCidade1 / areaCidade1;
    *densidadePopulacionalCidade2 = (float)populacaoCidade2 / areaCidade2;
}

void calcularPibPerCapita(float pibCidade1, float pibCidade2, unsigned long int populacaoCidade1, unsigned long int populacaoCidade2, float *pibPerCapitaCidade1, float *pibPerCapitaCidade2)
{
    // código para calcular PIB per capita
    *pibPerCapitaCidade1 = (float)(pibCidade1 * 1000000000.0) / populacaoCidade1; // multiplicar o PIB por 1 bilhão para converter de bilhões para unidades monetárias, e depois dividir pela população para obter o PIB per capita
    *pibPerCapitaCidade2 = (float)(pibCidade2 * 1000000000.0) / populacaoCidade2;
}

// Calcular o Super Poder: Para cada carta, calcule o "Super Poder" somando todos os atributos numéricos (população, área, PIB, número de pontos turísticos, PIB per capita e o inverso da densidade populacional – quanto menor a densidade, maior o "poder").
void calcularSuperPoder(unsigned long int populacaoCidade1, unsigned long int populacaoCidade2, float areaCidade1, float areaCidade2, float pibCidade1, float pibCidade2, int pontosTuristicosCidade1, int pontosTuristicosCidade2, float densidadePopulacionalCidade1, float densidadePopulacionalCidade2, float pibPerCapitaCidade1, float pibPerCapitaCidade2, float *superPoderCidade1, float *superPoderCidade2)
{
    // código para calcular o Super Poder
    *superPoderCidade1 = (float)(populacaoCidade1 + areaCidade1 + pibCidade1 + pontosTuristicosCidade1 + pibPerCapitaCidade1 + (1.0 / densidadePopulacionalCidade1)); // o inverso da densidade populacional é calculado como 1 dividido pela densidade populacional, para que cidades com menor densidade tenham um valor maior contribuindo para o Super Poder.
    *superPoderCidade2 = (float)(populacaoCidade2 + areaCidade2 + pibCidade2 + pontosTuristicosCidade2 + pibPerCapitaCidade2 + (1.0 / densidadePopulacionalCidade2));
}

void exibirCartas(char estadoCarta1, char estadoCarta2, char nomeCidade1[1000], char nomeCidade2[1000], float areaCidade1, float areaCidade2, float pibCidade1, float pibCidade2, int codCarta1, int codCarta2, int pontosTuristicosCidade1, int pontosTuristicosCidade2, unsigned long int populacaoCidade1, unsigned long int populacaoCidade2, float densidadePopulacionalCidade1, float densidadePopulacionalCidade2, float pibPerCapitaCidade1, float pibPerCapitaCidade2, float superPoderCidade1, float superPoderCidade2)
{
    // código para exibir cartas cadastradas
    // print todas as infos da cidade 1
    printf("\n================= CARTA 1 =================\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Código: %c%02d\n", estadoCarta1, codCarta1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("População: %d habitantes\n", populacaoCidade1);
    printf("Área: %.2f km²\n", areaCidade1);
    printf("PIB: %.2f bilhões de R$\n", pibCidade1);
    printf("Pontos turísticos: %d pontos\n", pontosTuristicosCidade1);
    printf("Densidade populacional: %.2f hab/km²\n", densidadePopulacionalCidade1);
    printf("PIB per capita: %.2f R$\n", pibPerCapitaCidade1);
    printf("Super Poder: %.2f pontos\n", superPoderCidade1);

    printf("\n-------------------------------------------\n");

    printf("\n================= CARTA 2 =================\n");
    printf("Estado: %c\n", estadoCarta2);
    printf("Código: %c%02d\n", estadoCarta2, codCarta2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("População: %d habitantes\n", populacaoCidade2);
    printf("Área: %.2f km²\n", areaCidade2);
    printf("PIB: %.2f bilhões de R$\n", pibCidade2);
    printf("Pontos turísticos: %d pontos\n", pontosTuristicosCidade2);
    printf("Densidade populacional: %.2f hab/km²\n", densidadePopulacionalCidade2);
    printf("PIB per capita: %.2f R$\n", pibPerCapitaCidade2);
    printf("Super Poder: %.2f pontos\n", superPoderCidade2);
}

// fazer comparação com estrutura de decisão para exibir a carta vencedora com base no Super Poder calculado
void exibirCartaVencedora(float superPoderCidade1, float superPoderCidade2)
{
    if (superPoderCidade1 > superPoderCidade2)
    {
        printf("----------------------------------------------------\n");
        printf("\nA Carta 1 é a vencedora com um Super Poder de %.2f!\n", superPoderCidade1);
        printf("A carta 2 perdeu com um Super Poder de %.2f!\n", superPoderCidade2);
        printf("----------------------------------------------------\n");
    }
    else if (superPoderCidade2 > superPoderCidade1)
    {
        printf("----------------------------------------------------\n");
        printf("\nA Carta 2 é a vencedora com um Super Poder de %.2f!\n", superPoderCidade2);
        printf("A carta 1 perdeu com um Super Poder de %.2f!\n", superPoderCidade1);
        printf("----------------------------------------------------\n");
    }
    else
    {
        printf("----------------------------------------------------\n");
        printf("\nAs duas cartas têm o mesmo Super Poder de %.2f! É um empate!\n", superPoderCidade1);
        printf("----------------------------------------------------\n");
    }

} //

int main()
{ // Variáveis para armazenar os dados das cartas
    char estadoCarta1, estadoCarta2, nomeCidade1[1000], nomeCidade2[1000];
    float areaCidade1, areaCidade2, pibCidade1, pibCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2;
    int codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2;
    float superPoderCidade1, superPoderCidade2;
    unsigned long int populacaoCidade1, populacaoCidade2;

    // chamar as funções para cadastrar cartas, calcular densidade populacional, calcular PIB per capita e exibir as cartas cadastradas
    CadCartas(&estadoCarta1, &estadoCarta2, nomeCidade1, nomeCidade2, TAM_CIDADE, &areaCidade1, &areaCidade2, &pibCidade1, &pibCidade2, &codCarta1, &codCarta2, &pontosTuristicosCidade1, &pontosTuristicosCidade2, &populacaoCidade1, &populacaoCidade2);
    calcularDensidadePopulacional(populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, &densidadePopulacionalCidade1, &densidadePopulacionalCidade2);
    calcularPibPerCapita(pibCidade1, pibCidade2, populacaoCidade1, populacaoCidade2, &pibPerCapitaCidade1, &pibPerCapitaCidade2);
    calcularSuperPoder(populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, pontosTuristicosCidade1, pontosTuristicosCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2, &superPoderCidade1, &superPoderCidade2);
    exibirCartas(estadoCarta1, estadoCarta2, nomeCidade1, nomeCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, populacaoCidade1, populacaoCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2, superPoderCidade1, superPoderCidade2);
    exibirCartaVencedora(superPoderCidade1, superPoderCidade2);

    return 0;
}