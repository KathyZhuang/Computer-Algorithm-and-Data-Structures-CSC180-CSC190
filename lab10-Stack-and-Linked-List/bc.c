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
   if (*x == NULL){
      return 2;
   }
   llnode_add_to_tail(x,value);
   return 0;
}

int pop(llnode **x, char *return_value){
   llnode *p;
   if (x==NULL){
      return -1;
   }
   if (*x == NULL){
      return 2;
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
   int testpush = 22;
   int testpop = 11;
   int hasFailed = 12;
   char value=0;
   char rvalue=0;
   llnode *input_list = NULL;
   input_list = (llnode *)malloc(sizeof(llnode *));
   int canPass = 1;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      if(value == '('||value == '{'||value == '['){
         testpush =  push(&input_list,value);
      }
      if(value == ']'){
         testpop = pop(&input_list,&rvalue);
         if(testpop != 0){
            break;
         }
         else{
            if(rvalue !='['){
               printf("FAIL\n,%d",n);
               hasFailed = 0;
               break;
            }
         }
      }
      if(value == ')'){
         testpop = pop(&input_list,&rvalue);
         if(testpop != 0){
            break;
         }
         else{
            if(rvalue !='('){
               printf("FAIL,%d\n",n);
               hasFailed = 1;
               break;
            }
         }
      }
      if(value == '}'){
         testpop = pop(&input_list,&rvalue);
         if(testpop != 0){
            break;
         }
         else{
            if(rvalue !='{'){
               printf("FAIL,%d\n",n);
               hasFailed = 2;
               break;
            }
         }
      }
   }
 //  pop(&input_list,&rvalue);
  /* if(rvalue != ' '){
      printf("FAIL,%d\n",n);
      return 0;
   }*/
   if(hasFailed != 12){
      return 0;
   }
   printf("PASS\n");
   return 0;
}



