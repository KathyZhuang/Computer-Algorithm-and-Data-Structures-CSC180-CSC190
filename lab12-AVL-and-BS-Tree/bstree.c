#include <stdio.h>
#include <stdlib.h>
struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;


struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;

int add_bst(bstNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root = (bstNode *)malloc(sizeof(bstNode));
      (*root)->val = val;
   } else {
      if ((*root)->val > val){
         add_bst(&((*root)->l),val);
      }
      else{
         add_bst(&((*root)->r),val);
      }
   }
}

int printTreeInOrder(bstNode *root){
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

int getLength(bstNode *root){
   int lh = 0;
   int rh = 0;
   if (root == NULL){
      return 0;
   }
   lh = getLength(root->l);
   rh = getLength(root->r);
   if (lh > rh){
      return (lh + 1);
   }
   else{
      return (rh + 1);
   }
}

int printLevelOrder(bstNode *root){
   int i = 0;
   int length = 0;
   if (root == NULL){
      return -1;
   }
   length = getLength(root);
   for (i = 0; i < length; i++){
      plo_helper(root,i);
   }
   return 0;
}

int plo_helper(bstNode *root, int level){
   if (root == NULL){
      return -1;
   }
   if (level == 0){
      printf("%d",root->val);
   }
   else{
      plo_helper(root->l, level - 1);
      plo_helper(root->r, level - 1);
   }
}



int main(void) {
   bstNode *root=NULL;
   add_bst(&root,5);
   add_bst(&root,3);
   add_bst(&root,1);
   add_bst(&root,4);
   add_bst(&root,7);
   add_bst(&root,6);
   add_bst(&root,8);
   printTreeInOrder(root);
   printLevelOrder(root);
   return 0;
}




