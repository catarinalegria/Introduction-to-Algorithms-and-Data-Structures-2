#include "contact.h"

void free_contact(contact *c){
      free(c->name);
      free(c->mail1);
      free(c->mail2);
      free(c->phone);
      free(c);
}


contact *create_contact(char *name,char *mail1,char *mail2,char *phone){
          contact *p_contact=(contact*)malloc(sizeof(contact));

          p_contact->name=(char*)malloc(sizeof(char)*(strlen(name)+1));
          strcpy(p_contact->name,name);

          p_contact->mail1=(char*)malloc(sizeof(char)*(strlen(mail1)+1));
          strcpy(p_contact->mail1,mail1);

          p_contact->mail2=(char*)malloc(sizeof(char)*(strlen(mail2)+1));
          strcpy(p_contact->mail2,mail2);

          p_contact->phone=(char*)malloc(sizeof(char)*(strlen(phone)+1));
          strcpy(p_contact->phone,phone);

          return p_contact;
}
