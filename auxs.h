#ifndef AUXS
#define AUXS

#include "hashtable.h"

/*funcao que recebe input e coloca-o num array*/
void read_input(char input[MAX_INPUT]);

/*funcao que separa em blocos a informacao da string fornecida, sendo o
caracter ' ' o delimitador entre os varios blocos; recebe como argumentos
a string que se pretende separar e a string onde se coloca a string separada*/
void  separate_string(char input[MAX_INPUT],char new[SIZE_CONTACTS][MAX_NAME]);

/*funcao que separa em blocos a informacao da string fornecida, sendo o
caracter '@' o delimitador entre os varios blocos; recebe como argumentos
a string que se pretende separar e a string onde se coloca a string separada*/
void  separate_mail(char input[MAX_INPUT],char new[SIZE_MAIL][MAX_MAIL]);

/*funcao que retorna um inteiro, correspondente a um indice da hashtable; recebe
uma string e o tamanho da hashtable, calculando o indice para essa string*/
unsigned long key_hash(const char *string, unsigned long m);

/*funcao que recebe um link para um no, a parte local e o dominio de um email;
realoca memoria para a nova informacao recebida e copia para o contacto presente
nesse no a nova parte local e o novo dominio; nao retorna nada*/
void change(link node, char* mail1, char* mail2);

#endif
