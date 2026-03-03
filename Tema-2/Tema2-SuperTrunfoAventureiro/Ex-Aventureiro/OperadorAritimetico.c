#include <stdio.h>

void lerDadosValores(int *n1, int *n2) {
    printf("Digite o primeiro numero: ");
    scanf("%d", n1);

    printf("Digite o segundo numero: ");
    scanf("%d", n2);
}

void calcularValores(int n1, int n2,
                     int *soma,
                     int *subtracao,
                     int *multiplicacao,
                     float *divisao) {

    *soma = n1 + n2;
    *subtracao = n1 - n2;
    *multiplicacao = n1 * n2;

    if (n2 != 0)
        *divisao = (float) n1 / n2;
    else
        *divisao = 0;  // evita divisão por zero
}

void exibirResultados(int soma, int sub, int mult, float div) {
    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", sub);
    printf("Multiplicacao: %d\n", mult);
    printf("Divisao: %.2f\n", div);
}

void operadoresDeAtribuicao(int n1, int n2) {

    int a = n1 += n2;  // 
    int b = n1 -= n2;  // 
    int c = n1 *= n2;  // 
    int d = n1 /= n2;  //

    printf("Resultado dos operadores de atribuicao:\n");
    printf("%d += %d: %d\n", n1, n2, a);
    printf("%d -= %d: %d\n", n1, n2, b);
    printf("%d *= %d: %d\n", n1, n2, c);
    printf("%d /= %d: %d\n", n1, n2, d);
}

int main() {
    int num1, num2;
    int soma, sub, mult;
    float div;

    lerDadosValores(&num1, &num2);

    calcularValores(num1, num2, &soma, &sub, &mult, &div);

    exibirResultados(soma, sub, mult, div);

    operadoresDeAtribuicao(num1, num2);

    return 0;
}
