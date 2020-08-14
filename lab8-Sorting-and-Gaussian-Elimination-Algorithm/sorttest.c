#include<stdio.h>
#include "sort.c"

int main(void){
   int x = 0;
   int idx = 20;
   int array[20];
   for(x=0;x<20;x++){
      array[x] = idx;
      idx = idx - 1;
   }
   bubbleSort(array,20);
   return 0;
}
