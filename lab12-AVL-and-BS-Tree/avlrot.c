#include <stdio.h>
#include <stdlib.h>
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

int getLength(avlNode *root){
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

int isAVL(avlNode **root){
   int l = getLength((*root)->l);
   int r = getLength((*root)->r);
   if (root == NULL){
      return -1;
   }
   if (l == r){
      (*root)->balance = 0;
      return 0;
   }
   else if ((l-r)==-1){
      (*root)->balance = -1;
      return -1;
   }
   else if ((r-l)==1){
      (*root)->balance = 1;
      return -1;
   }
   else{
      return -1;
   }
}

int rotate(avlNode **root, unsigned int Left0_Right){
   avlNode * temp = NULL;
   if (root == NULL){
      return -1;
   }
   if (Left0_Right == 0){
   /*left rotation*/
   temp = (*root)->r;
   (*root)->r = temp->l;
   temp->l = (*root);
   (*root) = temp;
   }
   else if (Left0_Right == 1){
   /*right rotation*/
   temp = (*root)->l;
   (*root)->l = temp->r;
   temp->r = (*root);
   (*root) = temp;
   }
   return 0;
}

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1){
   int x = 0;
   if (root == NULL){
      return -1;
   }
   if (MajLMinR0_MajRMinL1 == 1){
      x = rotate(&((*root)->l),1);
      x = rotate(root,0);
   }
   else if (MajLMinR0_MajRMinL1 == 0){
      x = rotate(&((*root)->r),0);
      x = rotate(root,1);
   }
   return 0;
}

int add_bst(avlNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root = (avlNode *)malloc(sizeof(avlNode));
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


