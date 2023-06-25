#include<bits/stdc++.h>

vector<bool>vis;
vector<int>color;

bool dfs(int col,int node,vector<int>graph[]){
	vis[node]=true;
	color[node]=col;
	for(auto it:graph[node]){
		if(!vis[it]){
			if(dfs(1-col,it,graph)==false) return false;
		}
		if(color[it]==col) return false;
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	
	int n=edges.size();
	
	vis.clear();
	color.clear();

	vis.resize(n+1,false);
	color.resize(n+1,-1);

	vector<int>graph[n+1];

	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(edges[x][y]==1){
				graph[x].push_back(y);
				graph[y].push_back(x);
			}
		}
	}
	
    for(int x=0;x<n;x++){
      if (!vis[x]) {
        if (dfs(0,x, graph) == false)
          return false;
      }
    }
	return true;
}
