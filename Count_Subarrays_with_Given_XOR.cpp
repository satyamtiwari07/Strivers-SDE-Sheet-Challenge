#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    unordered_map<int,int>mpp;
    int cnt=0;
    int xr=0;
    int n = arr.size();
    mpp[0]=1;
    
    for(int x=0;x<n;x++){
        xr = xr ^ arr[x];
        
        int val = xr ^ k;
        
        cnt += mpp[val];
        mpp[xr]++;
    }
    return cnt;
}
