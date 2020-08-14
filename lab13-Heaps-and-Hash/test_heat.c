#include<stdio.h>
#include<stdlib.h>

int main(void){
   HeapType pHeap = NULL;
   int x = 0;
   pHeap = (HeapType)malloc(sizeof(HeapType));
   x = initHeap(&pHeap,10);
   printf("x is %d\n",x);
   return 0;
}
