#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int llnode_add_to_head(llnode **x,char value){
   llnode *p = NULL;
   if (x==NULL){
      return -1;
   }
   p = *x;
   *x = (llnode*) malloc(sizeof(llnode));
   (*x)->value = value;
   (*x)->next = p;
      return 0;
}

int push(llnode **x, char value){
   if (x==NULL){
      return -1;
   }
   llnode_add_to_tail(x,value);
   return 0;
}

int pop(llnode **x, char *return_value){
   llnode *p;
   if (x==NULL){
      return -1;
   }
   p = *x;
   while((p->next)->next!= NULL){
      p = p->next;
   }
   *return_value = (p->next)->value;
   p->next = NULL;
   return 0;
}
int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
         return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
         return 0;
      }
   }
}

int main(void) {
   int n=0;
   int testpop = 0;
   char value=0;
   char rvalue=0;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      push(&input_list,value);
   }
   printf("INFO: you entered %d items\n",n);
   testpop = pop(&input_list,&rvalue);
   testpop = pop(&input_list,&rvalue);
  /* if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }*/
   printf("return value is %c\n",rvalue);
   return 0;
}

