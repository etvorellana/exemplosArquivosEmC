#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()
#include <string.h> // <- strcat()

#define NALUNOS 100

/*
    C Completo e Total
    criando um arquivo CSV com dados de alunos
*/ 

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

// gera dados de alunos de forma aleatória
void geraAluno(TAluno *aluno, int anoIni, int anoFim);

int main(void)
{
    FILE *fp;
    char str[80];
    int err;
    TAluno aluno;
    int i = 0;

    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    fp = fopen("alunos.csv", "w");
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto

    // Colocando o cabeçalho do csv
    fputs("Matricula, eMail, Nome\n", fp);
    
    // gerando os alunos e guardando no arquivo
    do
    {
        geraAluno(&aluno, 2000, 2022); // gera um aluno novo
        // coloca os dados do aluno numa string formatada
        sprintf(str, "%i,%s,%s\n", aluno.numMatricula, aluno.email, aluno.nome);
        fputs(str, fp);     // escreve no arquivo
    } while (++i < NALUNOS); // Ate completar NALUNOS 
    
    err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}

void geraAluno(TAluno *aluno, int anoIni, int anoFim)
{
    int dif = anoFim - anoIni;
    // Ano anoIni a anoFim * 100000
    aluno->numMatricula = (2000 + (random() % dif)) * 100000;
    // Semestre 1 a 2 * 10000, ex. 20aas0000
    aluno->numMatricula += ((random() % 2) + 1) * 10000;
    // Numero sequencial 1 a 999, ex. 20aasxxxx
    aluno->numMatricula += (random() % 999) + 1;
    sprintf(aluno->email, "%d@uesc.br", aluno->numMatricula);
    sprintf(aluno->nome, "Aluno_%d", aluno->numMatricula);
}