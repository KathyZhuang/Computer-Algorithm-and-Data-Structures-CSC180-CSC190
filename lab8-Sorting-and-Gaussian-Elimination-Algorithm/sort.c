
#include<stdio.h>

int bubbleSort(int *array, int size){
   if (array == NULL || size == 0){
      return -1;
   }
   int m = 0;
   int newele = 0;
   int i = 0;
   int swapped = 0;
   while (swapped == 0){
      for (i=1;i<size;i++){
         if (array[i-1]>array[i]){
            newele = array[i-1];
            array[i-1] = array[i];
            array[i] = newele;
         }
      }
      int allswp = 1;
      for (m=1;m<size;m++){
         if (array[m-1] > array[m]){
            allswp = 0;
         }
      }
      if (allswp == 1){
         break;
      }
   }
   int j = 0;
   for (j=0;j<size;j++){
      printf("%d",array[j]);
   }
   return 0;
}

