void dfs(int node,vector<int>graph[],vector<bool>&vis,vector<int>&temp){
    vis[node]=true;
    temp.push_back(node);
    for(auto it:graph[node]){
        if(!vis[it]){
            dfs(it,graph,vis,temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>graph[V+1];
    for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    vector<bool>vis(V+1,false);
    vector<vector<int>>ans;
    for(int x=0;x<V;x++){
        if(!vis[x]){
            vector<int>temp;
            dfs(x,graph,vis,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
