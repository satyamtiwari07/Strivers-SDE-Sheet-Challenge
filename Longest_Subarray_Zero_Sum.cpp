#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int,int>mpp;
  mpp[0]=-1;
  long long sum=0;
  int maxi=0;
  int n=arr.size();
  for(int x=0;x<n;x++){
    sum+=arr[x];
    if(mpp.count(sum)==0) mpp[sum]=x;
    else maxi=max(maxi,x-mpp[sum]);
  }
  return maxi;

}
