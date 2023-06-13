#include<bits/stdc++.h>

vector<pair<int, int>> dirs ={{-1, 0}, {0, 1}, {0, -1}, {1, 0}, {-1,1}, {-1,-1}, {1,1}, {1,-1}};

void dfs(int x,int y, int n, int m, int **arr){

   if(x<0 || y<0 || x>=n || y>=m || arr[x][y]==0 ||arr[x][y]==-1) return ;

   // vis[x][y]=true;
   arr[x][y]=-1;

   for(auto &dir:dirs){
      dfs(x+dir.first,y+dir.second,n,m,arr);
   }

}

int getTotalIslands(int **arr, int n, int m) {
  // Write your code here.
//   vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
  int cnt=0;
  
  for (int x = 0; x < n; x++) {
     for(int y=0;y<m;y++){
       if (arr[x][y] == 1) {
         dfs(x, y, n, m, arr);
         cnt++;
       }
     }
  }
  return cnt;
}
