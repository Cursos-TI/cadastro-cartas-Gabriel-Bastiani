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
void exibirCartaVencedora(bool *vencedor, float *valorAtributoCarta1, float *valorAtributoCarta2, int *opcaoCarta1, int *opcaoCarta2, char nomeCidade1[1000], char nomeCidade2[1000], unsigned long int populacaoCidade1, unsigned long int populacaoCidade2, float areaCidade1, float areaCidade2, float pibCidade1, float pibCidade2, int pontosTuristicosCidade1, int pontosTuristicosCidade2, float densidadePopulacionalCidade1, float densidadePopulacionalCidade2)
{
    // nao deu pra entender o que o professor quer de fato que seja apresentando. Não está claro se o professor quer a soma dos 2 atributos diferentes de cartas diferentes, ou o do mesmo atributo com cartas diferentes ou 2 atributos da mesma carta....
    // feedback, forneça um exemplo de saida no exercicio.
    // Tentei fazer da forma mais simples e de como foi passado em aula, sem usar laço de repição, array nem nada mais complexo.

    // Menu Interativo Carta 1 vs Carta 2
    printf("----------------------------------------------------\n");
    printf("\nComparando as cartas...\n");
    printf("----------------------------------------------------\n");
    printf("Escolha o primeiro atributo que você usará para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica(Populacional)\n");
    scanf("%d", opcaoCarta1);
    getchar();

    // salvando o atributo selecionado para a comparação da carta 1, para que na comparação da carta 2, o usuário não possa escolher o mesmo atributo e seja forçado a escolher um atributo diferente para a comparação da carta 2
    printf("Você escolheu o primeiro atributo que é a opção: %d\n", *opcaoCarta1);

    // 2° Menu Interativo
    printf("\nEscolha o segundo atributo que você usará para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica(Populacional)\n");
    scanf("%d", opcaoCarta2);
    getchar();

    // verificando se o usuário escolheu o mesmo atributo duas vezes
    if (*opcaoCarta2 == *opcaoCarta1)
    {
        printf("Você não pode escolher o mesmo atributo duas vezes!\nPor favor, escolha novamente os Dois atributos, sendo eles diferentes.\n");
        return exibirCartaVencedora(vencedor, valorAtributoCarta1, valorAtributoCarta2, opcaoCarta1, opcaoCarta2, nomeCidade1, nomeCidade2, populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, pontosTuristicosCidade1, pontosTuristicosCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2);
    }
    else
    {
        printf("Você escolheu o segundo atributo que é a opção: %d.\n", *opcaoCarta2);
    }

    switch (*opcaoCarta1)
    {
    case 1:
        *valorAtributoCarta1 = (float)(populacaoCidade1 + populacaoCidade2); // somar o valor do atributo escolhido para a carta 1, para depois comparar com o valor do mesmo atributo da carta 2
        printf("\nComparando População das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %lu habitantes\n", nomeCidade1, populacaoCidade1);
        printf("%s: %lu habitantes\n", nomeCidade2, populacaoCidade2);
        printf("A soma dos valores do atributo 'População' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta1);
        if (populacaoCidade1 > populacaoCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (populacaoCidade2 > populacaoCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 2:
        *valorAtributoCarta1 = areaCidade1 + areaCidade2; // somar o valor do atributo escolhido para a carta 1, para depois comparar com o valor do mesmo atributo da carta 2
        printf("\nComparando Área das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f km²\n", nomeCidade1, areaCidade1);
        printf("%s: %.2f km²\n", nomeCidade2, areaCidade2);
        printf("A soma dos valores do atributo 'Área' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta1);
        if (areaCidade1 > areaCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (areaCidade2 > areaCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 3:
        *valorAtributoCarta1 = pibCidade1 + pibCidade2; // somar o valor do atributo escolhido para a carta 1, para depois comparar com o valor do mesmo atributo da carta 2
        printf("\nComparando PIB das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f bilhões de R$\n", nomeCidade1, pibCidade1);
        printf("%s: %.2f bilhões de R$\n", nomeCidade2, pibCidade2);
        printf("A soma dos valores do atributo 'PIB' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta1);
        if (pibCidade1 > pibCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (pibCidade2 > pibCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 4:
        *valorAtributoCarta1 = (float)(pontosTuristicosCidade1 + pontosTuristicosCidade2); // somar o valor do atributo escolhido para a carta 1, para depois comparar com o valor do mesmo atributo da carta 2
        printf("\nComparando Pontos Turísticos das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %d pontos\n", nomeCidade1, pontosTuristicosCidade1);
        printf("%s: %d pontos\n", nomeCidade2, pontosTuristicosCidade2);
        printf("A soma dos valores do atributo 'Pontos Turísticos' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta1);
        if (pontosTuristicosCidade1 > pontosTuristicosCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (pontosTuristicosCidade2 > pontosTuristicosCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 5:
        *valorAtributoCarta1 = densidadePopulacionalCidade1 + densidadePopulacionalCidade2; // somar o valor do atributo escolhido para a carta 1, para depois comparar com o valor do mesmo atributo da carta 2
        printf("\nComparando Densidad Demográfica(Populacional) das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f hab/km²\n", nomeCidade1, densidadePopulacionalCidade1);
        printf("%s: %.2f hab/km²\n", nomeCidade2, densidadePopulacionalCidade2);
        printf("A soma dos valores do atributo 'Densidade Demográfica' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta1);
        if (densidadePopulacionalCidade1 < densidadePopulacionalCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (densidadePopulacionalCidade2 < densidadePopulacionalCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
    default:
        break;
    }

    // switch para comparar o segundo atributo escolhido pelo usuário para a carta 2
    switch (*opcaoCarta2)
    { // Comparação do segundo atributo
    case 1:
        *valorAtributoCarta2 = (float)(populacaoCidade2 + populacaoCidade1); // somar o valor do atributo escolhido para a carta 2, para depois comparar com o valor do mesmo atributo da carta 1
        // Comparar população do segundo atributo
        printf("\nComparando População das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %lu habitantes\n", nomeCidade1, populacaoCidade1);
        printf("%s: %lu habitantes\n", nomeCidade2, populacaoCidade2);
        printf("A soma dos valores do atributo 'População' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta2);
        if (populacaoCidade1 > populacaoCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (populacaoCidade2 > populacaoCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 2:
        *valorAtributoCarta2 = areaCidade2 + areaCidade1; // somar o valor do atributo escolhido para a carta 2, para depois comparar com o valor do mesmo atributo da carta 1
        // Comparar área do segundo atributo
        printf("\nComparando Área das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f km²\n", nomeCidade1, areaCidade1);
        printf("%s: %.2f km²\n", nomeCidade2, areaCidade2);
        printf("A soma dos valores do atributo 'Área' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta2);
        if (areaCidade1 > areaCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (areaCidade2 > areaCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 3:
        *valorAtributoCarta2 = pibCidade2 + pibCidade1; // somar o valor do atributo escolhido para a carta 2, para depois comparar com o valor do mesmo atributo da carta 1
        printf("\nComparando PIB das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f bilhões de R$\n", nomeCidade1, pibCidade1);
        printf("%s: %.2f bilhões de R$\n", nomeCidade2, pibCidade2);
        printf("A soma dos valores do atributo 'PIB' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta2);
        if (pibCidade1 > pibCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (pibCidade2 > pibCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 4:
        // Comparar pontos turísticos do segundo atributo
        *valorAtributoCarta2 = (float)(pontosTuristicosCidade2 + pontosTuristicosCidade1); // somar o valor do atributo escolhido para a carta 2, para depois comparar com o valor do mesmo atributo da carta 1
        printf("\nComparando Pontos Turísticos das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %d pontos turísticos\n", nomeCidade1, pontosTuristicosCidade1);
        printf("%s: %d pontos turísticos\n", nomeCidade2, pontosTuristicosCidade2);
        printf("A soma dos valores do atributo 'Pontos Turísticos' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta2);
        if (pontosTuristicosCidade1 > pontosTuristicosCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (pontosTuristicosCidade2 > pontosTuristicosCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    case 5:
        // Comparar densidad demográfica do segundo atributo
        *valorAtributoCarta2 = densidadePopulacionalCidade2 + densidadePopulacionalCidade1; // somar o valor do atributo escolhido para a carta 2, para depois comparar com o valor do mesmo atributo da carta 1
        printf("\nComparando Densidade Demográfica das Cidades %s e %s:\n", nomeCidade1, nomeCidade2);
        printf("%s: %.2f habitantes/km²\n", nomeCidade1, densidadePopulacionalCidade1);
        printf("%s: %.2f habitantes/km²\n", nomeCidade2, densidadePopulacionalCidade2);
        printf("A soma dos valores do atributo 'Densidade Demográfica' da carta 1 e carta 2 é: %.2f\n", *valorAtributoCarta2);
        if (densidadePopulacionalCidade1 > densidadePopulacionalCidade2)
        {
            printf("Vencedora: %s\n", nomeCidade1);
        }
        else
        {
            if (densidadePopulacionalCidade2 > densidadePopulacionalCidade1)
            {
                printf("Vencedora: %s\n", nomeCidade2);
            }
            else
            {
                printf("Empate!\n");
            }
        }
        break;
    default:
        break;
    }

    // exibir a carta vencedora com base na soma dos valores dos atributos escolhidos para cada carta, e tratar o empate caso a soma seja igual
    if (*valorAtributoCarta1 > *valorAtributoCarta2)
    {
        *vencedor = 1;
    }
    else
    {
        if (*valorAtributoCarta2 > *valorAtributoCarta1)
        {
            *vencedor = 0;
        }
        else
        {
            printf("\nEmpate!\n");
        }
    }

    *vencedor == 1 ? printf("\nO atributo com o maior valor é da cidade: %s\n", nomeCidade1) : printf("\nO atributo com o maior valor é da cidade: %s\n", nomeCidade2);
}

//

int main()
{ // Variáveis para armazenar os dados das cartas
    char estadoCarta1, estadoCarta2, nomeCidade1[1000], nomeCidade2[1000];
    float areaCidade1, areaCidade2, pibCidade1, pibCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2, valorAtributoCarta1, valorAtributoCarta2;
    int codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, opcaoCarta1, opcaoCarta2;
    float superPoderCidade1, superPoderCidade2;
    unsigned long int populacaoCidade1, populacaoCidade2;
    bool vencedor; // variável para armazenar o nome da cidade vencedora

    // chamar as funções para cadastrar cartas, calcular densidade populacional, calcular PIB per capita e exibir as cartas cadastradas
    CadCartas(&estadoCarta1, &estadoCarta2, nomeCidade1, nomeCidade2, TAM_CIDADE, &areaCidade1, &areaCidade2, &pibCidade1, &pibCidade2, &codCarta1, &codCarta2, &pontosTuristicosCidade1, &pontosTuristicosCidade2, &populacaoCidade1, &populacaoCidade2);
    calcularDensidadePopulacional(populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, &densidadePopulacionalCidade1, &densidadePopulacionalCidade2);
    calcularPibPerCapita(pibCidade1, pibCidade2, populacaoCidade1, populacaoCidade2, &pibPerCapitaCidade1, &pibPerCapitaCidade2);
    calcularSuperPoder(populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, pontosTuristicosCidade1, pontosTuristicosCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2, &superPoderCidade1, &superPoderCidade2);
    exibirCartas(estadoCarta1, estadoCarta2, nomeCidade1, nomeCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, codCarta1, codCarta2, pontosTuristicosCidade1, pontosTuristicosCidade2, populacaoCidade1, populacaoCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2, pibPerCapitaCidade1, pibPerCapitaCidade2, superPoderCidade1, superPoderCidade2);
    exibirCartaVencedora(&vencedor, &valorAtributoCarta1, &valorAtributoCarta2, &opcaoCarta1, &opcaoCarta2, nomeCidade1, nomeCidade2, populacaoCidade1, populacaoCidade2, areaCidade1, areaCidade2, pibCidade1, pibCidade2, pontosTuristicosCidade1, pontosTuristicosCidade2, densidadePopulacionalCidade1, densidadePopulacionalCidade2);

    return 0;
}