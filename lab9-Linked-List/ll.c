#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 *  * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 *   * to that function.
 *    *
 *     * Recap: if we want to use a function to modify a VARIABLE in the caller
 *      *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *       *
 *        * Similarly: if we want to use a function to modify a POINTER in the caller
 *         *            then the CALLER needs to send in the ADDRESS of the POINTER
 *          *
 *           * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 *            * nodes to be added to the linked list. Any dynamic creation of a node must be via
 *             * malloc.
 *              */

int ll_find_by_value(llnode *pList,int val){
//This searches the list (pointed at by pList) for a node with
//value "val"; returning success/failure based on your search.
  llnode *c = NULL;
   if(pList == NULL){
      return -1; // return false
   }
   c = pList; //let c and pLIst point at the same memory space
   while(c != NULL){
      if((*c).val == val){
         return 0;
      }
      else{
         c = c->next;
      }
   }
   return -1;
}
int ll_del_from_tail(llnode **ppList){
// This finds the tail node, if it exists, and removes it from the list,adjusting the list. Remember to "free" any dynamic structures that are deleted.
   if(ppList == NULL){
      return -1;
   }
   llnode *t_list;
   t_list = *ppList;
   while((t_list->next)->next != NULL){
      t_list = t_list->next;
   }
   printf("t_list value is %d\n",t_list->val);
   ll_free(t_list->next);
   t_list->next = NULL;
   return 0;
}

int ll_del_from_head(llnode **ppList){
   if(ppList == NULL){
      return -1;
   }
   *ppList = (*ppList)->next;
   return 0;
}
//This finds the head node, if it exists, and removes it from the list, adjusting the list. Remember to "free" any dynamic structures that are deleted.
int ll_del_by_value(llnode **ppList,int val){
//Search for the node with value "val" and if it exists, remove it
   if(ppList == NULL){
      return -1; // return false
   }
   llnode *c = NULL;
   c = *ppList; //let c and pLIst point at the same memory space
   while(c != NULL){
      if((c->next)->val == val){
         c->next = (c->next)->next;
         return 0;
      }
      else{
         c = c->next;
      }
   }
   return -1;
}

int ll_insert_in_order(llnode **ppList,int val){
   if(ppList == NULL){
      return -1;
   }
   llnode *d = NULL;
   llnode *e = NULL;
   llnode *h = *ppList;
   llnode *c = *ppList;
   while(c != NULL){
      if((c->val <= val)&&((c->next)->val >= val)){
         d = c->next;
         e = (llnode *)malloc(sizeof(llnode));
         e->val = val;
         c->next = e;
         e->next = d;
         return 0;
      }
      if(((c->next)->next) == NULL){
         if((c->val) <= val){
            e = (llnode *)malloc(sizeof(llnode));
            e->val = val;
            (c->next)->next = e;
            e->next = NULL;
            return 0;
         }
         else{
             e = (llnode *)malloc(sizeof(llnode));
             e->val = val;
             e->next = h;
             *ppList = e;
             return 0;
         }
      }
      else{
         c = c->next;
      }
   }
   return -1;
}

int ll_concat(llnode **pSrcA,llnode **pSrcB){
//This will merge SrcA and SrcB so that SrcA consists of SrcA and SrcB concatenated: in Python-speak "SrcA = SrcA + SrcB"
   if(pSrcA == NULL || pSrcB == NULL){
      return -1;
   }
   llnode *l_node = *pSrcA;
   llnode *f_node = *pSrcB;
   while((l_node->next) != NULL){
      l_node = l_node->next;
   }
   l_node->next = f_node;
   return 0;
}

int ll_sort(llnode **ppList){
//This will run BUBBLE SORT (whose algorithm you saw in the last lab)on the list pointed at by ppList.
   if(ppList == NULL){
      return -1;
   }
   llnode *array = *ppList;
   int newele = 0;
   int allswp = 1;
   while(allswp == 1){
      array = *ppList;
      allswp = 0;
      while((array->next)!= NULL){
         if(array->val >= array->next->val){
            newele = array->val;
            array->val = array->next->val;
            array->next->val= newele;
            allswp = 1;
         }
         array = array->next;
      }
   }
   return 0;
}

int ll_add_to_head( llnode **head, int val) {
   llnode *old_head;
   if (head == NULL) {
      return -1;
   }
   old_head = *head;
   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
   (*head) -> next = old_head;
   return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
                                        which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}


