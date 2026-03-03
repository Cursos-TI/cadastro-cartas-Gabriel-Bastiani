#include <stdio.h>
#include <string.h>

int main()
{

    int idade = 18;
    int resultado;

    // operador ternario
    // variavel mais condicao ? valor_se_verdadeiro : valor_se_falso
    resultado = idade >= 18 ? 1 : 0;

    resultado == 1 ? printf("Maior de idade\n") : printf("Menor de idade\n");

    
}