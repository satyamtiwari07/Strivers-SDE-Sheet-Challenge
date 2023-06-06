#include <bits/stdc++.h> 

int f(int x,int y,int m ,int n,vector<vector<int>>&dp){
	if(x==m-1 && y==n-1) return 1;
	if(x>=m || y>=n || x<0 || y<0) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	int a = f(x+1,y,m,n,dp);
	int b = f(x,y+1,m,n,dp);
	return dp[x][y] = a+b; 
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	return f(0,0,m,n,dp);
}

/**

we can also optimize this solution using (tabulation)
and again we can optimize the solution using prev and current row taking optimization(space optimization) 
time complexity remains same

*/
