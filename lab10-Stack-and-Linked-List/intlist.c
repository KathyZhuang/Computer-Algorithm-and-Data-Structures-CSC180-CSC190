#include <stdio.h>
#include <stdlib.h>

struct intlist {
   int *x;
   int end;
   int len;
   int value;
   struct intlist *next; // this element is added to make the linked list perform better
};
typedef struct intlist intlist;

int init(intlist *l,int len) {
   if (l==NULL) {
   return -1;
   }
   (l->x) = (int *)malloc(len * sizeof(int));
   if ((l->x) == NULL) { return -1; }
   l->end = -1;
   l->len=len;
   return 0;
}
int add_to_end(intlist *ls, int val){

  intlist *n = NULL;
  if (ls->next == NULL){
    n = (intlist *)malloc(sizeof(intlist));
    n->value=val;
    n->next=NULL;
    ls->next=n;
    return 0;
  }
  else {
     return add_to_end(ls->next,val);

  }

}



int add_to_start(intlist *ls,int val){

  intlist *p=NULL;

  p=(intlist *)malloc(sizeof(intlist));

  p->value=val;

  p->next=ls;

  ls=p;

  return 0;

}

int insert_after(intlist *ls, int inval, int val){

  intlist *q=NULL;

  if (inval>0&&ls->next!=NULL){

    return -1;

  }

  else {

    if (inval == 0){

      q = (intlist *)malloc(sizeof(intlist));

      q->value = val;

      if (ls->next == NULL){

        q->next=NULL;

        ls->next=q;

      }

      else{

        q->next=ls->next;

        ls->next=q;

      }

    }

    else{

      return insert_after(ls->next,inval-1,val);

    }

  }

}



int main(void){
   return 0;
}

