#include <stdio.h>
#include <stdlib.h>  // <- random()
#define NALUNOS 100

/*
    C Completo e Total
    Uma stream binária é uma sequência de bytes com uma correspondência de um
    para um com aqueles encontrados no dispositivo externo -  isto é, não 
    ocorre nenhuma tradução de caracteres.   

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
    // Como guardar informação num arquivo binário?
    // abre um arquivo binário para escrita
    fp = fopen("alunos_01.dat", "wb");
    // abre um arquivo binário já existente para anexar no final
    //fp = fopen("alunos_01.dat", "ab");
    // abre um arquivo binário para leitura e escrita
    //fp = fopen("alunos_01.dat", "rb+");
    // cria um arquivo binário para leitura e escrita
    //fp = fopen("alunos_01.dat", "wb+");
    // abre um arquivo binário já existente para ler e/ou anexar no final
    //fp = fopen("alunos_01.dat", "ab+");
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    /*
        Quando um arquivo é aberto para dados binários a função fwrite() pode 
        escrever qualquer tipo de informação.
            size_t fwrite(const void *ptr, size_t sb, size_t nb, FILE *stream)
        onde ptr representa o endereço de memória da informação que se deseja
        copiar, sb é o tamanho em bytes de cada elemento e nb a quantidade de 
        elementos que serão copiados. A função retorna a quantidade de 
        elementos que foram efetivamente copiados. Se tudo o processo for bem
        sucedido o retorno da função tem que ser igual que nb.
    */

    // gerando os alunos e guardando no arquivo
    do
    {
        size_t ok;
        geraAluno(&aluno, 2000, 2022); // gera um aluno novo
        ok = fwrite(&aluno, sizeof(TAluno), 1, fp); // escreve no arquivo
        if (ok != 1)
            printf("Problemas na escrita");
    } while (++i < NALUNOS); // Ate completar NALUNOS 

    
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