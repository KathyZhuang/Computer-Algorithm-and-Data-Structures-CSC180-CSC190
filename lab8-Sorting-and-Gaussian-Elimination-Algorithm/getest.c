#include<stdio.h>
#include<stdlib.h>
#include "ge.c"

int print(float *matrix, int rows, int cols);
int print(float *matrix, int rows, int cols){
   int r=0;
   int c=0;

   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         printf("%8.3f",matrix[r*cols + c]);
      }
      printf("\n");
   }
   return 0;
}


int main(void){
   int rows=0, cols=0;
   float *m=NULL, *n=NULL, *p=NULL; /* init value for ptrs */
   int r=0,c=0;
   float idx=0.0;
   int rval=0;
   int rval2 = 0;

   printf("How many rows? ");
   scanf("%d",&rows);
   printf("How many cols? ");
   scanf("%d",&cols);

   /* dynamically allocate matrices m and n
 *  *       Note: malloc returns NULL if it failed; i.e., if the computer
 *   *             was unable to allocate memory as requested */
   m = (float *)malloc(sizeof(float)*rows*cols);
   if (m==NULL) {
      printf("ERR: failed to allocate m; malloc failed\n");
      return -1;
   }
   n = (float *)malloc(sizeof(float)*rows*cols);
   if (n==NULL) {
      printf("ERR: failed to allocate n; malloc failed\n");
      return -1;
   }
   p = (float *)malloc(sizeof(float)*rows*cols);
   if (p==NULL) {
      printf("ERR: failed to allocate n; malloc failed\n");
      return -1;
   }

   /* construct the matrix with some unimaginative but pretty data */
   idx=0.0;
   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         m[r*cols + c] = idx;
         idx=idx+1;
      }
   }
   rval = ge_fw(m, rows, cols, n);
   print(m,rows,cols);
   print(n,rows,cols);
   if (rval != 0) {
      printf("ERR: ge_fw returned a non-zero status\n");
      return -1;
   }
   rval2 = ge_bw(n, rows, cols, p);
   print(n,rows,cols);
   print(p,rows,cols);
   if (rval2 != 0) {
      printf("ERR: ge_bw returned a non-zero status\n");
      return -1;
   }

   return 0;
}

                    
