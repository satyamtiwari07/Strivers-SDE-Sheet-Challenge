#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    unordered_map<int,int>mpp;
    int l=0;
    int r=0;
    int n=arr.size();
    vector<int>ans;
    while(r<n){
        mpp[arr[r]]++;
        if (r - l + 1 < k) {
          r++;
          continue;
        } else {
          ans.push_back(mpp.size());
          mpp[arr[l]]--;
          if (mpp[arr[l]] == 0)
            mpp.erase(arr[l]);
          l++;
          r++;
        }
    }

    return ans;

}
