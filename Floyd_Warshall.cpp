int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<vector<int>>dist(n,vector<int>(n,(int)1e9));
    
    for(int x=0;x<n;x++)dist[x][x]=0;

    for(auto &it:edges){
        int u = it[0]-1;
        int v = it[1]-1;
        int wt = it[2];
        dist[u][v] = wt; 
    }

    for(int via=0;via<n;via++){
        for(int x=0;x<n;x++){
          for (int y = 0; y < n; y++) {
              if(dist[x][via]!=1e9 and dist[via][y]!=1e9)
                dist[x][y] = min(dist[x][y], dist[x][via] + dist[via][y]);
          }
        }
    }
    
    return dist[src-1][dest-1];

}
