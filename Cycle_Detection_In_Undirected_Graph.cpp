bool dfs(int node,int par,vector<bool>&vis,vector<int>graph[]){
    vis[node]=true;

    for(auto it:graph[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,graph))return true;
            
        }
        else if(par!=it){
            return true;
        }
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>graph[n+1];
    for(auto it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    vector<bool>vis(n+1,false);
    for (int x = 1; x <= n; x++) {
      if (!vis[x])
        if (dfs(x, -1, vis, graph))
          return "Yes";
    }
    return "No";
}
