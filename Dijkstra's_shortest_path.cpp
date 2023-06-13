#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>>adj[vertices+1];

    for(auto &it:vec){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    //{dist,node} 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;

    while(!pq.empty()){
        auto i = pq.top();
        int node = i.second;
        int w = i.first;
        pq.pop();

        for(auto it:adj[node]){
            if(dist[it.first]>w+it.second){
                dist[it.first]=w+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    
    return dist;
}
