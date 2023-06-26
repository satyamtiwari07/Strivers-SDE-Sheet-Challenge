#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    /**      wt       node,parent
        pair<int,pair<int,int>>
    */

    vector<pair<int,int>>graph[n+1];
    
    for(auto &it:g){
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;
        graph[u].push_back({v, wt});
        graph[v].push_back({u,wt});
    }
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0, {1,-1}});
    
    vector<pair<pair<int, int>,int>>mst;
    vector<bool>vis(n+1,false);

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node])continue;
        vis[node]=true;
        // sum+=wt;
        if(parent!=-1){
          mst.push_back({{node,parent},wt});
        } 
        for(auto i:graph[node]){
          //{u,wt};
          pq.push({i.second,{i.first,node}});
        }
    }

    return mst;

}
