#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode*node, graphNode*copy, map<graphNode*,graphNode*>&mpp){

	mpp[node]=copy;

	for(auto it:node->neighbours){
		if(mpp.count(it)==0){
			//means this node is not made
			graphNode*temp = new graphNode(it->data);
			
			copy->neighbours.push_back(temp);
			dfs(it,temp,mpp);
		}
		else{
			copy->neighbours.push_back(mpp[it]);
		}
	} 
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
		//NewNode,OldNode
	map<graphNode*,graphNode*>mpp;
	graphNode* copy = new graphNode(node->data);
	dfs(node,copy,mpp);
	return copy;
}
