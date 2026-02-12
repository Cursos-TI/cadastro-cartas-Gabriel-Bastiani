#include <stdio.h>
#include <string.h>

int CadAluno()
    {
        // código para cadastrar aluno
        /*criando um programa em C que gerencia o cadastro de alunos em uma turma.
         Utilizaremos variáveis para armazenar informações como nome, idade e matrícula dos alunos.*/

        char nome[50];
        int idade;
        int matricula;

        // perguntar os dados
        printf("Digite o nome do aluno: ");
        fgets(nome, sizeof(nome), stdin); // nome com espaço
        
        nome[strcspn(nome, "\n")] = '\0';
        
        printf("Digite a idade do aluno: ");
        scanf("%d", &idade);
        

        printf("Digite a matrícula do aluno: ");
        scanf("%d", &matricula);
        
        //printf para exibir os dados cadastrados
        printf("Aluno cadastrado:\n Nome: %s\n Idade: %d\n Matrícula: %d\n", nome, idade, matricula);

        return 0;
    }

int main()
{
    CadAluno();
    return 0;
}