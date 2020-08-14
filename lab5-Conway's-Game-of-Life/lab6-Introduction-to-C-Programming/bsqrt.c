#include<stdio.h>
float myAbs(float m);
float bsqrt(float x, float tol);

float myAbs(float m){
   float  myM = m;
      if (myM < 0){
        return -myM;
      }
      else{
     return myM;
     }
}

float bsqrt(float x, float tol) {
   float sqrt_x;
   sqrt_x = x / 2;
   while (myAbs(x - sqrt_x*sqrt_x) > tol){
      sqrt_x = (sqrt_x + x/sqrt_x)/2;
   }
   return sqrt_x;
}
