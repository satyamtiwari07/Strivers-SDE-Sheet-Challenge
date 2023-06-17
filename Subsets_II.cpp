#include <bits/stdc++.h> 
void f(int idx,vector<int>&arr,int n,vector<int>&temp,vector<vector<int>>&ans){
    if(idx>=n){
        // if(temp.size()) 
        ans.push_back(temp);
        return ;
    }

    //pick
    temp.push_back(arr[idx]);
    f(idx+1,arr,n,temp,ans);
    temp.pop_back();
    while(idx+1<n and arr[idx]==arr[idx+1]) idx++;

    //not pick
    f(idx+1,arr,n,temp,ans);
        
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<int>temp;
    vector<vector<int>>ans;
    f(0,arr,n,temp,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
