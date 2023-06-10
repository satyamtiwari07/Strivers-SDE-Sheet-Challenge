#include <bits/stdc++.h> 
void dfs(int r,int c, vector<vector<int>>&maze, vector<int>&temp,vector<vector<int>>&ans,int n){
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0) return;

    temp[n*r+c]=1; 
    if(r==n-1 and c==n-1 ){
      //one possible answer exists
      ans.push_back(temp);
      return;
    }
    
    maze[r][c]=0;
    dfs(r+1,c,maze,temp,ans,n);
    dfs(r-1,c,maze,temp,ans,n);
    dfs(r,c+1,maze,temp,ans,n);
    dfs(r,c-1,maze,temp,ans,n);
    temp[n*r+c]=0;
    maze[r][c]=1;
    
  }
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<int>temp(n*n,0);
  vector<vector<int>>ans;
  dfs(0,0,maze,temp,ans,n);
  return ans;
}
