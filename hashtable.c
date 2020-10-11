#include "hashtable.h"

/*FUNCOES COMUNS AS DUAS HASHTABLES*/

list** create_hash(){
        list** hash=malloc(sizeof(list*)*SIZE);
        int index;

        for (index=0;index<SIZE;index++){
            hash[index]=mk_list();
          }

        return hash;
}

link search(list *l, char* name){
      link aux=l->head;

      for(;aux!=NULL;aux=aux->next)
          if(!strcmp(name,aux->c->name))
              return aux;
      return NULL;
}


/*FUNCOES QUE TRATAM DA HASHTABLE DOS DOMINIOS*/


void freeHashDom(list **hash){
      int i;
      for(i=0;i<SIZE;i++)
          free(hash[i]);

      free(hash);
}

void removeHashDom(list *l,link n){
            if(n->prev_d==NULL){
              if(n->next_d==NULL)
                l->tail=l->head=NULL;
              else {
                n->next_d->prev_d=n->prev_d;
                l->head=n->next_d;
              }
            }
            else if(n->next_d==NULL){
                l->tail=n->prev_d;
                n->prev_d->next_d=n->next_d;
            }
            else{
                n->next_d->prev_d=n->prev_d;
                n->prev_d->next_d=n->next_d;
            }
      }


void addHashDom(list *l, link new){
      if(l->head==NULL){
        l->head=l->tail=new;
        new->next_d=new->prev_d=NULL;
      }
      else{
        new->prev_d=l->tail;
        new->next_d=NULL;
        l->tail->next_d=new;
        l->tail=new;
      }

    }

/*FUNCOES QUE TRATAM DA HASHTABLE DOS NOMES*/


void freeHashName(list **hash){
      int i;

      for(i=0;i<SIZE;i++)
          freeList(hash[i]);

      free(hash);
}


void removeHashName(list *l,link n){
          if(n->prev==NULL){
              if(n->next==NULL)
                  l->tail=l->head=NULL;
              else {
                  n->next->prev=n->prev;
                  l->head=n->next;
                }
              }
              else if(n->next==NULL){
                  l->tail=n->prev;
                  n->prev->next=n->next;
              }
              else{
                  n->next->prev=n->prev;
                  n->prev->next=n->next;
              }
        }


  link addHashName(list *l, contact* c){
        link n=malloc(sizeof(node));
        n->c=c;

        if(l->head==NULL){
            l->head=l->tail=n;
            n->next=n->prev=NULL;
            return n;
          }

        n->prev=l->tail;
        n->next=NULL;
        l->tail->next=n;
        l->tail=n;
        return n;
  }
