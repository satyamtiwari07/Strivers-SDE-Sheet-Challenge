#include <bits/stdc++.h> 
int f(int x,int y,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(x==n-1 and y==m-1) return grid[x][y];
    if(x>=n || y>=m) return 1e8;
    if(dp[x][y]!=-1) return dp[x][y];
    long long  a = grid[x][y]+f(x+1,y,n,m,grid,dp);
    long long  b = grid[x][y]+f(x,y+1,n,m,grid,dp);
    return dp[x][y]=min(a,b);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(0,0,n,m,grid,dp);
}

//we can also do tabilation and then space optimization is also possible
//so the time complexity boils down to T.C -> O(N*M)  S.C->O(2*N) 
//where n is the number of row and c is the column
