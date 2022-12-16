#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()

/*
    C Completo e Total
    Escrevendo em um arquivo de texto.
    Vamos mudar o modo 'a' para o modo 'w'
    * Vaja que acontece com o arquivo "arquivo_texto.txt" após
    executar repetidamente este exemplo.

*/

int main(void)
{
    FILE *fp;
    char ch;
    int err;

    /*
        O arquivo "arquivo_texto.txt" foi criado no exemplo anterior e, mesmo
        qie vazio, ele já existe. Então:
    */
    // abre um arquivo e texto para escrita
    fp = fopen("arquivo_texto.txt", "w");
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto

    // vamos guardar os caracteres digitados até o usuário digitar '$'
    do{
        ch = getchar();     // le do teclado
        fputc(ch, fp);      // escreve no arquivo
    }while(ch != '$');
    
    err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}