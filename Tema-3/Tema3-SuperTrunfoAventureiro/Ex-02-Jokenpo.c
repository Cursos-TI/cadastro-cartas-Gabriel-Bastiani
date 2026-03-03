#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

int main(){
    int opcao, opcaoComputador;

    printf("===============================\n");
    printf("\nBem-vindo ao Jokenpô!\n");
    printf("===============================\n");
    
    printf("\nEscolha uma opção:\n");
    printf("0 - Pedra\n");
    printf("1 - Papel\n");
    printf("2 - Tesoura\n");
    printf("\nDigite a sua opção: ");
    scanf("%d", &opcao);

    // Gerar um número aleatório entre 0 e 2 para o computador
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    opcaoComputador = rand() % 3; // Gera um número entre 0 e 2

    printf("\nVocê escolheu: %d" , opcao);
    
    if(opcaoComputador == 0){
        printf("\nO computador escolheu: 0 - Pedra");
    } else if(opcaoComputador == 1){
        printf("\nO computador escolheu: 1 - Papel");
    } else {
        printf("\nO computador escolheu: 2 - Tesoura");
    }

    
    switch (opcao)
    {
    case 0:
        if(opcaoComputador == 0){
            printf("\nEmpate! O computador também escolheu Pedra.");
        } else if(opcaoComputador == 1){
            printf("\nVocê perdeu! O computador escolheu Papel.");
        } else {
            printf("\nVocê ganhou! O computador escolheu Tesoura.");
        }
        break;
    case 1:
        if(opcaoComputador == 0){
            printf("\nVocê ganhou! O computador escolheu Pedra.");
        } else if(opcaoComputador == 1){
            printf("\nEmpate! O computador também escolheu Papel.");
        } else {
            printf("\nVocê perdeu! O computador escolheu Tesoura.");
        }
        break;
    case 2:
        if(opcaoComputador == 0){
            printf("\nVocê perdeu! O computador escolheu Pedra.");
        } else if(opcaoComputador == 1){
            printf("\nVocê ganhou! O computador escolheu Papel.");
        } else {
            printf("\nEmpate! O computador também escolheu Tesoura.");
        }
        break;
    
    default:
        printf("\nOpção inválida! Por favor, escolha 0, 1 ou 2.");
        break;
    }



}

