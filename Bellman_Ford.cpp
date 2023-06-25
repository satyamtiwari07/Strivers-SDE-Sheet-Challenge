#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
    
    for(int x=1;x<=n-1;x++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
              dist[v]=dist[u]+wt;
        }
    }
    return dist[dest]==INT_MAX ? 1000000000 : dist[dest];
}
