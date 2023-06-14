bool dfs(int node,vector<int>adj[],vector<bool>&dfsvis,vector<bool>&vis){
  vis[node]=true;
  dfsvis[node]=true;

  for(auto it:adj[node]){
    if(!vis[it]){
       if(dfs(it,adj,dfsvis,vis)) return true;
    }
    else if(dfsvis[it]) return true;
  }
  dfsvis[node]=false;
  return false;
} 


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<bool>vis(n+1,false);
  vector<bool>dfsvis(n+1,false);
  
  vector<int>adj[n+1];
  for(auto it:edges)
    adj[it.first].push_back(it.second);
  
  for(int x=1;x<=n;x++){
    if (!vis[x]) {
      if (dfs(x, adj, dfsvis, vis))
        return true;
    }
  }

  return false;

}
