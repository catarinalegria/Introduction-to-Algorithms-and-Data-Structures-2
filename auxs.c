#include "auxs.h"

/*FUNCOES AUXILIXARES UTILIZADAS NO PROGRAMA*/

void read_input(char input[MAX_INPUT]){
      char c;
      int i;

      c=getchar();
      for (i=0;c!='\n' && c!=EOF;i++){
          input[i]=c;
          c=getchar();
      }
      input[i]=0;
}

void  separate_string(char input[MAX_INPUT],char new[SIZE_CONTACTS][MAX_NAME]){
      int i=0;
      char* p;

      for (p = strtok(input,DELIM1); p != NULL; p = strtok(NULL,DELIM1))
            strcpy(new[i++],p);
}

void  separate_mail(char input[MAX_INPUT],char new[SIZE_MAIL][MAX_MAIL]){
      int i=0;
      char* p;

      for (p = strtok(input,DELIM2); p != NULL; p = strtok(NULL,DELIM2))
            strcpy(new[i++],p);
}

unsigned long key_hash(const char *string, unsigned long m){
           unsigned long h, a = 31415, b = 27183;

           for (h = 0; *string != '\0'; string++, a = a*b % (m-1))
                h = (a*h + *string) % m;

           return h;
}

void change(link n, char* mail1, char* mail2){
      /*realoca dinamicamente memoria para o novo email fornecido*/
      n->c->mail1=realloc(n->c->mail1,sizeof(char)*(strlen(mail1)+1));
      n->c->mail2=realloc(n->c->mail2,sizeof(char)*(strlen(mail2)+1));
      strcpy(n->c->mail1,mail1);
      strcpy(n->c->mail2,mail2);

}
