#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,int>>q;
    int one=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(grid[x][y]==2){
              q.push({x,y});
            }
            else if(grid[x][y]==1) one++;
        }
    }
    if(q.empty()) return 0;

    int cnt=0;
    vector<pair<int, int>> dirs = { {-1,0} , {0,-1} , {1,0} , {0,1} };
    
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        auto it = q.front();
        q.pop();
        // grid[it.first][it.second] = -1;

        for (auto dir : dirs) {
          int x = it.first + dir.first;
          int y = it.second + dir.second;

          if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1) {
            one--;
            q.push({x, y});
            grid[x][y] = 2;
          }
        }
      }
      cnt++;
    }
    
    if(one==0) return cnt-1;
    return -1;

}
