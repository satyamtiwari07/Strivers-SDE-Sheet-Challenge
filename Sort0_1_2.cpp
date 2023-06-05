#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int zero=0,one=0,two=0;
   for(int x=0;x<n;x++){
      if(arr[x]==0) zero++;
      else if(arr[x]==1) one++;
      else two++;
   }

   int x=0;
   while(zero || one || two){
     if (zero) {
       arr[x++] = 0;
       zero--;
     } else if (one) {
       arr[x++] = 1;
       one--;
     } else {
       arr[x++] = 2;
       two--;
     }
   }
}
