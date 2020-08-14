#include<stdio.h>

int anlboard(char *T, int sizeT){
   if (sizeT != 9){
      return -1;
   }
   int i;
   for (i=0;i<sizeT;i++){
      if (T[i]!='X' && T[i]!= 'O'){
         return -1;
      }
   }
   if (T[0] == T[1] && T[0]== T[2] && T[0]!= '-'){
      if (T[0]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[3] == T[4]&& T[3] == T[5] && T[3]!=  '-'){
      if (T[3]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[6] == T[7]&& T[6] == T[8] && T[6]!=  '-'){
      if (T[6]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[0] == T[3]&& T[0]== T[6] && T[0]!=  '-'){
      if (T[0]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[1] == T[4] && T[1]== T[7] && T[1]!=  '-'){
      if (T[1]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[2] == T[5] && T[2]== T[8] &&T[2]!=  '-'){
      if (T[2]=='X'){
         return 1;
      }
      else{
         return 2;
      }
      else{
         return 2;
      }
   }
   if (T[0] == T[4] && T[0]== T[8] && T[0]!=  '-'){
     if (T[0]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   if (T[2] == T[4] && T[2]== T[6] && T[2]!=  '-'){
      if (T[2]=='X'){
         return 1;
      }
      else{
         return 2;
      }
   }
   int allOccu = 1;
   int j;
   for (j=0;j<sizeT;j++){
      if (T[j] == '-'){
         allOccu = 0;
      }
   }
   if (allOccu == 1){
      return 3;
   }
   return 0;
}

