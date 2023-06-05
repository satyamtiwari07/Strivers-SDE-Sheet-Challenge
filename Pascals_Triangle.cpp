#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.

  vector<long long int >prev;
  vector<vector<long long int>>ans;

  for(int x=1;x<=n;x++){
    vector<long long int>temp(x,1);
    if(x==1 || x==2) ans.push_back(temp);
    else{
      for(int x=1;x<prev.size();x++){
         temp[x]=prev[x]+prev[x-1];
      }
      ans.push_back(temp);
    }
    prev=temp;
  }
  return ans;
}
