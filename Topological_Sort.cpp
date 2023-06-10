#include <bits/stdc++.h>
void f(int node,vector<int>adj[],vector<bool>&vis,vector<int>&ans){
    // if(vis[node]) return ;
    vis[node]=true;

    for(auto it:adj[node]){
        if(!vis[it]){
            f(it,adj,vis,ans);
        }
    }
    ans.push_back(node);
} 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>ans;
    vector<int>adj[v+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<bool>vis(v+1,false);
    for (int x = 0; x < v; x++) {
      if (!vis[x])
        f(x, adj, vis, ans);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
