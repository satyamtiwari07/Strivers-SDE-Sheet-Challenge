#include <bits/stdc++.h> 

class dsu{
   vector<int>parent;
   vector<int>size;
   public:
    dsu(){
     parent.resize(1e4+1);
	 size.resize(1e4,1);
	 for(int x=0;x<1e4+1;x++) parent[x]=x;
   }

   int findparent(int node){
	   if(parent[node]==node) return node;
	   return parent[node]=findparent(parent[node]);
   }
   
   void connect(int node1,int node2){
	   int a=findparent(node1);
	   int b=findparent(node2);
	   if(a==b) return ;
	   else{
		   if(size[a]>size[b]){
			   parent[b]=a;
			   size[a]+=size[b];
		   }
		   else{
			   parent[a]=b;
			   size[b]+=size[a];
		   }
	   }
   }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	dsu d;
	vector<pair<int,pair<int,int>>>adj;
	for(auto it:graph){
          adj.push_back({it[2],{it[0],it[1]}});
    }
	sort(adj.begin(),adj.end());
	int sum=0;
	for(int x=0;x<m;x++){
		int a = adj[x].second.first;
		int b = adj[x].second.second;
		if(d.findparent(a)!=d.findparent(b)){
			sum+=adj[x].first;
			d.connect(a,b);
		}
	}
	return sum;

}
