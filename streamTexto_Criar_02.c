#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()

/*
    C Completo e Total
    Escrevendo em um arquivo de texto.
    * Vaja que acontece com o arquivo "arquivo_texto.txt" após
    executar repetidamente este exemplo.
    * O caractere '$' está aparecendo no arquivo. Como não incluir ele no 
    arquivo? 
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
    // abre um arquivo de texto já existente para anexar no final
    fp = fopen("arquivo_texto.txt", "a");
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    
    /*
        O padrão C ANSI define duas funções equivalentes para escrever
        caracteres: putc() e fputc(). Vamos utilizar a fputc()
            int fputc(int char, FILE *stream)
        A função fputc() escreve um caractere em um arquivo que foi previamente 
        aberto para escrita. Por razões históricas o caractere é definido com
        um int mas apenas byte menos significativo é utilizado.
        Se a operação for bem sucedida a função retorna o caractere que foi
        escrito. Caso contrário, retorna o caractere EOF definido na stdio.h
    */

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