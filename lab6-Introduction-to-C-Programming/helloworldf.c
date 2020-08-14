#include <stdio.h> //this is needed to provide access to the standard IO
                   // (or input/output) library for printf, or scanf
float myAbs(float m);
float bsqrt(float x, float y); // you should always do this, it allows the main to look for squareInt func at the bottom when it's running
float main(void) {
   int i;
   for(i=0;i<10;i++){
      float sqrt;
      sqrt = bsqrt((float)i,0.001);
      printf("The sqrt of  %d is %f\n",i,sqrt);
     }
   return 0;
}
float myAbs(float m){
   float  myM = m;
   if (myM < 0){
      return -myM;
   }
   else{
      return myM;
   }
}
float bsqrt(float x, float y) {
   float e;
   e = x / 2;
   while (myAbs(x - e*e) > y){
      e = (e + x/e)/2;
   }
   return e;
}
