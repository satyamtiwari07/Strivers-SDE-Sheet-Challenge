#include <bits/stdc++.h>

struct Node{
	Node* child[2];

	//return true if that bit exists 
	//return false if that bit not exists
	bool contain(int bit){
		return child[bit]!=NULL;
	}

	void put(int bit, Node* node){
		 child[bit] = node;
	}

	Node* get(int bit){
		return child[bit];
	}
};

class Trie{

public:
    Node * root;
	Trie(){
		root = new Node();
	}
   void insert(int num){
	   Node*temp=root;
	   for(int x=31 ; x>=0 ; x--){
		   int bit = (num >> x)&1;
		   if(!temp->contain(bit)){
			   temp->put(bit,new Node());
		   } 
		   temp=temp->get(bit);
	   }
   }

   int getMax(int num){
	   Node*temp = root;
	   int maxi=0;
	   for(int x=31;x>=0;x--){
		   int bit = (num>>x)&1;
		   if(temp->contain(1-bit)){
			    maxi^=(1<<x);
                temp=temp->get(1-bit); 
		   }
		   else temp = temp->get(bit);
	   }
	   return maxi;
   }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.

	sort(arr.begin(),arr.end());
	Trie t;
	// {ai,{xi,idx}}
	vector<pair<int,pair<int,int>>>temp;
	int cnt=0;
	for(auto it:queries){
		int xi=it[0];
		int ai=it[1];
		temp.push_back({ai,{xi,cnt}});
		cnt++;
	}
	int n=temp.size();
	sort(temp.begin(),temp.end());
	vector<int>ans(queries.size(),0);
	int i=0;
	for(auto it:temp){
		int ai = it.first;
		int xi = it.second.first;
		int idx= it.second.second;
		
		while(i<arr.size() and arr[i]<=ai){
			t.insert(arr[i]);
			i++;
		}
		if(i==0) ans[idx]=-1;
		else ans[idx] = t.getMax(xi);
	}

	return ans;
}
