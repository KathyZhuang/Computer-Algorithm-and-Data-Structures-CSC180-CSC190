#include<stdio.h>
#include<stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap(HeapType *pHeap, int size);
int inorder(HeapType *pHeap, int **output, int *o_size);
int preorder(HeapType *pHeap, int **output, int *o_size);
int postorder(HeapType *pHeap, int **output, int *o_size);

void inorderHelper(int *heapArray, int root, int **op, int end);
void preorderHelper(int *heapArray, int root, int **op, int end);
void postorderHelper(int *heapArray, int root, int **op, int end);

int addHeap(HeapType *pHeap, int key);
int findHeap(HeapType *pHeap, int key);
int delHeap(HeapType *pHeap, int *key);

int reheapUp(HeapType *pHeap, int r);
int reheapDown(HeapType *pHeap, int r);


int initHeap(HeapType *pHeap, int size){
   if (pHeap == NULL || size <= 0){
      return -1;
   }
   pHeap->store = malloc(size*sizeof(int));
   pHeap->end = 0;
   pHeap->size = size;
   if ((pHeap->store) == NULL){
      return -1;
   }
   else{
      return 0;
   }
}

int inorder(HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL || output == NULL){
      return -1;
   }
   (*o_size) = pHeap->end + 1;
   (*output) = (int *)malloc((*o_size)*sizeof(int));
   inorderHelper(pHeap->store,0,output,*o_size);
   return 0;
}

void inorderHelper(int *heapArray, int root, int **op, int end){
   int i = 0;
   if (root*2+1 < end){
      inorderHelper(heapArray,root*2+1,op,end);
   }
   for (i=0;i<end;i++){
      if((*op)[i]==0){
         (*op)[i] = heapArray[root];
         break;
      }
   }
   if (root*2+2 < end){
      inorderHelper(heapArray,root*2+2,op,end);
   }
}

int preorder(HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL || output == NULL){
      return -1;
   }
   (*o_size) = pHeap->end + 1;
   (*output) = (int *)malloc((*o_size)*sizeof(int));
   preorderHelper(pHeap->store,0,output,*o_size);
   return 0;
}


void preorderHelper(int *heapArray, int root, int **op, int end){
   int i = 0;
   for (i=0;i<end;i++){
      if((*op)[i]==0){
         (*op)[i] = heapArray[root];
         break;
      }
   }
   if (root*2+1 < end){
      inorderHelper(heapArray,root*2+1,op,end);
   }
   if (root*2+2 < end){
      inorderHelper(heapArray,root*2+2,op,end);
   }
}

int postorder(HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL || output == NULL){
      return -1;
   }
   (*o_size) = pHeap->end + 1;
   (*output) = (int *)malloc((*o_size)*sizeof(int));
   postorderHelper(pHeap->store,0,output,*o_size);
   return 0;
}

void postorderHelper(int *heapArray, int root, int **op, int end){
   int i = 0;
   if (root*2+1 < end){
      inorderHelper(heapArray,root*2+1,op,end);
   }
   if (root*2+2 < end){
      inorderHelper(heapArray,root*2+2,op,end);
   }
   for (i=0;i<end;i++){
      if((*op)[i]==0){
         (*op)[i] = heapArray[root];
         break;
      }
   }

}

int addHeap(HeapType *pHeap, int key){
   if ((pHeap->end)+1 >= pHeap->size){
      return -1;
   }
   (pHeap->store)[pHeap->end + 1] = key;
   pHeap->end = pHeap->end + 1;
   reheapUp(pHeap,pHeap->end);
   return 0;
}

int reheapUp(HeapType *pHeap, int r){
   int parent = 0;
   int temp = 0;
   if (r == 0){
      return 0;
   }
   parent = (r-1)/2;
   if ((pHeap->store)[parent] < (pHeap->store)[r]){
      temp = (pHeap->store)[parent];
      (pHeap->store)[parent] = (pHeap->store)[r];
      (pHeap->store)[r] = temp;
      reheapUp(pHeap,parent);
   }
   else{
      return 0;
   }
}

int findHeap(HeapType *pHeap, int key){
   int i = 0;
   if (pHeap == NULL){
      return -1;
   }
   for (i=0;i<(pHeap->end+1);i++){
      if ((pHeap->store)[i] == key){
         return 1;
      }
   }
   return 0;
}


int delHeap(HeapType *pHeap, int *key){
   int x = 0;
   if (pHeap == NULL || pHeap->size == 0){
      return -1;
   }
   (*key) = (pHeap->store)[0];
   x = (pHeap->store)[pHeap->end];
   (pHeap->store)[0] = x;
   pHeap->end = pHeap->end - 1;
   reheapDown(pHeap,0);
   return 0;
}

int reheapDown(HeapType *pHeap, int r){
   int cl = 0;
   int cr = 0;
   int max = 0;
   int temp = 0;
   cl = r*2+1;
   cr = r*2+2;
   if (cl >= pHeap->size || cr >= pHeap->size){
      return 0;
   }
   if ((pHeap->store)[cl]==0 && (pHeap->store)[cr]==0){
      return 0;
   }
   else if((pHeap->store)[cr]==0){
      if ((pHeap->store)[cl] > (pHeap->store)[r]){
         temp = (pHeap->store)[cl];
         (pHeap->store)[cl] = (pHeap->store)[r];
         (pHeap->store)[r] = temp;
         reheapDown(pHeap,cl);
      }
      else{
         return 0;
      }
   }
   else{
      if((pHeap->store)[cl] > (pHeap->store)[cr]){
         max = (pHeap->store)[cl];
      }
      else{
         max = (pHeap->store)[cr];
      }
      temp = (pHeap->store)[max];
      (pHeap->store)[max] = (pHeap->store)[r];
      (pHeap->store)[r] = temp;
      reheapDown(pHeap,max);
   }
}

