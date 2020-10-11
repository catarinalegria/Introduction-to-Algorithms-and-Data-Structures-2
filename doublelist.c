#include "doublelist.h"


/*FUNCOES COMUNS A TODAS AS LISTAS*/
list *mk_list(){
      list *l=malloc(sizeof(list));

      l->head=l->tail=NULL;

      return l;
}

void free_node(link p){
      free_contact(p->c);
}

void freeList(list *l){
      link n=l->head;
      link aux = n;

      while(n != NULL){
        aux = n->next;
        free_node(n);
        free(n);
        n = aux;
      }

      free(aux);

      free(l);
}

/*FUNCOES QUE TRATAM DA LISTA COM OS CONTACTOS ORDENADOS*/

void removeList(list *l,link n){

      if(n->prev_l==NULL){
        if(n->next_l==NULL)
          l->tail=l->head=NULL;
        else {
          n->next_l->prev_l=NULL;
          l->head=n->next_l;
        }
      }
      else if(n->next_l==NULL){
          l->tail=n->prev_l;
          n->prev_l->next_l=NULL;
      }
      else{
          n->next_l->prev_l=n->prev_l;
          n->prev_l->next_l=n->next_l;
      }
}

void addList(list *l, link new){
      if(l->head==NULL){
        l->head=l->tail=new;
        new->next_l=new->prev_l=NULL;
      }
      else{
      new->prev_l=l->tail;
      new->next_l=NULL;
      l->tail->next_l=new;
      l->tail=new;
    }

}
