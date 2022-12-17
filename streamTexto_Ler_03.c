#include <stdio.h>  // <- printf(), fopen(), fclose(), ...
#include <stdlib.h> // <- exit()

/*
    C Completo e Total
    Lendo de um arquivo de texto com fegts()

*/

int main(void)
{
    FILE *fp;
    char str[80];
    
    fp = fopen("arquivo_texto.txt", "r");
    
    // Vamos abrir um arquivo para leitura e verificar se foi tudo bem
    if(fp == NULL) // Ponteiro nulo significa problemas na abertura do arquivo
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    // Se chegamos até aqui é porque o arquivo está aberto
    
    /*
        Já utilizamos a função fgets() para ler strings da entrada padrão.
        Entretanto, esta função pode ser utilizada para ler diretamente 
        uma string no arquivo. 
            char *fgets(char *str, int n, FILE *stream)
        Esta função lê uma string da stream especificada até que um caractere 
        nova linha é lida, ela será parte da string. A string final incluirá 
        o caractere '\0' no final. A função retorna um ponteiro para a string
        se for bem sucedida e NULL se ocorrer algum erro.  
    */

    while(!feof(fp)) // enquanto nâo chegar no final do arquivo
    {
        char *ok; // se ok for NULL teve problema na leitura
        ok = fgets(str, 80, fp); // pega a string do arquivo 
        if(ok) // se ok != NULL (NULL é Falso, diferente de NULL verdadeiro)
            printf("%s", str);
    } 
    
    int err = fclose(fp);
    if (err) // err != 0
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    return 0;
}