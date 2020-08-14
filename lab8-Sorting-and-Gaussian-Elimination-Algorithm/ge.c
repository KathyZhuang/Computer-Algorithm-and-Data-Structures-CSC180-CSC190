#include<stdio.h>

int ge_bw(float *matrix, int rows, int cols, float *matrix_out){
   if (matrix == NULL || matrix_out == NULL || rows == 0 || cols == 0){
      return -1;
   }
   int q = 0;
   int m = 0;
   int cntc = 0;
   int n = 0;
   int k = 0;
   float d2 = 0.0;
   float d3 = 0.0;
   int r = 0;
   int c = 0;
   int limit = 0;
   int passB = 0;
   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         matrix_out[r*cols + c] = matrix[r*cols + c];
      }
   }
   if (rows <= cols){
      limit = rows;
   }
   else{
      limit = cols;
   }
   for(m=limit-1;m>-1;m=m-1){
      passB = 0;
      cntc = 0;
      while(matrix_out[m*cols + cntc] == 0.0){
         cntc = cntc + 1;
         if(cntc >= cols){
            passB = 1;
            break;
         }
      }
      if(passB == 0){
         d2 = (1.0)/(matrix_out[m*cols + cntc]);
         for(n=cntc;n<cols;n++){
            matrix_out[m*cols + n] = (matrix_out[m*cols + n])*d2;
         }
         for(k=0;k<m;k++){
            d3 = matrix_out[k*cols + cntc];
            for(q=0;q<cols;q++){
               matrix_out[k*cols + q] = matrix_out[k*cols + q] - d3*matrix_out[m*cols + q];
            }
         }
      }
   }
   return 0;
}

int ge_fw(float *matrix, int rows, int cols, float *matrix_out){
   if (matrix == NULL || matrix_out == NULL || rows == 0 || cols == 0){
      return -1;
   }
   int q = 0;
   int r = 0;
   int c = 0;
   int m = 0;
   int n = 0;
   int k = 0;
   int limit = 0;
   int cnt = 0;
   int passA = 0;
   float d1 = 0.0;
   float new = 0.0;
   // assign values in matrix to matrix_out
   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         matrix_out[r*cols + c] = matrix[r*cols + c];
      }
   }
   if (rows <= cols){
      limit = rows;
   }
   else{
      limit = cols;
   }
   for(q=0;q<limit;q++){
      cnt = q;
      passA = 0;
      while (matrix_out[cnt*cols + q] == 0.0){
         cnt = cnt + 1;
         if (cnt >= rows){
            passA = 1;
            break;
         }
      }
      if(passA == 0){
         for(m=0;m<cols;m++){
            new = matrix_out[cnt*cols + m];
            matrix_out[cnt*cols + m] = matrix_out[q*cols + m];
            matrix_out[q*cols + m] = new;
         }
         for(n=q+1;n<rows;n++){
            if(matrix_out[q*cols + q]!=0){
               d1 = matrix_out[n*cols + q]/matrix_out[q*cols + q];
               for(k=0;k<cols;k++){
                  matrix_out[n*cols + k] = matrix_out[n*cols + k] - d1*matrix_out[q*cols + k];
               }
            }
         }
      }
   }
   return 0;
}

                 
