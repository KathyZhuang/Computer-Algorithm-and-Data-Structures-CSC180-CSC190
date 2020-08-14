#include<stdio.h>
#include<stdlib.h>

struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;


int printTreeInOrder(avlNode *root){
   if (root == NULL){
      return -1;
   }
   if (root->l != NULL){
      printTreeInOrder(root->l);
   }
   printf("%d\n",(root->val));
   if (root->r != NULL){
      printTreeInOrder(root->r);
   }
}

int main(void){
   avlNode *root=malloc(sizeof(avlNode));
   root->val=11;
   add_bst(&root,5);
   add_bst(&root,7);
   add_bst(&root,3);
   add_bst(&root,78);
   add_bst(&root,4);
   add_bst(&root,67);
   add_bst(&root,9);
   printTreeInOrder(root);
   dblrotate(&root,1);
   return 0;
}
