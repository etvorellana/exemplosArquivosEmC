#include <stdio.h>

/*
    C Completo e Total
    Uma stream binária é uma sequência de bytes com uma correspondência de um
    para um com aqueles encontrados no dispositivo externo -  isto é, não 
    ocorre nenhuma tradução de caracteres.   

*/

int main(void)
{
    FILE *fp;
    // Como guardar informação num arquivo binário?
    // abre um arquivo e texto para escrita
    fp = fopen("arquivo_texto.txt", "wb");
    // abre um arquivo de texto já existente para anexar no final
    //fp = fopen("arquivo_texto.txt", "ab");
    // abre um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "rb+");
    // cria um arquivo e texto para leitura e escrita
    //fp = fopen("arquivo_texto.txt", "wb+");
    // abre um arquivo de texto já existente para ler e/ou anexar no final
    //fp = fopen("arquivo_texto.txt", "ab+");
    // Vamos abrir um arquivo para escrita e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    /*
        Quando um arquivo é aberto para 
    */

    
    return 0;
}