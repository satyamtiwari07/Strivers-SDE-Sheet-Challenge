#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    if(root==NULL)
      return {};
    // Write your code here.
    queue<pair<BinaryTreeNode<int> *,int>>q;
    q.push({root, 0});
    
    //idx,value
    map<int,int>mpp;
    // mpp[root->val]=0;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto it= q.front();
            q.pop();
            int idx=it.second;
            int val=it.first->data;

            mpp[idx]=val;
            
            if(it.first->left)
              q.push({it.first->left, idx - 1});
            
            if (it.first->right) 
              q.push({it.first->right,idx+1});
        }
    }
    vector<int>ans;
    // ans.clear();
    for(auto &it:mpp) ans.push_back(it.second);
    return ans;
    
}
