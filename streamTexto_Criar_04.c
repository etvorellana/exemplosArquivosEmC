#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()
#include <string.h> // <- strcat()

/*
    C Completo e Total
    Escrevendo em um arquivo de texto.
    Escrevendo strings

*/

int main(void)
{
    FILE *fp;
    char str[80];
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

    /*
        Já utilizamos a função fputs() para escrever strings da entrada padrão.
        Entretanto, esta função pode ser utilizada para escrever diretamente 
        uma string no arquivo. 
            int fputs(const char *str, FILE *stream)
        Esta função escreve na stream especificada e retorna EOF se acontecer 
        algum problema durante a escrita.
    */

    do
    {
        printf("Digite uma string (CR para sair): ");
        fgets(str, 80, stdin); // pega da entrada padrão
        fputs(str, fp);     // escreve no arquivo
    } while (*str != '\n'); // até encontrar '\n' no início da string
    
    err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}