#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()
#include <string.h> // <- strcpy()

/*
    C Completo e Total
    Lendo de um arquivo csv

*/

// Armazenando as informações de um aluno
typedef struct
{
    int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
    char nome[100];   // nome com até 99 caracteres
    char email[100];  // eMail com até 99 caracteres
} TAluno;

int main(void)
{
    TAluno turma[200];
    FILE *fp;
    char str[80];
    int i = 0;
    
    fp = fopen("alunos.csv", "r");
    
    // Vamos abrir um arquivo para leitura e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    
    // pegando o cabeçalho
    char *ok; // se ok for NULL teve problema na leitura
    ok = fgets(str, 80, fp); // pega a string do arquivo 
    if(ok) // se ok != NULL (NULL é Falso, diferente de NULL verdadeiro)
        printf("%s", str);
    i = 0;
    while(!feof(fp)) // enquanto nâo chegar no final do arquivo
    {
        ok = fgets(str, 80, fp); // pega a string do arquivo 
        if(ok) // se ok != NULL (NULL é Falso, diferente de NULL verdadeiro)
        {
            char numMatricula[100];
            int j, pos;
            printf("%s", str);
            for(pos = 0; str[pos] != ','; pos++)
                numMatricula[pos] = str[pos];
            numMatricula[pos] = '\0';
            turma[i].numMatricula = atoi(numMatricula);
            for(j = 0, pos = pos + 1; str[pos] != ','; j++, pos++)
                turma[i].email[j] = str[pos];
            turma[i].email[j] = '\0';
            strcpy(turma[i].nome, &str[++pos]);
            j = strlen(turma[i].nome);
            turma[i].nome[j-1] = '\0'; // tiranfo o '\n' do final
            printf("%d,", turma[i].numMatricula);
            printf("%s,", turma[i].email);
            printf("%s\n", turma[i].nome);
            i++;
        }
    } 
    
    int err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}