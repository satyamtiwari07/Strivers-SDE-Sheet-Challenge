#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   //-3 -2 2 3 3 
   sort(arr.begin(),arr.end());
   vector<vector<int>>ans;
   int n=arr.size();
   for(int x=0;x<n-1;x++){
      int rem = s-arr[x];
      auto it = lower_bound(arr.begin()+x+1,arr.end(),rem);
      if(it==arr.end()) continue;
      while (arr[x] + *it == s) {
         ans.push_back({min(arr[x],*it),max(arr[x],*it)});
         it++;
      }
   }
   return ans;
}
