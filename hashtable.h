#ifndef HASHTABLE
#define HASHTABLE

#include "doublelist.h"

/*funcao responsavel por criar e inicializar as listas da hshtable, retornando-a*/
list**create_hash();

/*funcao que recebe uma lista e um nome;procura na lista o no no qual o contacto
apresenta esse nome, retornando um ponteiro para esse no; se nao encontrar nenhum
no a que corresponda esse nome, a funcao retorna NULL*/
link search(list *list, char* name);

/*funcao que recebe uma hashtable e e responsavel por dar free a todas as listas
dessa hashtable; nao retorna nada*/
void freeHashDom(list **hash);

/*funcao que recebe um ponteiro para uma lista e um ponteiro para um no,
removendo esse no da lista fornecida; nao retorna nada */
void removeHashDom(list *list,link node);

/*funcao que recebe um ponteiro para uma lista e para um no e adiciona esse no
no final da lista fornecida; nao retorna nada*/
void addHashDom(list *list,link node);

/*funcao que recebe uma hashtable e e responsavel por dar free a todas as listas
dessa hashtabel, recoreendo a funcao freeList; nao retorna nada*/
void freeHashName(list **hash);

/*funcao que recebe um ponteiro para uma lista e um ponteiro para um no e remove
esse no da lista dada; nao retorna nada;*/
void removeHashName(list *list,link node);

/*funcao que recebe um ponteiro para uma lista e um ponteiro para um contacto;
cria um no com esse contacto e insere-o no final da lista fornecida; retorna
um ponteiro para o no criado*/
link addHashName(list *list,contact *c);

#endif
