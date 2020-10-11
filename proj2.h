#ifndef PROJ2
#define PROJ2

#include "auxs.h"


/*funcao que adiciona um contacto as duas hashtables e, ordenadamente, a uma lista;
recebe como parametro a hashtable dos nomes, a hashtable dos dominio, e a lista ordenada;
nao retorna nada*/
void addContact(list **hashNames, list **hashDom, list *list);

/*funcao que recebe a lista ordenada e imprime, pela ordem em que foram inseridos,
todos os contactos adicionados; nao retorna nada*/
void listContacts(list *list);

/*funcao que procura um contacto na hashtable dos nomes, imprimindo esse contacto
caso exista; recebe como parametro a hashtable dos nomes; nao retorna nada*/
void searchContact(list **hashNames);

/*funcao responsavel por alterar o email de um contacto; recebe como argumentos
a hashtable dos nomes e a hastable dos dominios; nao retorna nada*/
void changeMail(list **hashNames,list **hashDom);

/*funcao responsavel por contar o numero de ocorrencias de um dado dominio; recebe
como argumentos a hashtable dos dominios; nao retorna nada*/
void countMail(list **hashDom);

/*funcao responsavel por apagar um contacto; recebe como argumentos as duas
hashtables e a lista ordenada; nao retorna nada*/
void deleteContact(list **hashNames,list **hashDom, list *l);

#endif
