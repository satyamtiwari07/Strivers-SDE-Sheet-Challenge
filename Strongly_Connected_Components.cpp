void topo(int node,vector<int>adj[],vector<bool>& vis,vector<int>& st){
    vis[node]=true;

    for(auto it:adj[node]){
        if(!vis[it])
          topo(it,adj,vis,st);
    }

    st.push_back(node);
}

void dfs(int node,vector<int>adj[],vector<bool>& vis, vector<int>&temp){
    vis[node]=true;

    for(auto it:adj[node])
    if(!vis[it]) dfs(it,adj,vis,temp);

    temp.push_back(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto &it:edges) adj[it[0]].push_back(it[1]);
    
    vector<bool> vis(n+1,false);
    vector<int>st;
    vector<vector<int>>ans;

    //1>.topological sorting
    for(int x=0;x<n;x++) if(!vis[x]) topo(x,adj,vis,st);

    //2>.revere the edge of the graph
    for(auto &it:adj) it.clear();
    for(auto &it:edges) adj[it[1]].push_back(it[0]);
    vis = vector<bool>(n+1,false);

    //3>.start dfs from the topological stack
    for(int x=st.size()-1 ;x>=0 ;x--)
      if (!vis[st[x]]) {
          vector<int>temp;
        dfs(st[x], adj, vis,temp);
        ans.push_back(temp);
      }

    return ans;
}
