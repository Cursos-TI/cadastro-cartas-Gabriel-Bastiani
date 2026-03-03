#include <stdio.h>

int main()
{

    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";

    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;

    float valorA = 10.50;
    float valorB = 20.40;

    unsigned int estoqueMinimoA = 500;
    unsigned int estoqueMinimoB = 2500;

    double valorTotalA;
    double valorTotalB;

    int resultadoA;
    int resultadoB;

    //exibir as informações dos produtos
    printf("Produto: %s tem estoque de %u unidades e o valor unitário é R$ %.2f\n", produtoA, estoqueA, valorA);
    printf("Produto: %s tem estoque de %u unidades e o valor unitário é R$ %.2f\n", produtoB, estoqueB, valorB);

    //comparações com o valor minimo de estoque
    resultadoA = estoqueA > estoqueMinimoA;
    resultadoB = estoqueB > estoqueMinimoB;

    //sem usar if, para exibir o resultado da comparação
    printf("O prudto %s tem estoque mínimo %d\n", produtoA, resultadoA);
    printf("O prudto %s tem estoque mínimo %d\n", produtoB, resultadoB);

    //comparação entre os valores totais dos produtos
    printf("O valor total do estoque do %s é R$ %.2f é maior que o valor total do estoque do que %s que é R$ %.2f? %d\n", 
        produtoA, valorTotalA = estoqueA * valorA, produtoB, valorTotalB = estoqueB * valorB, valorTotalA > valorTotalB);
  
}