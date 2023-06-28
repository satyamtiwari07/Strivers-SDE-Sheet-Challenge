#include<vector>

long f(int idx, int value, int *denominations, int n, vector<vector<long>>&dp){

    // if(value==0) return 1ll;
    if(idx>=n) return value==0;
    if(dp[idx][value]!=-1) return dp[idx][value];
    long notPick = f(idx+1,value,denominations,n,dp);
    
    long pick=0;
    if(denominations[idx]<=value)
        pick = f(idx,value-denominations[idx],denominations,n,dp);

    return dp[idx][value]=pick+notPick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // vector<vector<long>>dp(n+1,vector<long>(value+1,-1));
    // return f(0,value,denominations,n,dp);
    
    vector<vector<long>>dp(n+1,vector<long>(value+1,0));
    dp[n][0]=1;

    for(int idx=n-1;idx>=0; idx--){
        for(int v=0;v<=value;v++){
    
            long notPick = dp[idx+1][v];
            long pick=0;
            if(denominations[idx]<=v)
                pick = dp[idx][v-denominations[idx]];
           dp[idx][v]=pick+notPick;
        }
    }
    return dp[0][value];
}
