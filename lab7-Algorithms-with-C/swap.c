#include <stdio.h>

int swap(int *a, int *b){
   int m =  *a;
   int n =  *b;
   *a = n;
   *b = m;
   return 1;
}
