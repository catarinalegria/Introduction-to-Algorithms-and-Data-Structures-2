/*
 * File:  proj2.c
 * Author:  Catarina Alegria
 * Description: projeto 2
*/

#include "proj2.h"

/*FUNCOES DOS COMANDOS E FUNCAO MAIN*/

void addContact(list **hashNames, list **hashDom, list *l){
          char input[MAX_INPUT],inf[SIZE_CONTACTS][MAX_NAME];
          char mail[SIZE_MAIL][MAX_MAIL];
          int index1,index2;
          contact* data;
          link new,aux;

          read_input(input);
          separate_string(input,inf);
          separate_mail(inf[1],mail);

          /*cria uma estrutua contacto relativa a informacao recebida*/
          data=create_contact(inf[0],mail[0],mail[1],inf[2]);

          /*indice na hashtable dos nomes onde o contacto se encontra*/
          index1=key_hash(data->name,SIZE);
          /*indice na hashtable dos contactos onde o contacto se encontra*/
          index2=key_hash(data->mail2,SIZE);

          aux=search(hashNames[index1],data->name);

          if (aux==NULL){
              /*cria o no com esse contacto, adiciona-o a hashtable dos nomes e retorna-o*/
              new=addHashName(hashNames[index1],data);

              /*adiciona esse mesmo no a hashtable dos dominios e a lista ordenada*/
              addList(l,new);
              addHashDom(hashDom[index2],new);
              return;
          }

          free_contact(data);
          printf("Nome existente.\n");

}

void listContacts(list *l){
      link aux;

      for(aux=l->head;aux!=NULL;aux=aux->next_l)
          printf("%s %s@%s %s\n",aux->c->name, aux->c->mail1,aux->c->mail2,aux->c->phone);
}

void searchContact(list **hash){
      char name[MAX_NAME];
      link aux;
      int index;

      scanf("%s",name);
      /*getchar do \n */
      getchar();

      /*indice na hashtable dos nomes onde o contacto se encontra*/
      index=key_hash(name,SIZE);

      if(hash[index]==NULL || hash[index]->head==NULL){
        printf("Nome inexistente.\n");
        return;
      }

      aux=search(hash[index],name);

      if (aux!=NULL){
              printf("%s %s@%s %s\n",aux->c->name, aux->c->mail1,aux->c->mail2,aux->c->phone);
              return;
          }

      printf("Nome inexistente.\n");
}

void changeMail(list **hashNames,list **hashDom){
      char informations[SIZE_MAIL][MAX_NAME],input[MAX_INPUT];
      char mail[SIZE_MAIL][MAX_MAIL];
      char *name,*mail1,*mail2,*domain;
      link aux;
      int index,index1,index2;

      read_input(input);

      separate_string(input,informations);
      name=informations[0];

      /*indice na hashtable dos nomes onde o contacto se encontra*/
      index=key_hash(name,SIZE);

      if(hashNames[index]==NULL || hashNames[index]->head==NULL){
        printf("Nome inexistente.\n");
        return;
      }

      separate_mail(informations[1],mail);
      mail1=mail[0];
      /*novo dominio*/
      mail2=mail[1];

      aux=search(hashNames[index],name);

      if(aux!=NULL){
        /*indice da hashtable dos dominios onde o contacto se encontra antes do
        email ser alterado*/
        index1=key_hash(aux->c->mail2,SIZE);
        /*dominio antigo*/
        domain=aux->c->mail2;

        change(aux,mail1,mail2);
      }
      else{
          printf("Nome inexistente.\n");
          return;
        }

        /*indice da hashtable dos dominios onde o contacto se encontra apos o
        email ser alterado*/
        index2=key_hash(mail2,SIZE);

        if (domain!=mail2){
            removeHashDom(hashDom[index1],aux);
            addHashDom(hashDom[index2],aux);
        }
}

void countMail(list **hash){
      char dominio[MAX_MAIL];
      int index,cont=0;
      link aux;

      scanf("%s",dominio);
      /*getchar do \n */
      getchar();

      /*indice na hashtable dos dominios onde o contacto se encontra*/
      index=key_hash(dominio,SIZE);

      if(hash[index]==NULL){
        printf("%s:%d\n",dominio,cont);
        return;
      }

      aux=hash[index]->head;

      /*percorre a lista da hashtable dos dominios onde o dominio fornecido esta presente*/
      for(;aux!=NULL;aux=aux->next_d){
          if(!strcmp(dominio,aux->c->mail2))
            cont++;
        }

      printf("%s:%d\n",dominio,cont);

}

void deleteContact(list **hashNames,list **hashDom, list *l){
      char name[MAX_NAME];
      link aux;
      int index1, index2;

      scanf("%s",name);
      /*getchar do \n*/
      getchar();

      /*indice na hashtable dos nomes onde o contacto se encontra*/
      index1=key_hash(name,SIZE);

      if(hashNames[index1]==NULL || hashNames[index1]->head==NULL){
        printf("Nome inexistente.\n");
        return;
      }

      aux=search(hashNames[index1],name);

      if (aux!=NULL){
          /*indice na hashtable dos dominios onde o contacto se encontra*/
          index2=key_hash(aux->c->mail2,SIZE);
          /*remove o contacto das duas hashtavles e da lista ordenada*/
          removeHashName(hashNames[index1],aux);
          removeList(l,aux);
          removeHashDom(hashDom[index2],aux);

          free_node(aux);
          free(aux);
          return;
        }

      printf("Nome inexistente.\n");
    }


int main() {
    /*variavel que contem a letra do comando que o utilizador prentende executar*/
    char command;

    /*hashtable onde os indices sao calculados atraves do nome do contacto*/
    list **hashNames=create_hash();
    /*hashtable onde os indices sao calculados atraves do dominio do contacto*/
    list **hashDom=create_hash();
    /*lista duplamente ligada onde os contactos apresentam-se ordenados pela
    ordem em que foram introduzidos*/
    list *l=mk_list();


    while(1){
        command=getchar();
        getchar();

        switch (command) {
          case 'a':
                addContact(hashNames,hashDom,l);
                break;
          case 'l':
                listContacts(l);
                break;
          case 'p':
                searchContact(hashNames);
                break;
          case 'r':
                deleteContact(hashNames,hashDom,l);
                break;
          case 'e':
                changeMail(hashNames,hashDom);
                break;
          case 'c':
                countMail(hashDom);
                break;
          case 'x':
                /*antes de terminar o programa, faz se free das duas hashtables
                e da lista*/
                free(l);
                freeHashDom(hashDom);
                freeHashName(hashNames);
                return 0;
        }
      }

      return 0;
}
