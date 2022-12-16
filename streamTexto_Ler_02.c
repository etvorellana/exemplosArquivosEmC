#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()

/*
    C Completo e Total
    Lendo de um arquivo de texto 

*/

int main(void)
{
    FILE *fp;
    char ch;
    
    fp = fopen("arquivo_texto.txt", "r");
    
    // Vamos abrir um arquivo para leitura e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    
    /*
        C inclui a função feof(), que determina quando o final do arquivo foi 
        atingido na leitura de dados. Esta função é muito útil para arquivos 
        binários, quando não conseguimos identificar o caractere EOF. 
            int feof(FILE *stream)
        Esta função retorna verdadeiro se o final do arquivo foi atingido. Ela
        pode ser utilizada tanto para arquivos binários quanto para arquivos
        de texto.
    */

    ch = fgetc(fp); // le um caractere do arquivo
    while(!feof(fp)) // enquanto nâo chegar no final do arquivo
    {
        putchar(ch); // imprime na tela
        ch = fgetc(fp);
    } 
    
    int err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}