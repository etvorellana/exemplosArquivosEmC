#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()

/*
    C Completo e Total
    Uma stream de texto é uma sequência da caracteres. O padrão 
    C ANSI permite que uma stream de texto seja organizada em 
    linhas terminadas por um caractere de nova linha. O caractere 
    de nova linha é opcional na última linha.   
*/

int main(void)
{
    /*
        Cada stream associada a um arquivo tem uma estrutura de 
        controle de arquivo do tipo FILE. Essa estrutura é 
        definida no cabeçalho stdio.h  
    */
    FILE *fp;
    /*
        A função fopen() (stdio.h) abre uma stream para uso e 
        associa um arquivo a ela. Ela retorna o ponteiro 
        associado a esse arquivo
            FILE *fopen(const char* nomeArq, const char* modo)
        onde nomeArq é um ponteiro para uma cadeia de caracteres 
        que forma um nome válido de arquivo e pode incluir uma 
        especificação de caminho de pesquisa (path). 
        A string apontada por modo determina como o arquivo será 
        abeto.
    */
    // Como guardar informação num arquivo?
    // abre um arquivo e texto para escrita
    fp = fopen("arquivo_texto.txt", "w");
    // abre um arquivo de texto já existente para anexar no final
    //fp = fopen("arquivo_texto.txt", "a");
    // abre um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "r+");
    // cria um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "w+");
    // abre um arquivo de texto já existente para ler e/ou anexar 
    // no final
    //fp = fopen("arquivo_texto.txt", "a+");
    
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    // A quantidade máxima de arquivos que pode ser aberto é definida por 
    printf("FOPEN_MAX = %d\n", FOPEN_MAX);

    /*
        A função fclose() fecha uma stream que foi aberta por meio 
        de uma chamada a fopen(). Ela escreve qualquer dado que 
        ainda permanecer no buffer de disco no arquivo e, então, 
        fecha normalmente o arquivo em nível de sistema operacional.
            int fclose(FILE *fp);
        A função retorna zero quando o arquivo foi corretamente fechado. 
        Qualquer valor diferente de zero indica um erro.
    */
    int err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}