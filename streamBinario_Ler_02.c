#include <stdio.h>
#include <stdlib.h>  // <- exit()
#define NALUNOS 100

/*
    C Completo e Total
    Lendo um array completo
*/

// Lendo as informações dos alunos
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int main(void)
{
    FILE *fp;
    char str[80];
    int err;
    TAluno turma[NALUNOS];
    int i = 0;
    // Como ler informação num arquivo binário?
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    fp = fopen("alunos_01.dat", "rb");
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto

    // lendo os alunos guardados no arquivo
    size_t ok;
    ok = fread(turma, sizeof(TAluno), NALUNOS, fp); // escreve no arquivo
    if (ok != NALUNOS)
        printf("Problemas na leitura");
    else
        for(i = 0; i < NALUNOS; i++)
        {
            printf("%d,", turma[i].numMatricula);
            printf("%s,", turma[i].email);
            printf("%s\n", turma[i].nome);
        }
    return 0;
}