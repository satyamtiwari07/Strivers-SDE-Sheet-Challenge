#include <bits/stdc++.h> 

void f(int idx,vector<int>&v,vector<int>&temp,vector<vector<int>>&ans){
    if(idx==v.size()){
        ans.push_back(temp);
        return;
    }

    //2 choices pick and not-pick
    
    //1>.not pick
    f(idx+1,v,temp,ans);
    
    //2>.pick
    temp.push_back(v[idx]);
    f(idx+1,v,temp,ans);

    //(backtracking) remove picked element
    temp.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    vector<int>temp;
    f(0,v,temp,ans);
    return ans;
}

//this problem also solved using bit-masking creating mask of n(size of array)
