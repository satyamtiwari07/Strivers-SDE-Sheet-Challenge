#include<bits/stdc++.h>

int f(int i,int j, string str1, string str2, vector<vector<int>>&dp){
    if(i==str1.length()) return str2.length()-j;
    if(j==str2.length()) return str1.length()-i; 
    
    if(dp[i][j]!=-1) return dp[i][j];

    if(str1[i]==str2[j]) return dp[i][j]=f(i+1,j+1,str1,str2,dp);

    int insertA = 1 + f(i,j+1,str1,str2,dp);
    int deleteA = 1 + f(i+1,j,str1,str2,dp);
    int replaceA = 1 + f(i+1,j+1,str1,str2,dp);

    return dp[i][j]=min({insertA,deleteA,replaceA});
}

int editDistance(string str1, string str2)
{
    //write you code here
    // vector<vector<int>>dp(str1.length()+1,vector<int>(str2.length()+1,-1));
    // return f(0,0,str1,str2,dp);
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[n][j] = m-j;
    for(int i=0;i<=n;i++) dp[i][m] = n-i;

    for(int i=n-1;i>=0;i--){

        for(int j=m-1;j>=0;j--){

            if(str1[i]==str2[j]) dp[i][j]=dp[i+1][j+1];
            else{
                int insertA = 1 + dp[i][j+1];
                int deleteA = 1 + dp[i+1][j];
                int replaceA = 1 + dp[i+1][j+1];

                dp[i][j] = min({ insertA, deleteA, replaceA});
            }
        }
    }
    
    return dp[0][0];
}
