#include <stdio.h>
#include <stdlib.h>  // <- random()
#define NALUNOS 100

/*
    C Completo e Total
    Agora vamos copiar o array de uma vez
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
    TAluno turma[NALUNOS]; 
    // Como guardar informação num arquivo binário?
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    fp = fopen("alunos_02.dat", "wb");
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto

    // gerando os alunos e guardando em um array
    for(int i = 0; i < NALUNOS; i++)
        geraAluno(&turma[i], 2000, 2022); // gera um aluno novo
       
    size_t ok;
    ok = fwrite(turma, sizeof(TAluno), NALUNOS, fp); // escreve no arquivo
    if (ok != NALUNOS)
        printf("Problemas na escrita");
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