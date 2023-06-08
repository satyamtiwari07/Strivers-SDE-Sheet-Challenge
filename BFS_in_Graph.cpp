#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    
    unordered_map<int,set<int>>graph;
    vector<int>ans;

    for(auto &edge:edges){
        graph[edge.first].insert(edge.second);
        graph[edge.second].insert(edge.first);
    }

    vector<bool>vis(vertex+1,false);
    for(int x=0;x<vertex;x++){
        if(!vis[x]){
            queue<int>q;
            q.push(x);
            // vis[x]=true;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                if(vis[it])continue;
                vis[it]=true;
                ans.push_back(it);
                for(auto node:graph[it]){
                    if(!vis[node]){
                        // vis[node]=true;
                        q.push(node);
                    }
                }
            }
        }
    }

    return ans;

}
