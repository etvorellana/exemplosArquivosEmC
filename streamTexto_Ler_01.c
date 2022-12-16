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
    
    // Como pegar informação de um arquivo?
    // abre um arquivo e texto para leitura
    fp = fopen("arquivo_texto.txt", "r");
    // abre um arquivo de texto já existente para anexar no final
    //fp = fopen("arquivo_texto.txt", "a");
    // abre um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "r+");
    // cria um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "w+");
    // abre um arquivo de texto já existente para ler e/ou anexar no final
    //fp = fopen("arquivo_texto.txt", "a+");
    
    // Vamos abrir um arquivo para leitura e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    
    /*
        O padrão C ANSI define duas funções equivalentes para leitura de
        caracteres: getc() e fgetc(). Vamos utilizar a fputc()
            int fgetc(FILE *stream)
        A função fgetc() pega um caractere em um arquivo que foi previamente 
        aberto para leitura. Por razões históricas a função retorna um int
        mas o byte mais significativo é zero.
        A função fgetc() retorna EOF quando o final do arquivo for alcançado. 
    */

    ch = fgetc(fp); // le um caractere do arquivo
    while(ch != EOF)
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