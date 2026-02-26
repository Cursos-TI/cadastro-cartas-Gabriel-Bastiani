#include <stdio.h>

int main(){

int a, b, c;

printf("Digite o valor 1: ");
scanf("%d", &a); 

printf("Digite o valor 2: ");
scanf("%d", &b); 

c = a + b;

float fa = 10.55;



printf("O resultado da soma do valor 1: %d mais o valor 2: %d é: %d e o valor de fa é: %.2f\n", a, b, c, fa);

// operadores de comparação
/*
&&, ||,  !
*/

//>,<, >=, <=, ==, !=
//a = 10 b = 10

if(a > b){//0
    printf("O valor de a é maior que o valor de b\n");
} else if(a < b){//1 
    printf("O valor de a é menor que o valor de b\n");
} else if(a == b){//0
    printf("========================================\n");
    printf("O valor de 'A' é igual ao valor de 'B'\n");
}
}
    