#ifndef DOUBLELIST
#define DOUBLELIST

#include "contact.h"

/*estrutura no, caracterizada por outros 6 ponteiros para nos(cada par
(prev e next) pertencente a uma das duas hashtables ou a lista ordenada)e um
ponteiro para um contacto*/
struct Node {

      	struct Node *next,*prev;         /*ponteiros das listas ligadas da hashtable dos nomes*/
        struct Node *next_l,*prev_l;     /*ponteiros da lista de contactos ordenada*/
        struct Node *next_d,*prev_d;     /*ponteiros das listas ligadas da hashtable dos dominios*/
      	contact *c;
};
typedef struct Node node;
typedef struct Node* link;

/*estrutura lista, composta por 2 ponteiros para nos, a head e a tail, que apontam,
respetivamente, para o primeiro e ultimo elemento de uma lista*/
typedef struct List {
        node *  head, * tail;
}list;

/*funcao responsavel por criar e retornar uma lista, inicializando a sua
head e tail a NULL,*/
list *mk_list();

/*funcao que recebe um ponteiro para um no, fazendo primeiro free do contacto
presente nesse no e depois do no; nao retorna nada*/
void free_node(link node);

/*funcao que recebe um ponteiro para uma lista e e responsavel por fazer free
de todos os nos presentes nessa lista e depois da lista em si; nao retorna nada*/
void freeList(list *list);


/*funcao que recebe um ponteiro para a lista que contem os contactos ordenados
e um ponteiro para um no e remove esse no da lista; nao retorna nada*/
void removeList(list *list,link node);
void addList(list *list,link node);

#endif
