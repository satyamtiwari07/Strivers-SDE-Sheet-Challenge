#include <bits/stdc++.h>

bool valid(string &str,int i,int j){

    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int f(int idx,string&str, vector<int>&dp){
    
    if(idx>=str.length()) return 0; 
    
    if(dp[idx]!=-1) return dp[idx];

    int ans = INT_MAX;

    for(int x=idx ; x<str.length() ; x++){
        if(valid(str,idx,x)){
            ans=min(ans,1+f(x+1,str,dp));
        }
    }
    return dp[idx]=ans;

}
int palindromePartitioning(string str) {
    // Write your code here
    vector<int>dp(str.length()+1,-1);
    return f(0,str,dp)-1;
    // return ans;
}
