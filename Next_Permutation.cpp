#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
   int x,y;
   //first finding first decreasing element from the last
   for(x=n-2;x>=0;x--){
       if(permutation[x]<permutation[x+1]) break;
   }

   //then finding the first elemt which is greater then arr[x]
   if(x>=0){
    for(y=n-1;y>=0;y--){
        if(permutation[y]>permutation[x]) break;
    }
    // swap element of arr[x] with arr[y]
    swap(permutation[x],permutation[y]);
   }

   // reverse elements from index x+1 to n
   reverse(permutation.begin()+x+1,permutation.end());
   return permutation;
}
