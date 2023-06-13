#include <bits/stdc++.h>


bool f(int idx,int n,string &target,unordered_map<string,bool>&mpp){

    if(idx>=n) return true;

    string rem=target.substr(idx);
    
    if(mpp[rem]) return true;
    
    string temp="";
    
    for(int x=idx;x<n;x++){
        temp+=target[x];
        if(mpp[temp]){
            return f(x+1,n,target,mpp);
        }
    }
    return false;
    
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    unordered_map<string,bool>mpp;
    for(auto &it:arr) mpp[it]=1;

    return f(0,target.length(),target,mpp);
    
}
