#include <bits/stdc++.h> 
bool f(int idx,int sum,int k,vector<int>arr,vector<vector<int>>&dp){
    if(sum>k) return false;

    if(sum==k) return true;

    if(idx>=arr.size()) return false;
    
    if(dp[idx][sum]!=-1) return dp[idx][sum];

    bool pick = f(idx+1,sum+arr[idx],k,arr,dp);
    bool notpick = f(idx+1,sum,k,arr,dp);
    
    return dp[idx][sum] = pick or notpick;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    // return f(0,0,k,arr,dp);
    dp[n][k]=1;
    for(int idx=n-1;idx>=0;idx--){
        for(int sum=k;sum>=0;sum--){
            bool pick=false;
            if(sum+arr[idx]<=k) pick = dp[idx+1][sum+arr[idx]];
            bool notpick = dp[idx+1][sum];
            dp[idx][sum] = pick or notpick;
        }    
    }
    return dp[0][0];
}
