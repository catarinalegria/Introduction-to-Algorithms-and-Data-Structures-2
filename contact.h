#ifndef CONTACT
#define CONTACT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*tamanho maximo que os nomes podem tomar (1023 caracteres + '/0')*/
#define MAX_NAME 1024
/*tamanho maximo que os mails podem tomar (511 caracteres + '/0')*/
#define MAX_MAIL 512
/*tamanho maximo que os contactos telemoveis podem tomar (63 caracteres + '/0')*/
#define MAX_PHONE 64
/*numero de dados que caracterizam o input dado (nome, contacto e email)*/
#define SIZE_CONTACTS 3
/*numero de componentes que caracterizam um email(parte local e dominio)*/
#define SIZE_MAIL 2
/*numero maximo de caracteres que o input fornecido pode tomar*/
#define MAX_INPUT 1598
/*tamanho das hashtables*/
#define SIZE 503
/*delimitador entre dados do input fornecido*/
#define DELIM1 " "
/*delimitador entre componentes do email fornecido*/
#define DELIM2 "@"

/*estrutura contact, caracterizada pelo seu nome,parte local do email(mail1),
dominio do email(mail2) e contacto telemovel (ponteiros para arrays de strings)*/
typedef struct Contact{
        char *name;
        char *mail1,*mail2; /*mail2=dominio*/
        char *phone;
}contact;

/*funcao que recebe um contacto e faz free de todas as componentes desse contacto;
nao retorna nada*/
void free_contact(contact * c);

/*funcao que recebe um nome, a parte local e o dominio de um email e um contacto
telemovel e retorna um ponteiro para o contacto constituido por essas componentes*/
contact *create_contact(char *name,char *mail1,char *mail2,char *phone);

#endif
