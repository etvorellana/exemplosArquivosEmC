#include <stdio.h>
#include <stdlib.h>  // <- exit()
#define NALUNOS 100

/*
    C Completo e Total
    Uma stream binária é uma sequência de bytes com uma correspondência de um
    para um com aqueles encontrados no dispositivo externo -  isto é, não 
    ocorre nenhuma tradução de caracteres.   

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
    // abre um arquivo binário para leitura
    fp = fopen("alunos_01.dat", "rb");
    // abre um arquivo binário para leitura e escrita
    //fp = fopen(alunos_01.dat", "rb+");
    // cria um arquivo e texto para leitura e escrita
    //fp = fopen(alunos_01.dat", "wb+");
    // abre um arquivo de texto já existente para ler e/ou anexar no final
    //fp = fopen(alunos_01.dat", "ab+");
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    /*
        Quando um arquivo é aberto para dados binários a função fread() pode 
        ler qualquer tipo de informação.
            size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
        onde ptr representa o endereço de memória onde a informação será 
        copiada, sb é o tamanho em bytes de cada elemento e nb a quantidade de 
        elementos que serão lidos. A função retorna a quantidade de 
        elementos que foram efetivamente lidos. Se tudo o processo for bem
        sucedido o retorno da função tem que ser igual que nb.
    */

    // lendo os alunos guardados no arquivo
    for(i = 0; i < NALUNOS; i++)
    {
        size_t ok;
        ok = fread(&turma[i], sizeof(TAluno), 1, fp); // escreve no arquivo
        if (ok != 1)
            printf("Problemas na leitura");
        else
        {
            printf("%d,", turma[i].numMatricula);
            printf("%s,", turma[i].email);
            printf("%s\n", turma[i].nome);
        }
    }
    
    return 0;
}