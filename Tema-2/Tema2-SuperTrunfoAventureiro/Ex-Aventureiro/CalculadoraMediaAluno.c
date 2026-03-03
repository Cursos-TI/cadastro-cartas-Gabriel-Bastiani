#include <stdio.h>

//calcula a média de três notas inseridas pelo usuário
//Utilizaremos variáveis para armazenar as notas, operadores matemáticos para somar e calcular a média, e operadores de atribuição para atualizar valores.

void lerNotas(float *nota1, float *nota2, float *nota3) {
    printf("Digite a primeira nota: ");
    scanf("%f", nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", nota3);
}

void calcularMedia(float nota1, float nota2, float nota3, float *media) {
    float soma = nota1 += nota2 += nota3;

    *media = (soma / 3); //Nao precisa de casting pois todas as variáveis são do tipo float
}


int main(){
    float nota1, nota2, nota3, media;

    lerNotas(&nota1, &nota2, &nota3);

    calcularMedia(nota1, nota2, nota3, &media);

    printf("A média é: %.2f\n", media);

    return 0;
}