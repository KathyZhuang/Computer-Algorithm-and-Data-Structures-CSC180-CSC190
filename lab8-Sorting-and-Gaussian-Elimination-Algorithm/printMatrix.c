#include<stdio.h>


int main(void){
   int row = 2;
   int col = 4;
   float myarray[row][col];
   int m = 0;
   int n = 0;
   float idx = 0.0;
   for (m=0;m<row;m++){
      for(n=0;n<col;n++){
         myarray[m][n] = idx;
         idx = idx + 0.1;
      }
   }
   printMatrix(myarray,row,col);
   return 0;
}

int printMatrix(float *tdarray, int row, int col ){
   if (tdarray == NULL){
      return 0;
   }
   int i = 0;
   int j = 0;
   for (i=0;i<row;i++){
      for (j=0;j<col;j++){
        printf("%8.3f",tdarray[i][j]);
      }
      printf("\n");
   }
return 1;
}
