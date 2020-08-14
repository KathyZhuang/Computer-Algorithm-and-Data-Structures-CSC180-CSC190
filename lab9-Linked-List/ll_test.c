#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *rootA = NULL;
   llnode *rootB = NULL;
   int r=0;
   int i=0;
   int va = 3;
   int rt = 4;
   int valueIn = 10229;
   printf("List A\n");
   r=ll_add_to_tail(&rootA,100);
   r=ll_add_to_tail(&rootA,200);
   r=ll_add_to_tail(&rootA,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&rootA,i*100);
   }
   r=ll_print(rootA);
   va = ll_find_by_value(rootA,100);
   printf("find value %d\n",va);
  // rt = ll_insert_in_order(&root,valueIn);
  // printf("valueIn %d\n",valueIn);
  // printf("insert value %d\n",rt);
  // printf("ajusted root:");
  // r=ll_print(root);
  // r=ll_free(root);

   printf("List B\n");
  // root=NULL;
   r=ll_add_to_tail(&rootB,100);
   r=ll_add_to_tail(&rootB,200);
   r=ll_add_to_tail(&rootB,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_head(&rootB,i*100);
   }
   r=ll_print(rootB);
  // rt = ll_insert_in_order(&root,valueIn);
  // printf("inserit B value %d\n",rt);
  // printf("ajusted root:");
   printf("merged lists \n");
   rt = ll_concat(&rootA,&rootB);
   r=ll_print(rootA);
   int rm = 123;
   rm = ll_sort(&rootA);
   printf("changed!!! %d\n",rm);
   r = ll_print(rootA);
//   r=ll_free(root);
   return 0;
}
